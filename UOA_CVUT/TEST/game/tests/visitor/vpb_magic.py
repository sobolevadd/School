#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tests/visitor/vpb_magic.py
"""
Modul testuje správné zapracování modifikace `MAGIE`¤
definované následovně:

- Provedení akce bude záviset na třech příznacích:
  * příznak `MAGIC` indikuje, zda akce již byla korektně použita,
  * příznak 'ARGUMENT' slouží k zadání kroku scénáře se špatným argumentem,
  * příznak 'NOEND' indikuje, zda akce připravila zrychlené dosažení cíle.
  Na počátku hry budou všechny inicializovány na hodnotu `True`.

- Při zadání příkazu s argumentem `KOUZLO` se stane následující:
  * Kapacita batohu se zvětší o 1.
  * V batohu se objeví předmět nazvaný `KOUZLO`.
  Nic jiného se na aktuálním stavu hry nezmění.
  Korektní zadání příkazu vyžaduje, aby příznak `MAGIC` měl hodnotu `True`.
  Korektně spuštěná akce změní jeho hodnotu na `False` a odpoví:
  Dosažení cíle vám usnadní právě získaný objekt KOUZLO

- Má-li již hráč v batohu předmět `KOUZLO` a zadá-li příkaz
  MAGIE KONEC
  tak se hra dostane do stavu po předposledním příkazu šťastného scénáře.
  Korektní zadání příkazu vyžaduje, aby příznak `NOEND` měl hodnotu `True`.
  Korektně spuštěná akce změní jeho hodnotu na `False` a odpoví:
  Vše je připraveno pro to, abyste zadáním příkazu XXX dosáhli KONEC
  kde XXX zastupuje název závěrečné akce šťastného scénáře.

- Bude-li v následujícím kroku zadán ukončovací příkaz,
  odpoví hra stejně jako v závěrečném kroku úspěšného scénáře.

- Bude-li příkaz `MAGIE` zadán s jiným než požadovaným argumentem
  (případně bude-li zadán bez argumentů) nebo nebude-li splněna
  požadovaná hodnota příznaku, stav hry se nesmění a hra uživateli odpoví:
  Příkaz MAGIE neznám.

"""
import dbg; dbg.start_pkg(1, __name__, __doc__)
###########################################################################q

import game.tests as gt
# Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
gt.VERBOSITY = gt.Verbosity.STEP_ATTR   # Podrobnost výpisu průběhu testu

from game.api.interfaces import IPkgInitor, IGame
from game.api.scen_types import (HAPPY_NAME, MISTAKE_NAME, stGENERAL,
                                 tsNS_1, tsNS1_0Args, tsBAG_FULL,
                                 tsNS1_WRONG_ARG, tsNS1_WrongCond,
                                 )
from game.api.scenario   import ScenarioStep, Scenario
from game.tests          import Level
from game.tests.visitor  import Visitor



###########################################################################q
# KONSTANTY
ACTION = 'MAGIE'    # Název přidávané akce
ITEM   = 'KOUZLO'   # Položka přibyvší do batohu po prvním korektním použití
ARG_1  = 'KOUZLO'   # Argument pro první korektní použití
ARG_2  = 'KONEC'    # Argument pro druhé korektní použití
FLAG_1 = 'MAGIC'    # Příznak podmiňující první korektní použití
VAL_1  = True       # Hodnota příznaku podmiňující první korektní použití
FLAG_2 = 'NOEND'    # Příznak podmiňující druhé korektní použití
VAL_2  = True       # Hodnota příznaku podmiňující druhé korektní použití
ARG    = 'ARGUMENT' # Pomocný příznak pro test nevhodného argumentu
ARG_VAL= True       #

MSG_0  = 'Příkaz MAGIE neznám.'
MSG_1  = 'Dosažení cíle vám usnadní právě získaný objekt KOUZLO'
MSG_2a = 'Vše je připraveno pro to, abyste zadáním příkazu '
MSG_2b = ' dosáhli KONEC'


# Slovník indikující již inicializované portály.
PORTAL_2_PREPARED = {}



###########################################################################q

