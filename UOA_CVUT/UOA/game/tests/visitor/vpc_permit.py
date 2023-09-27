#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tests/visitor/vpc_permit.py
"""
Modul testuje správné zapracování akce `ZÍSKAT`¤
definované následovně:


- Provedení akce bude záviset na dvou příznacích:
  = příznak `OBTAINED` indikuje, zda akce již byla korektně použita,
  = příznak 'ARGUMENT' slouží k zadání kroku scénáře se špatným argumentem,
  Na počátku hry budou oba příznaky inicializovány na hodnotu `False`.

- Při zadání příkazu s argumentem `POVOLENÍ` se stane následující:
  = Kapacita batohu se zvětší o 1.
  = V batohu se objeví předmět nazvaný `POVOLENÍ`.
  Nic jiného se na aktuálním stavu hry nezmění.
  Korektní zadání příkazu vyžaduje, aby příznak `OBTAINED` měl hodnotu `False`.
  Korektně spuštěná akce změní jeho hodnotu na `True` a odpoví:
  Dosažení cíle vám umožní právě získaný objekt POVOLENÍ

- Bude-li příkaz `ZÍSKAT` zadán s jiným než požadovaným argumentem
  (případně bude-li zadán bez argumentů) nebo nebude-li splněna
  požadovaná hodnota příznaku `OBTAINED`, stav hry se nesmění
  a hra uživateli odpoví:
  Příkaz ZÍSKAT neznám.

- Standardní ukončení hry bude vyžadovat, aby se v batohu vyskytoval
  předmět `POVOLENÍ`. V opačném případě hra oznámí:
  K úspěšnému ukončení hry je třeba nejprve získat povolení.
"""

import dbg; dbg.start_pkg(1, __name__, __doc__)
###########################################################################q
# KONSTANTY

from game.api.scen_types    import (
     HAPPY_NAME, BASIC_NAME, MISTAKE_NAME, MISTAKE_NS_NAME)

ACTION = 'ZÍSKAT'   # Název přidávané akce
ITEM   = 'POVOLENÍ' # Položka přibyvší do batohu po prvním korektním použití
ARG_1  = 'POVOLENÍ' # Argument pro první korektní použití
FLAG_1 = 'OBTAINED' # Příznak podmiňující první korektní použití
VAL_1  = False      # Hodnota příznaku podmiňující první korektní použití
ARG    = 'ARGUMENT' # Pomocný příznak pro test nevhodného argumentu
ARG_VAL= False      #

MSG_0  = 'Příkaz ZÍSKAT neznám.'
MSG_1  = 'Dosažení cíle vám umožní právě získaný objekt POVOLENÍ'
MSG_2  = 'K úspěšnému ukončení hry je třeba nejprve získat povolení'

OLD_HAPPY   = 'OLD_HAPPY'
OLD_MISTAKE = 'OLD_MISTAKE'

# Slovník indikující již inicializované portály.
PORTAL_2_PREPARED = {}



###########################################################################q
# PŘIZPŮSOBENÍ TESTOVACÍHO PROSTŘEDÍ DANÉ ÚLOZE

from game.tests import Level, test_game as tg

# @dbg.prSEd()
def prepare_test_environment() -> None:
    """
    Připraví testovací prostředí pro test aplikací
    řešících zadání definované v tomto modulu.
    """
    tg.LEVEL_2_SCENARIOS[Level.EXTENDED] = (
        HAPPY_NAME, HAPPY_NAME, MISTAKE_NAME, MISTAKE_NS_NAME,
        OLD_HAPPY, OLD_MISTAKE)
    # dbg.prIN(1, f'{tg.LEVEL_2_SCENARIOS = }')

    def string(self) -> str:
        """
        Jako uživatelský podpis daného scénáře vrátí jeho název
        následovaný výpisem jeho kroků.
        """
        result  = f'Definice scénáře {self._name}\n{70*"V"}\n'
        steps   = [f'{step}' for step in self._steps]
        result += '\n'.join(steps) + f'{70*"A"}\n' \
                  f'Konec definice scénáře: {self._name}\n\n'
        return result

    from game.api.scenario import Scenario
    Scenario.string = string

