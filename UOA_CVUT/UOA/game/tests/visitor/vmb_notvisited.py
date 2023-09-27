#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
"""
Modul definuje třídu `Visitor_NotVisited`, jejíž instance testují
správné zapracování modifikace požadující následující úpravu
původního programu:

Na konec každé zprávy vypisované jako odpověď hry na zadání příkazu
přidat řádek s textem:

§Dosud nenavštíveno: ['name1', 'name2', 'name3', ..., 'nameN']

kde v hranatých závorkách bude uveden abecedně seřazený seznam
čárkami oddělených a na malá písmena převedených názvů prostorů,
které hráč během aktuální hry ještě nenavštívil.
Názvy name1, name2 atd. ve výše  uvedeném textu
zastupují názvy prostorů testované hry.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

from game.api.interfaces        import IPkgInitor, IGame, INamed
from game.api.scenario          import Scenario, ScenarioStep
from game.tests                 import Level, test_scenario
from game.tests.common.errors   import error
from game.tests.common.texts    import *
from game.tests.common.utils    import containers_differs
from game.tests.visitor         import Visitor
from game.api.scen_types import tsSTART, tsEMPTY, tsNOT_START, tsUNKNOWN



###########################################################################q

class Visitor_NotVisited(Visitor):
    """
    Třída návštěvníků kontrolujících modifikaci původní hry
    pomáhá kontrolovat správnost řešení popsaného v dokumentaci modulu.
    """

    def __init__(self, portal:IPkgInitor, level:Level):
        super().__init__(portal, level)
        self.not_visited = []


    @staticmethod
    def are_imperfect_scenarios_allowed(self) -> None:
        """Vrátí informaci o tom, je-li v prověřovaném zadání povoleno
        testování hry i v případě, kdy správce scénářů neprojde verifikací.
        """
        return False


    # @dbg.prSEd()
    def before_game_start(self, scenario:Scenario) -> None:
        """
        Akce, která se má provést před spuštěním hry.
        Cílem metody je prověřit scénáře a případné další pomocné kódy.

        :param scenario: Scénář, podle nějž se hra testuje
        """
        self.scenario = scenario


    # @dbg.prSEd()
    def after_game_start(self, scenario:Scenario) -> None:
        """
        Akce, která se má provést po provedení startovacího kroku hry
        (tj. ve chvíli, kde je hra již inicializována), ale před jeho testem,
        tj. před ověřením, že stav hry odpovídá scénáři.
        Cílem metody je připravit potřebné informace o testované hře.
        
        :param scenario: Scénář, podle nějž se hra testuje
        """
        # Porovná úvodní hlášení hry se situací odvozenou ze scénářů
        if len(self.portal.AUTHOR_ID) > 4:  # Ne pro demonstrační programy
            verify_no_ck(self.game, self.game.world())

        # dbg.prIN(1, f'{self.game.all_actions() = }')
        if containers_differs(test_scenario._all_mentioned_places,
                              self.game.world().places()):
            error('Seznam prostorů hry', scenario, scenario.steps[0],
                  self.game, containers_differs.from_scenario,
                             containers_differs.from_game)
        # Nastaví výchozí stav potřebných proměnných
        self.not_visited = containers_differs.from_game
        self.not_visited.remove(self.game.world()
                                    .current_place().name.lower())


    # @dbg.prSEd()
    def before_entering_command(self, step:ScenarioStep) -> None:
        """
        Akce, která se má provést před zadáním příkazu hře.
        Používá se zřídka. Při její definici je třeba vzít v úvahu, že se
        u startovacího kroku provede ještě před odstartováním hry,
        tj. před metodami `before_game_start` a `after_game_start`.

        :param step: Aktuálně prověřovaný krok scénáře
        """


    # @dbg.prSEd()
    def before_step_test(self, step:ScenarioStep, answer:str) -> None:
        """
        Akce, která se má provést po provedení kroku hry, ale před jeho
        testem, tj. před ověřením, že stav hry odpovídá scénáři.
        
        :param step:    Aktuálně prověřovaný krok scénáře
        :param answer:  Odpověď hry na zadání příkazu
        """


    # @dbg.prSEd()
    def after_step_test(self, step:ScenarioStep, answer:str) -> None:
        """
        Akce, která se má provést po testu aktuálního kroku.
        
        :param step:   Aktuálně prověřovaný krok scénáře
        :param answer: Odpověď hry na zadání příkazu
        """
        if step.typeOfStep == tsNOT_START:
            return
        # Aktualizuje  potřebné proměnné
        current_place_name = self.game.world().current_place().name.lower()
        if current_place_name in self.not_visited:
            self.not_visited.remove(current_place_name)
        # Najde a zkontroluje poslední řádek
        parts  = answer.split('\n')
        last_line = parts[-1]
        if not last_line.startswith(START):
            error('Závěrečný řádek nemá požadovaný začátek',
                  self.scenario, step, self.game, START, last_line)
        required = str(self.not_visited)
        obtained = last_line[len(START):].lower()
        # dbg.prIN(1, f'{current_place_name = }\n{required = }\n{obtained = }')
        if required != obtained:
            error('Seznamy nenavštívených prostorů si neodpovídají',
                  self.scenario, step, self.game, required, obtained)



    # @dbg.prSEd()
    def after_game_end(self, verbose_message:str='',
              exception:Exception=None, summary:'GameSummary'=None) -> None:
        """
        Akce, která se má provést po testu posledního kroku.
        
        :param verbose_message: Kompletní zpráva o průběhu testu
        :param exception:       Případná vyhazovaná výjimka
        :param summary:         Přepravka s informacemi o předpokládaném
                                průběhu hry podle scénářů
        """


    def __repr__(self) -> str:
        """
        Systémový podpis instance -- vrátí název třídy
        a autora testované aplikace.
        """
        return f'{self.__class__.__module__}.{self.__class__.__name__}(' \
               f'{self.portal.__name__})'



###########################################################################q

# @dbg.prSEda()
def verify_no_ck(*modules):
    """
    Prověří, že názvy zadaných modulů nezačínají 'ck_'.
    
    :param modules: Moduly, jejichž názvy se budou prověřovat
    """
    CK = 'ck_'
    for module in modules:
        if module.__name__.lower().startswith(CK):
            reason = 'Názvy modulů nebyly zbaveny předpony `ck_`'
            print(f'\n{N_EXCLAM_N}CHYBA:\n{reason}{N_EXCLAM_N}')
            raise Exception(f'{reason}')



###########################################################################q

# TEST_ID     = "21w12"
NO_COMMAND  = {tsSTART, tsEMPTY, tsNOT_START, tsUNKNOWN, }
START       = "§Dosud nenavštíveno: "



###########################################################################q
dbg.stop_mod(1, __name__)