class VisitorMagic(Visitor):
    """
    Pomáhá kontrolovat správnost řešení popsaného v dokumentaci modulu.
    """

    # @dbg.prSEd()
    def __init__(self, portal:IPkgInitor, level:Level):
        """
        Součástí přípravy návštěvníka je i doplnění scénáře
        testujícího rozšíření do sady scénářů dodané portálem.
        
        :param portal: Portál zprostředkující komunikaci s testovanou aplikací
        :param level:
        """
        super().__init__(portal, level)
        if PORTAL_2_PREPARED.get(portal):  return
        prepare_test_scenario(portal)


    def before_game_start(self, scenario:Scenario) -> None:
        """
        Akce, která se má provést před spuštěním hry.
        Cílem metody je prověřit scénáře a případné další pomocné kódy.

        :param scenario: Scénář, podle nějž se hra testuje
        """
        self.scenario = scenario


    # @dbg.prSEda()
    def after_game_start(self, scenario:Scenario) -> None:
        """
        Akce, která se má provést po provedení startovacího kroku hry
        (tj. ve chvíli, kde je hra již inicializována), ale před jeho testem,
        tj. před ověřením, že stav hry odpovídá scénáři.
        TODO Prověří, že hra deklaruje právě ty akce, které jsou deklarované
        TODO ve scénářích a uloží seznam jejich abecedně seřazených názvů.
        Cílem metody je připravit potřebné informace o testované hře.
        
        :param scenario: Scénář, podle nějž se hra testuje
        """


    def before_entering_command(self, step:ScenarioStep) -> None:
        """
        Akce, která se má provést před zadáním příkazu hře.
        Používá se zřídka. Při její definici je třeba vzít v úvahu, že se
        u startovacího kroku provede ještě před odstartováním hry,
        tj. před metodou `after_game_start`.

        :param step: Aktuálně prověřovaný krok scénáře
        :return: Aktuálně prověřovaný krok scénáře
        """


    def before_step_test(self, step:ScenarioStep, answer:str) -> None:
        """
        Akce, která se má provést po provedení kroku hry, ale před jeho
        testem, tj. před ověřením, že stav hry odpovídá scénáři.
        
        :param step:    Aktuálně prověřovaný krok scénáře
        :param answer:  Odpověď hry na zadání příkazu
        """


    def after_step_test(self, step:ScenarioStep, answer:str) -> None:
        """
        Akce, která se má provést po testu aktuálního kroku.
        :param step:   Aktuálně prověřovaný krok scénáře
        :param answer: Odpověď hry na zadání příkazu
        """


    def after_game_end(self, verbose_message:str='',
              exception:Exception=None, summary:'GameSummary'=None) -> None:
        """
        Akce, která se má provést po testu posledního kroku.
        
        :param verbose_message: Kompletní zpráva o průběhu testu
        :param exception:       Případná vyhazovaná výjimka
        :param summary:         Přepravka s informacemi o předpokládaném
                                průběhu hry podle scénářů
        """

    def fourth_scenario(portal: IPkgInitor) -> None:
        """
        Inicializuje několik globálních proměnných
        a vytvoří testovací scénář pro prověrku požadovaného rozšíření.

        :param portal: Portál zprostředkující komunikaci s testovanou aplikací
        """


############################################################################