prepare_test_environment()



###########################################################################q
# IMPORTY

import game.tests as gt
# Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
# gt.VERBOSITY = gt.Verbosity.STEP_ATTR   # Podrobnost výpisu průběhu testu

from game.api.interfaces  import IPkgInitor, IGame
from game.api.scen_types  import (
     tsNS_1, tsNS1_0Args, tsBAG_FULL, tsNS1_WRONG_ARG, tsNS1_WrongCond,
     tsSTART, tsNOT_SUCCESS, tsSUCCESS, tsEND,
     stHAPPY, stBASIC, stMISTAKES, stMISTAKES_NS, stGENERAL
     )
from game.api.scenario    import ScenarioStep, Scenario
from game.tests           import Verbosity, prVb
from game.tests.visitor   import Visitor



###########################################################################q

class VisitorPermit(Visitor):
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


    def before_game_start(self, scenario:Scenario) -> None:
        """
        Akce, která se má provést před spuštěním hry.
        Cílem metody je prověřit scénáře a případné další pomocné kódy.

        :param scenario: Scénář, podle nějž se hra testuje
        """
        self.scenario = scenario



###########################################################################q

class WrappedPortal(IPkgInitor): # Je strukturálním potomkem protokolu `IPkgInitor`
    """
    Instance třídy slouží jako dekorátory portálů upravující některé
    vlastnosti dekorovaného portálu.
    """
    
    def __init__(self, original:IPkgInitor):
        """ Vymění scénáře dekorovaného portálu.
        """
        super().__init__()
        self.original           = original
        self.__name__           = original.__name__
        self.__package__        = original.__package__
        self.AUTHOR_ID          = original.AUTHOR_ID
        self.AUTHOR_NAME        = original.AUTHOR_NAME
        self.AUTHOR_NATIVE_NAME = original.AUTHOR_NATIVE_NAME
        self.org_game           = original.GAME()
        self.org_name2scenario  = original.NAME_2_SCENARIO()
        self._name2scenario     = self.prepare_scenarios()


    def NAME_2_SCENARIO(self):
        """Vrátí odkaz na slovník převádějící názvy scénářů na dané scénáře
        Scénáře musejí být instancemi třídy `game.api.scenario.Scenario`
        """
        return self._name2scenario


    def GAME(self):
        """Vrátí odkaz na hru.
        """
        return self.original.GAME()


    def prepare_scenarios(self) -> dict[str:Scenario]:
        """
        Vytvoří a vrátí základní šestici scénářů.
        """
        org_happy  = self.org_name2scenario[HAPPY_NAME]
        org_start  = org_happy.steps[0]

        # Startovní krok nového happy scénáře
        ScenarioStep.next_index = 0
        self.start = ScenarioStep(typeOfStep= tsSTART,
                     command   = '',
                     message   = org_start.message,
                     place     = org_start.place,
                     neighbors = org_start.neighbors,
                     items     = org_start.items,
                     bag       = org_start.bag,
                     sets      = org_start.sets | {FLAG_1:VAL_1, ARG:ARG_VAL})
        result = {
            stHAPPY.name       : self.prepare_NEW_HAPPY(org_happy),
            stBASIC.name       : self.prepare_NEW_BASIC(),
            stMISTAKES.name    : self.prepare_NEW_MISTAKES(),
            stMISTAKES_NS.name : self.prepare_MISTAKES_NS(),
            OLD_HAPPY          : self.prepare_OLD_HAPPY(org_happy),
            OLD_MISTAKE        : self.prepare_OLD_MISTAKES(),
        }
        return result


    def prepare_OLD_HAPPY(self, org_happy) -> Scenario:
        """
        Modifikuje původní HAPPY scénář výměnou závěrečného kroku
        za pokus o něj, který neprojde kvůli nezískanému povolení.
        Scénář je proto třeba zakončit nestandardním ukončením hry.
        """
        # Zkopíruje kroky původní verze scénáře s výjimkou posledního kroku
        steps = [self.start] \
              + [step for step in org_happy.steps[1:-1]]
        penultimate_step = steps[-1]
        # Stav předposledního kroku
        place       = penultimate_step.place
        neighbors   = penultimate_step.neighbors
        items       = penultimate_step.items
        bag         = penultimate_step.bag
        ScenarioStep.next_index = len(steps)
        
        # Pokusí se hru ukončit bez získaného povolení
        steps.append(ScenarioStep(typeOfStep= tsNOT_SUCCESS,
                     command   = org_happy.steps[-1].command,
                     message   = MSG_2,     place=place,
                     neighbors = neighbors, items=items, bag=bag,
                     needs     = {FLAG_1:not VAL_1}))
        # Předčasné ukončení - zpráva pro poslední krok ze scénáře BASIC
        steps.append(ScenarioStep(typeOfStep= tsEND,
                     command   = self.org_game.basic_actions().END_NAME,
                     message   = self.org_name2scenario[BASIC_NAME]
                               . steps[-1].message,
                     place     =place,
                     neighbors = neighbors, items=items, bag=bag))
        result = Scenario(stGENERAL, steps, OLD_HAPPY)
        prVb(Verbosity.STEPS, result.string())
        return result


    def prepare_NEW_HAPPY(self, org_happy) -> Scenario:
        """
        Modifikací původního HAPPY scénáře, v níž na počátku získá povolení,
        které si pak hráč nese v batohu do konce hry,
        vytvoří HAPPY scénář pro upravenou hru.
        """
        # Vytvoří zárodek sady kroků se startovním krokem
        steps = [self.start]
        # Zapamatuje si stav počátečního kroku
        place       = self.start.place
        neighbors   = self.start.neighbors
        items       = self.start.items
        bag         = self.start.bag
        ScenarioStep.next_index = 1
        
        # Získání povolení
        steps.append(ScenarioStep(typeOfStep = tsNS_1,
                     command  = ACTION + ' ' + ARG_1,
                     message  = MSG_1,       place = place,
                     neighbors=neighbors,    items =items,
                     bag   = bag + (ITEM,),
                     needs = {FLAG_1 : VAL_1},
                     sets  = {FLAG_1 : not VAL_1})
                    )
        # Zbylé kroky scénáře HAPPY doplněné o povolení v batohu
        for step in org_happy.steps[1:-1]:
            steps.append(ScenarioStep(typeOfStep = step.typeOfStep,
                         command  = step.command,
                         message  = step.message,
                         place    = step.place,
                         neighbors= step.neighbors,
                         items    = step.items,
                         bag      = step.bag + (ITEM, ),
                         needs    = step.needs,
                         sets     = step.sets)
                        )
        # Poslední krok
        step = org_happy.steps[-1]
        steps.append(ScenarioStep(typeOfStep = tsSUCCESS,
                     command  = step.command,
                     message  = step.message,
                     place    = step.place,
                     neighbors= step.neighbors,
                     items    = step.items,
                     bag      = step.bag + (ITEM, ),
                     needs    = step.needs | {FLAG_1: not VAL_1})
                    )
        result = Scenario(stHAPPY, steps)
        prVb(Verbosity.STEPS, result.string())
        return result


    def prepare_NEW_BASIC(self) -> Scenario:
        """
        Doplní pouze novou podobu startovního kroku.
        """
        basic = self.org_name2scenario[BASIC_NAME].steps
        steps = [self.start] \
              + [step for step in basic[1:]]
        result = Scenario(stBASIC, steps)
        prVb(Verbosity.STEPS, result.string())
        return result


    def prepare_OLD_MISTAKES(self) -> Scenario:
        """
        Převezme původní scénář MISTAKES v němž pouze vymění startovní krok.
        Slouží především k ověření toho, že kapacita batohu nevzroste
        bez získáním povolení.
        """
        mistake = self.org_name2scenario[MISTAKE_NAME].steps
        steps = [mistake[0], self.start] \
              + [step for step in mistake[2:]]
        result = Scenario(stGENERAL, steps, OLD_MISTAKE)
        prVb(Verbosity.STEPS, result.string())
        return result


    def prepare_NEW_MISTAKES(self) -> Scenario:
        """
        Přidáním získání povolení za start původního MISTAKES scénáře
        vytvoří jeho ekvivalent pro upravenou hru a ověří,
        že se získáním povolení kapacita batohu opravdu zvýšila.
        """
        mistake = self.org_name2scenario[MISTAKE_NAME].steps
        steps = [mistake[0], self.start]    # Špatný start + start
        # Stav po startovním kroku
        place       = self.start.place
        neighbors   = self.start.neighbors
        items       = self.start.items
        bag         = self.start.bag
        ScenarioStep.next_index = 1
        # Bez argumentů
        steps.append(ScenarioStep(typeOfStep=tsNS1_0Args,
                     command=ACTION,
                     message=MSG_0, place=place,
                     neighbors=neighbors, items=items, bag=bag)
                    )
        # Špatný argument
        steps.append(ScenarioStep(typeOfStep=tsNS1_WRONG_ARG,
                     command=ACTION + ' ' + ACTION,
                     message=MSG_0, place=place,
                     neighbors=neighbors, items=items, bag=bag,
                     needs={ARG:not ARG_VAL})
                    )
        # Správný argument
        steps.append(ScenarioStep(typeOfStep = tsNS_1,
                     command = ACTION + ' ' + ARG_1,
                     message = MSG_1,       place = place,
                     neighbors=neighbors,   items=items,
                     bag   = (bag := bag + (ITEM,)),
                     needs = {FLAG_1 : VAL_1},
                     sets  = {FLAG_1 : not VAL_1})
                    )
        # Týž argument, nyní už špatný
        steps.append(ScenarioStep(typeOfStep = tsNS1_WrongCond,
                     command  = ACTION + ' ' + ARG_1,
                     message  = MSG_0,    place = place,
                     neighbors=neighbors, items=items, bag=bag,
                     needs = {FLAG_1 : VAL_1})
                    )
        # Zbytek scénáře MISTAKE
        for step in mistake[2:]:
            steps.append(ScenarioStep(typeOfStep = step.typeOfStep,
                         command  = step.command,
                         message  = step.message,
                         place    = step.place,
                         neighbors= step.neighbors,
                         items    = step.items,
                         bag      = step.bag + (ITEM, ),
                         needs    = step.needs,
                         sets     = step.sets)
                        )
        result = Scenario(stMISTAKES, steps)
        prVb(Verbosity.STEPS, result.string())
        return result


    def prepare_MISTAKES_NS(self) -> Scenario:
        """ Vhodnou modifikací původního MISTAKES_NS scénáře vytvoří
        jeho ekvivalent pro upravenou hru.
        """
        mis_ns = self.org_name2scenario[MISTAKE_NS_NAME].steps
        steps   = [self.start] + [step for step in mis_ns[1:]]
        result  = Scenario(stGENERAL, steps, MISTAKE_NS_NAME)
        print (result)
        return result



###########################################################################q

def err0(reason:str) -> None:
    """
    Chyba odhalená před tím, než se začnou procházet kroky scénáře.
    
    :param reason:
    :return:
    """
    msg = f'\n{reason}\n'
    print(msg)
    raise Exception(msg)


def err1(reason:str, expected:ScenarioStep, obtained:ScenarioStep) -> None:
    """
    Chyba odhalená při procházení kroků scénáře před spuštěním hry.
    
    :param reason:
    :param expected:
    :param obtained:
    :return:
    """
    msg = (f'\n{expected.index}'
           f'. krok testovacího scénáře neodpovídá požadavkům - {reason}:\n'
           f'Očekáván krok typu {expected.typeOfStep}:\n{expected}\n\n'
           f'Obdržen krok typu {obtained.typeOfStep}:\n{obtained}\n')
    print(msg)
    raise Exception('Krok testovacího scénáře neodpovídá požadavkům')



###########################################################################q

def test(portal: 'IPkgInitor'):
    from game.tests.test_interface  import test as ti
    ti(portal, Level.EXTENDED, VisitorPermit)



###########################################################################q
dbg.stop_pkg(1, __name__)
