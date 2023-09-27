#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_EDU_Demo/game/a1j_whole/ck_scenarios.py
"""
Základní čtveřice scénářů pro hru inspirovanou
pohádkou o Červené Karkulce.
Kroky jsou doplněny o podmínky k jejich úspěšnému provedení.
Vystupující texty jsou uloženy do proměnných.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

from game.api.scenario   import ScenarioStep, Scenario
from game.api.scen_types import *  # Především typu kroků



###########################################################################q
ScenarioStep.next_index = 0   # Index prvního kroku za startem

SUBJECT = (
    'Toto je příběh o Honzikovi, který chce koupit potraviny.\n'
    'Svými příkazy řídíte Honzika, aby koupil všechno co nemá doma\n'
    'ani v kuchyně, ani ve skladu.\n'
    'Když přijde do Alberta , měl by vzít potraviny,\n'
    'zaplatit na kase, vzít věcí a odnest je do kuchýně.\n'
    'Nezapomente přinest potraviny i ze skladu do kuchyně \n'
    'a ukazat mamince všechno, co máte v tašce.\n'
    'Jestli maminka říká, že máte všechno, hra se končí.\n\n'
    'Nebudete-li si vědět rady, zadejte znak ?, jenž zobrazí nápovědu.'
    )
# Základní úspěšný scénář demonstrující průběh hry, při němž hráč
# nezadává žádné chybné příkazy a dosáhne zadaného cíle.
HAPPY = Scenario(stHAPPY, (
    START_STEP :=
    ScenarioStep(tsSTART, '',                
        WELCOME := 'Vítejte!\n' + SUBJECT,
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),   
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ), 
        (),                         
        # Počáteční stavy stavových proměnných
        sets = {'conditions': ['argument_payable',
                               'argument_present',
                               'payable_present', ],
                'cibule.bought': True,
                'cibule.inkitchen': False,
                'brambory.bought': True,
                'brambory.inkitchen': False,
                'payable': ('brambory', 'okurky', 'jahody', )
                },
        ),
    ScenarioStep(tsGOTO, 'Jdi sklad',          
        (GOTO := 'Honza se přesunula do prostoru:\n') + 'Sklad',
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', 'Cibule', ),       
        ( ),                                   
        ),
    ScenarioStep(tsTAKE, 'Vezmi mlíko',              # Zadaný příkaz
        (TAKE := 'Honza dala do košíku objekt ')  + 'Mlíko',
        'Sklad',                                  # Aktuální prostor
        ('Dům', 'Kuchyn', ),              
        ('Těstoviny', 'Cibule', ),         
        ('Mlíko', ),                    
        ),
    ScenarioStep(tsTAKE, 'Vezmi těstoviny',           # Zadaný příkaz
        TAKE + 'Těstoviny',
        'Sklad',                                  # Aktuální prostor
        ('Dům', 'Kuchyn', ),             
        ('Cibule',  ),                     
        ('Mlíko', 'Těstoviny',  ),           
        ),
    ScenarioStep(tsGOTO, 'Jdi kuchyn',         
        GOTO + \
        (KITCHEN := 'kucnyn, kde maminka vari jidlo'),
        'Kuchyn',                              
        ('Dům', 'Sklad',),              
        ('Maminka',),         # H-objekty v prostoru
        ('Mlíko', 'Těstoviny', ),                  
        ),
    ScenarioStep(tsPUT_DOWN, 'Polož mlíko',       # Zadaný příkaz
        (PUT_DOWN := 'Honza vyndal z košíku objekt ') + 'Mlíko',
        'Kuchyn',                          # Aktuální prostor
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko',),               # H-objekty v prostoru
        ('Těstoviny', ),                # H-Objekty v batohu
        ),
    ScenarioStep(tsPUT_DOWN, 'Polož těstoviny',       # Zadaný příkaz
        (PUT_DOWN := 'Honza vyndal z košíku objekt ') + 'Těstoviny',
        'Kuchyn',                          # Aktuální prostor
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny',),      
        ( ),                                 # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi dům',           # Zadaný příkaz
        GOTO  + (HOUSE := 'Domeček, ve kterém Honza bude vařit'),
        'Dům',                                # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),              
        ( ),                      # H-Objekty v batohu
        ),
     ScenarioStep(tsTAKE, 'Vezmi peníze',      # Zadaný příkaz
        TAKE + 'Peníze',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn',  ),       
        ('Dedecek', 'Plysak', 'Kniha', ),           
        ('Peníze',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi ulice',           # Zadaný příkaz
        GOTO + (STREET := 'Ulice, ktera vede k albertu '),
        'Ulice',                                # Aktuální prostor
        ('Dům', 'Albert',),      
        ('Kamarád',  ),            # H-objekty v prostoru
        ('Peníze', ),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi albert',           # Zadaný příkaz
        GOTO + (MARKET := 'Obchod, kde Honza kupuje potraviny '),
        'Albert',                                # Aktuální prostor
        ('Ulice',  ),
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',), 
        ('Peníze', ),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsNS_1, 'Kup brambory',          # Zadaný příkaz
        (NS_1 := 'Honza zjisti, jestli muze zaplatit ') + 'Brambory',
        'Albert',                                  # Aktuální prostor
        ('Ulice',  ),                        
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',),      
        ('Peníze', ),                 # H-Objekty v batohu
        needs = {'tests': ['argument_present',
                                'argument_payable'],
                 'brambory.bought': True},
        sets  = {'brambory.bought': False},
        ),
    ScenarioStep(tsTAKE, 'Vezmi brambory',           # Zadaný příkaz
        TAKE + 'Brambory',
        'Albert',                         
        ('Ulice',  ),                                 # Aktuální sousedé
        ('Okurky', 'Jahody', 'Kasa',),          
        ('Peníze', 'Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi ulice',           # Zadaný příkaz
        GOTO + 'Ulice',
        'Ulice',                           # Aktuální prostor
        ('Dům', 'Albert',),                       # Aktuální sousedé
        ('Kamarád',  ),            # H-objekty v prostoru
        ('Peníze', 'Brambory',),          # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi dům',           # Zadaný příkaz
        GOTO + HOUSE,
        'Dům',                                # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),
        ('Dedecek', 'Plysak', 'Kniha', ),            
        ('Peníze', 'Brambory', ),                 # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi kuchyn',                # Zadaný příkaz
        GOTO + KITCHEN,
        'Kuchyn',                                   # Aktuální prostor
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny',),         # H-objekty v prostoru
        ('Peníze', 'Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsPUT_DOWN, 'Polož brambory',       # Zadaný příkaz
        (PUT_DOWN := 'Honza vyndal z košíku objekt ') + 'Brambory',
        'Kuchyn',                                      # Aktuální prostor
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory',),  
        ('Peníze',  ),                           # H-Objekty v batohu
        ),
    ScenarioStep(tsNS_0, 'Odnes',                 # Zadaný příkaz
        (NS_0 := 'Honza nechal v kuchyni Brambory'),
        'Kuchyn',                                # Aktuální prostor
        ('Dům', 'Sklad',),                            # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory', ), 
        ('Peníze',),                                     
        needs = {'tests': ['payable_present', ],
                 'brambory.bought': False,
                 'brambory.inkitchen':  False},
        sets  = {'brambory.inkitchen':  True },
        ),
    ScenarioStep(tsSUCCESS, 'Popřej',                  # Zadaný příkaz
        ((SUCCESS1 := 'Honza koupil objekt ') + 'Brambory'
      +  (SUCCESS2 := ' a vse je prineseno k vareni\n'
          'Úspěšně jste ukončili hru.\nDěkujeme, že jste si zahráli.')
        ),
        'Kuchyn',                                # Aktuální prostor
        ('Dům', 'Sklad', ),                            # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory', ),
        ('Peníze', ),                                     
        needs = {'tests': ['payable_present', ],
                 'brambory.inkitchen':  True},
        ),
    )   # N-tice
)   # Konstruktor




############################################################################

ScenarioStep.next_index = +1  # Index prvního kroku za startem

BASIC = Scenario(stBASIC, (
    START_STEP,
    ScenarioStep(tsGOTO, 'Jdi sklad',                 # Zadaný příkaz
        (GOTO := 'Honza se přesunula do prostoru:\n') + 'Sklad',
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', 'Cibule', ),     # H-objekty v prostoru
        ( ),                                       # H-Objekty v batohu
        ),
    ScenarioStep(tsTAKE, 'Vezmi cibule',            # Zadaný příkaz
        TAKE + 'Cibule',
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', ),         # H-objekty v prostoru
        ('Cibule', ),                     # H-Objekty v batohu
        ),
    ScenarioStep(tsPUT_DOWN, 'Polož cibule',        # Zadaný příkaz
        PUT_DOWN + 'Cibule',
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', 'Cibule', ),    # H-objekty v prostoru
        ( ),                                 # H-Objekty v batohu
        ),
    ScenarioStep(tsHELP, '?',                       # Zadaný příkaz
        SUBJECT,
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', 'Cibule', ),   # H-objekty v prostoru
        ( ),                                # H-Objekty v batohu
        ),
    ScenarioStep(tsEND, 'KONEC',                    # Zadaný příkaz
        END := 'Ukončili jste hru.\nDěkujeme, že jste si zahráli.',
        'Sklad',                                   # Aktuální prostor
        ('Dům', 'Kuchyn',),                        # Aktuální sousedé
        ('Mlíko', 'Těstoviny', 'Cibule', ),    
        ( ),                                       # H-Objekty v batohu
        ),
    )   # N-tice
)   # Konstruktor



############################################################################
# Základní chybový scénář demonstrující průběh hry, při němž hráč
# zadává chybně příkazy k provedení základních akcí
# a současně vyzkouší vyvolání nápovědy a nestandardní ukončení.


ScenarioStep.next_index = -1  # Index kroku před korektním startem

WRONG_START = ScenarioStep(tsNOT_START, 'start', # Zadaný příkaz
        NOT_START := (
        'Prvním příkazem není startovací příkaz.\n' 
        'Hru, která neběží, lze spustit pouze startovacím příkazem.\n'),
        '',                                         # Aktuální prostor
        (),                                         # Aktuální sousedé
        (),                                         # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        )

ScenarioStep.next_index = +1  # Index prvního kroku za startem

MISTAKE = Scenario(stMISTAKES, (
    WRONG_START,
    START_STEP,
    ScenarioStep(tsEMPTY, '',                       # Zadaný příkaz
        EMPTY := 'Prázdný příkaz lze použít pouze pro start hry',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),        
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),   # H-obju
        (), 
        ),
    ScenarioStep(tsUNKNOWN, 'bez',                 # Zadaný příkaz
        (UNKNOWN := 'Tento příkaz neznám: ') + 'bez',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),       
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ), 
        (),                                         # H-Objekty v batohu
        ),
    ScenarioStep(tsMOVE_WA, "jdi",                  # Zadaný příkaz
        MOVE_WA := ('Nevím, kam mám jít.\n'
                    'Je třeba zadat název cílového prostoru.'),
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),           
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ), # H-objekty
        (),                                         # H-Objekty v batohu
        ),
    ScenarioStep(tsTAKE_WA, "vezmi",                # Zadaný příkaz
        TAKE_WA := ('Nevím, co mám zvednout.\n'
                    'Je třeba zadat název zvedaného objektu.'),
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),             
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ), # H-obj
        (),                                         # H-Objekty v batohu
        ),
    ScenarioStep(tsPUT_DOWN_WA, "polož",            # Zadaný příkaz
        PUT_DOWN_WA := ('Nevím, co mám položit.\n'
                        'Je třeba zadat název pokládaného objektu.'),
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),          
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        ),
    ScenarioStep(tsBAD_NEIGHBOR, "jdi albert", # Zadaný příkaz
         (BAD_NEIGHBOR := 'Do zadaného prostoru se odsud jít nedá: ')
                        + 'Albert',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),             
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        ),
    ScenarioStep(tsBAD_ITEM, "vezmi brambory",        # Zadaný příkaz
        (BAD_ITEM := 'Zadaný objekt v prostoru není: ') + 'Brambory',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),                 
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                          # H-Objekty v batohu
        ),
    ScenarioStep(tsUNMOVABLE, "vezmi dedecek",         # Zadaný příkaz
        (UNMOVABLE := 'Zadaný objekt není možno vzit: ') + 'Dedecek',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),              
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                          # H-Objekty v batohu
        ),
    ScenarioStep(tsTAKE, 'Vezmi peníze',              # Zadaný příkaz
        TAKE + 'Peníze',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),       
        ('Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze',),                                 # H-Objekty v batohu
        ),
    ScenarioStep(tsTAKE, 'Vezmi plysak',           # Zadaný příkaz
        TAKE + 'Plysak',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),       
        ('Dedecek', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze', 'Plysak',),                     # H-Objekty v batohu
        ),
    ScenarioStep(tsBAG_FULL, 'Vezmi kniha',       # Zadaný příkaz
        (BAG_FULL := 'Zadaný objekt se už do košíku nevejde: ') + 'Kniha',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),         
        ('Dedecek', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze', 'Plysak',),                     # H-Objekty v batohu
        ),
    ScenarioStep(tsNOT_IN_BAG, 'polož kniha',     # Zadaný příkaz
        (NOT_IN_BAG := 'Zadaný objekt v košíku není: ') + 'Kniha',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),       
        ('Dedecek', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze', 'Plysak',),                     # H-Objekty v batohu
        ),
    ScenarioStep(tsHELP, '?',                       # Zadaný příkaz
        SUBJECT,
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),              
        ('Dedecek', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze', 'Plysak',),                     # H-Objekty v batohu
        ),
    ScenarioStep(tsEND, 'KONEC',                    # Zadaný příkaz
        END,
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),         
        ('Dedecek', 'Kniha', ),  # H-objekty v prostoru
        ('Peníze', 'Plysak',),                     # H-Objekty v batohu
        ),
    )   # N-tice
)   # Konstruktor



############################################################################
# Základní chybový scénář demonstrující průběh hry, při němž hráč
# zadává chybně příkazy k provedení povinně definovaných akcí.
ScenarioStep.next_index = 5    # Index prvního nestandardního kroku
MISTAKE_NS = Scenario(stMISTAKES_NS, (
    HAPPY.steps[0],
    ScenarioStep(tsNS0_WrongCond, 'Odnes',        # Zadaný příkaz
        NS0_WrongCondA := 'Honza nenechal v kuchyni Brambory.',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),     
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                        # H-Objekty v batohu
        needs = {'tests': ['payable_present']}
        ),
    ScenarioStep(tsNOT_SUCCESS, 'Popřej',        # Zadaný příkaz
        NOT_SUCCESa := 'Honza nekoupil objekt Brambory\n'
        'Úspěšně jste neukončili hru.',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),              
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        needs = {'tests': ['payable_present']}
        ),
    ScenarioStep(tsNS1_WRONG_ARG, 'Kup dedecek',    # Zadaný příkaz
        (NS1_WRONG_ARGa := 'Nelze koupit objekt ') + 'Dedecek',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),            
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        needs = {'tests': ['argument_present']}
        ),
    HAPPY.steps[1],   # Vezmi víno
    HAPPY.steps[2],   # Vezmi Bábovka
    HAPPY.steps[3],   # Jdi les
    HAPPY.steps[4],   # Jdi Temný_les
    HAPPY.steps[5],   # Jdi Chaloupka
    HAPPY.steps[6],   # Polož Bábovka
    HAPPY.steps[7],   # Polož Víno
    ScenarioStep(tsNS0_WrongCond, 'Odnes',        # Zadaný příkaz
        (NS0_WrongCond1 := 'Honza nenechal v kuchyni ') + 'Brambory'
      + (NS0_WrongCond2 := '.'),
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),           
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                         # H-Objekty v batohu
        needs = {'tests': ['payable_present'],
                 'brambory.bought': False},
        ),
    ScenarioStep(tsNS1_0Args, 'Kup',             # Zadaný příkaz
        NS1_0Args := 'Nevím, co mam koupit',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),         
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                       # H-Objekty v batohu
        ),
    ScenarioStep(tsNS1_WRONG_ARG, 'Kup peníze',    # Zadaný příkaz
        (NS1_WRONG_ARGb := 'Nelze koupit objekt ') + 'Peníze',
        'Dům',                                  # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),          
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),  # H-objekty v prostoru
        (),                                            # H-Objekty v batohu
        needs = {'tests': ['argument_payable']}
        ),
    ScenarioStep(tsGOTO, 'Jdi ulice',           # Zadaný příkaz
        GOTO + (STREET := 'Ulice, ktera vede k albertu '),
        'Ulice',                                # Aktuální prostor
        ('Dům', 'Albert',),                
        ('Kamarád',  ),            # H-objekty v prostoru
        ( ),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi albert',           # Zadaný příkaz
        GOTO + (MARKET := 'Obchod, kde Honza kupuje potraviny '),
        'Albert',                                # Aktuální prostor
        ('Ulice',  ),
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',), 
        (),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsNS_1, 'Kup Brambory',          # Zadaný příkaz
        (NS_1 := 'Honza zjisti, jestli muze zaplatit ') + 'Brambory',
        'Albert',                                  # Aktuální prostor
        ('Ulice',  ),                                 # Aktuální sousedé
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',),  
        ( ),                 # H-Objekty v batohu
        needs = {'tests': ['argument_present',
                                'argument_payable'],
                 'brambory.bought': True},
        sets  = {'brambory.bought': False},
        ),
    ScenarioStep(tsNS1_WrongCond, 'Kup brambory', # Zadaný příkaz
        ((NS1_WrongCond := 'Nelze koupit objekt, ktery je již koupen: ')
                         + 'Brambory'),
        'Albert',                                  # Aktuální prostor
        ('Ulice',  ),                                 # Aktuální sousedé
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',),   
        ( ),                                        # H-Objekty v batohu
        needs = {'brambory.bought': True}
        ),
    ScenarioStep(tsNOT_SUCCESS, 'popřej',           # Zadaný příkaz
        (NOT_SUCCESSb1 := 'Objekt ') + 'Brambory'
      + (NOT_SUCCESSb2 := ' ještě nebyl koupen'),
        'Albert',                                  # Aktuální prostor
        ('Ulice',  ),                                 # Aktuální so
        ('Brambory', 'Okurky', 'Jahody', 'Kasa',),    
        ( ),                                        # H-Objek
        needs = {'tests': ['argument_present',
                                'argument_payable'],
                 'brambory.bought':  True }
        ),
    ScenarioStep(tsTAKE, 'Vezmi brambory',           # Zadaný příkaz
        TAKE + 'Brambory',
        'Albert',                                  # Aktuální prostor
        ('Ulice',  ),                                 # Ak
        ('Okurky', 'Jahody', 'Kasa',),     
        ('Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi ulice',           # Zadaný příkaz
        GOTO + 'Ulice',
        'Ulice',                                # Aktuální prostor
        ('Dům', 'Albert',),           
        ('Kamarád',  ),            # H-objekty v prostoru
        ('Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi dům',           # Zadaný příkaz
        GOTO + HOUSE,
        'Dům',                                # Aktuální prostor
        ('Sklad', 'Ulice', 'Kuchyn', ),
        ('Peníze', 'Dedecek', 'Plysak', 'Kniha', ),           
        ('Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsGOTO, 'Jdi kuchyn',           # Zadaný příkaz
        GOTO + KITCHEN,
        'Kuchyn',                             # Aktuální prostor
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', ),         # H-obj
        ('Brambory',),                      # H-Objekty v batohu
        ),
    ScenarioStep(tsPUT_DOWN, 'Polož brambory',       # Zadaný příkaz
        (PUT_DOWN := 'Honza vyndal z košíku objekt ') + 'Brambory',
        'Kuchyn',                                      # Aktuální r
        ('Dům', 'Sklad',),                 # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory',), 
        ( ),                           # H-Objekty v batohu
        ),
     ScenarioStep(tsNS_0, 'Odnes',                 # Zadaný příkaz
        (NS_0 := 'Honza nechal v kuchyni Brambory'),
        'Kuchyn',                                # Aktuální prostor
        ('Dům', 'Sklad',),                            # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory',),
        (),                                         # H-Objekty v batohu
        needs = {'tests': ['payable_present', ],
                 'brambory.bought': False,
                 'brambory.inkitchen':  False},
        sets  = {'brambory.inkitchen':  True },
        ),
    ScenarioStep(tsNS0_WrongCond, 'Odnes',        # Zadaný příkaz
        (NS0_WrongCondB1 := 'Nemá smysl odnaset objekt ') + 'brambory'
      + (NS0_WrongCondB2 := ', protože již byl odnesen'),
        'Kuchyn',                                # Aktuální prostor
        ('Dům', 'Sklad',),                            # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory',),
        ( ),                                         # H-Objekty v batohu
        needs = {'brambory.bought': False,
                 'brambory.inkitchen':  False},
        sets  = {'brambory.inkitchen':  True },
        ),
    ScenarioStep(tsEND, 'konec',                    # Zadaný příkaz
        END,
        'Kuchyn',                                # Aktuální prostor
        ('Dům', 'Sklad',),                            # Aktuální sousedé
        ('Maminka', 'Mlíko', 'Těstoviny', 'Brambory', ),
        (),                                   # H-Objekty v batohu
        ),
    )   # N-tice
)   # Konstruktor




###########################################################################q

# Slovník převádějící názvy scénářů na scénáře
NAME_2_SCENARIO = {
    HAPPY       .name: HAPPY,     # Základní úspěšný (= šťastný) scénář
    BASIC       .name: BASIC,     # Scénář obsahující jen povinné akce
    MISTAKE     .name: MISTAKE,   # Scénář chybně zadaných povinných akcí
    MISTAKE_NS  .name: MISTAKE_NS,# Scénář chybně zadaných dodatečných akcí
}



###########################################################################q
dbg.stop_pkg(1, __name__)