# @dbg.prSEd()
def prepare_test_scenario(portal:IPkgInitor) -> None:
    """
    Inicializuje několik globálních proměnných
    a vytvoří testovací scénář pro prověrku požadovaného rozšíření.
    
    :param portal:  Portál zprostředkující komunikaci s testovanou aplikací
    """
    global name2scenario, happy, start_step, last_step, success_action

    name2scenario   = portal.NAME_2_SCENARIO()
    happy           = name2scenario[HAPPY_NAME]
    start_step      = check_start_step()
    last_step       = happy.steps[-1]
    penultimate_step= happy.steps[-2]
    success_action  = last_step.command.upper()
    # dbg.prIN(1, f'{name2scenario = }')
    mistake         = name2scenario[MISTAKE_NAME]

    ScenarioStep.next_index = 1
    place     = start_step.place
    neighbors = start_step.neighbors
    items     = start_step.items
    bag       = start_step.bag
    # Krok č. 0
    steps     = [start_step]    # Zárodek vytvářeného scénáře
    # Krok č. 1
    steps.append(ScenarioStep(typeOfStep = tsNS1_0Args,
                 command=ACTION,
                 message=MSG_0,         place=place,
                 neighbors=neighbors,   items=items,        bag=bag))
    # Krok č. 2
    steps.append(ScenarioStep(typeOfStep = tsNS1_WRONG_ARG,
                 command=ACTION + ' ' + ARG_2,
                 message=MSG_0,         place=place,
                 neighbors=neighbors,   items=items,        bag=bag,
                 needs = {ARG : False})
                )
    # Krok č. 3
    steps.append(ScenarioStep(typeOfStep = tsNS_1,
                 command = ACTION + ' ' + ARG_1,
                 message = MSG_1,       place = place,
                 neighbors=neighbors,   items=items,
                 bag   = (bag := bag + (ITEM,)),
                 needs = {FLAG_1 : VAL_1},
                 sets  = {FLAG_1 : not VAL_1})
                )
    # Krok č. 4
    steps.append(ScenarioStep(typeOfStep = tsNS1_WrongCond,
                 command  = ACTION + ' ' + ARG_1,
                 message  = MSG_0,      place = place,
                 neighbors=neighbors,   items=items,       bag=bag,
                 needs = {FLAG_1 : VAL_1})
                )
    # Kroky Mistake
    for step in mistake.steps[2:]:
        steps.append(ScenarioStep(
            step.typeOfStep, step.command, step.message,
            step.place, step.neighbors, step.items,
            bag   = step.bag + (ITEM,),
            needs = step.needs,    sets = step.sets)
        )
        if step.typeOfStep == tsBAG_FULL:   break;

    # Krok č. n-1
    steps.append(ScenarioStep(typeOfStep = tsNS_1,
                 command  = ACTION + ' ' + ARG_2,
                 message  = MSG_2a + success_action + MSG_2b,
                 place    = penultimate_step.place,
                 neighbors= penultimate_step.neighbors,
                 items    = penultimate_step.items,
                 bag      = penultimate_step.bag,
                 needs    = {FLAG_2 : VAL_2},
                 sets     = last_step.needs | {FLAG_2: not VAL_2})
                )
    # Krok č. n
    steps.append(ScenarioStep(typeOfStep = tsNS1_WrongCond,
                 command  = ACTION + ' ' + ARG_2,
                 message  = MSG_0,
                 place    = penultimate_step.place,
                 neighbors= penultimate_step.neighbors,
                 items    = penultimate_step.items,
                 bag      = penultimate_step.bag,
                 needs    = {FLAG_2 : VAL_2})
                )
    # Krok č. 7
    steps.append(last_step)

    # # Vytiskne vytvořený scénář
    if gt.VERBOSITY >= gt.Verbosity.DETAILS:
        print(f'{60 * "%"}')
        for s in steps: print(s)
        print(f'{60 * "%"}')
    # Požadovaný název je zadán v modulu `test_game`
    from game.tests.test_game import LEVEL_2_SCENARIOS as L2S
    name                = L2S[Level.EXTENDED][-1]
    scenario            = Scenario(stGENERAL, steps, name)
    name2scenario[name] = scenario
    PORTAL_2_PREPARED[portal] = True
    # dbg.prIN(1, f'{name2scenario = }\n{portal.NAME_2_SCENARIO() = }')


@dbg.prSEd()
def check_start_step() -> ScenarioStep:
    """
    Prověří, že startovní krok byl požadovaným způsobem rozšířen,
    a vrátí jej.

    :return: Prověřený startovní krok
    """
    start_step = happy.steps[0]
    if (    (start_step.sets.get(FLAG_1) == VAL_1)
        and (start_step.sets.get(FLAG_2) == VAL_2)
        and (start_step.sets.get(ARG)    == ARG_VAL)
    ):
        return start_step
    else:
        msg = (f'Startovní krok nedefinuje požadované příznaky\n'
               f'{FLAG_1!r}={VAL_1}, {FLAG_2!r}={VAL_2}\n'
               f'Obdrženo:\n{start_step}')
        err0(msg)


###########################################################################q

def err0(reason:str) -> None:
    """
    Chyba odhalená před tím, než se začnou procházet kroky scénáře.
    """
    msg = f'\n{reason}\n'
    print(msg)
    raise Exception(msg)


def err1(reason:str, expected:ScenarioStep, obtained:ScenarioStep) -> None:
    """
    Chyba odhalená při procházení kroků scénáře před spuštěním hry.
    """
    msg = (f'\n{expected.index}'
           f'. krok testovacího scénáře neodpovídá požadavkům - {reason}:\n'
           f'Očekáván krok typu {expected.typeOfStep}:\n{expected}\n\n'
           f'Obdržen krok typu {obtained.typeOfStep}:\n{obtained}\n')
    print(msg)
    raise Exception('Krok testovacího scénáře neodpovídá požadavkům')



###########################################################################q

def test(portal):
    from game.tests                 import Level
    from game.tests.test_interface  import test as ti
    ti(portal, Level.EXTENDED, VisitorMagic)



###########################################################################q
dbg.stop_pkg(1, __name__)
