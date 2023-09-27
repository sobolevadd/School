# Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tests/test_scenario.py
"""
Sada tříd a funkcí pro otestování korektnosti definic scénářů.
"""
import dbg
dbg.start_mod(0, __name__)
############################################################################

from collections import namedtuple

from ..api              import BasicActions
from ..api.interfaces   import IPkgInitor
from ..api.scen_types   import *
from ..api.scenario     import ScenarioStep, Scenario
from .common.texts      import *
from  .                 import Level, Verbosity, prVb



############################################################################

# Maximální povolené délka zalamovaných výstupních řádků
MAX_LINE_LENGTH = 80

# Počet scénářů, které se mají povinně zadávat
REQUESTED = 4


############################################################################
# @dbg.prSEd()
def test_scenarios_from(portal:IPkgInitor, LID:Level=99) -> str:
    """Otestuje scénáře v zadaném balíčku podle LID=Level ID.
    Při (LID == 1 == Level.HAPPY) se testuje pouze scénář HAPPY.
    Při (LID >= 2 == Level.SCENARIOS)  a vyšším se testují všechny
    scénáře, ale přinejmenším povinnou čtveřici pro hladinu BASIC.
    """
    if LID <= 0:
        _ERR('Metoda game.tests.test_scenario vyžaduje '
             'druhý argument kladný', steps=0)
    global _LID, _portal, _scenarios
    _LID = LID
    _portal = portal
    # dbg.prIN(1, f'{_LID = },   Author = {_portal.AUTHOR_NATIVE_NAME}')
    n2s = portal.NAME_2_SCENARIO
    if not isinstance(n2s, dict):
        n2s = n2s()
    fas = n2s.values()
    num = len(fas)
    req = REQUESTED if LID >= 2 else 1
    if num < req:
        _ERR(f'Metoda game.tests.test_scenario vyžaduje dodání nejméně\n'
             f'{req} scénářů, ale bylo poskytnuto jen {num}.')
    ok = True
    clear_extended_types()  # Vyčistí množiny rozšiřujících typů,
                            # protože jsou vázány na konkrétní řešení
    # Připraví n-tici scénářů, které se budou testovat
    _scenarios = tuple(fas)
    happy      = _scenarios[0]
    for i in range(num):
        if _scenarios[i].type.ordinal != i:
            _ERR(f'Typ scénáře neodpovídá jeho pořadí:\n'
                 f'    Pořadí: {i}\n'
                 f'    Požadováno: {TypeOfScenario.get()}\n'
                 f'    Obdrženo:   {_scenarios[i].type}')

    _initialize_for_all()
    results = [(scenario.name + ' - ' + str(_test_scenario(scenario)))
               for scenario in _scenarios]
    msg = '\n'.join(results)
    global BASIC_ACTIONS
    BASIC_ACTIONS = _derive_basic_actions()
    global ALL_ACTIONS
    ALL_ACTIONS   = _all_entered_actions
    name = portal.AUTHOR_NAME
    try:
        name = portal.AUTHOR_NATIVE_NAME
    except Exception:
        name = name + ' - Nebylo zadáno jméno v rodném jazyce'
    print(f'{N_EXCLAM_N}{portal.__name__} - {name}\n'
          f'Testy scénářů dopadly následovně:\n{msg}\n{30*"="}')
    return results

    # end_step   = happy.steps[-1]
    # ss = ScenariosSummary(_portal, ok,
    #     _all_mentioned_places, _all_entered_actions, _all_seen_items,
    #     _start_step, end_step, _derive_basic_actions(),
    #     _ns_actions_by_args, _scenarios, results
    # )
    # return ss


############################################################################
#
# class ScenariosSummary:
#     """Třída fungující jako přepravka uchovávající souhrnné informace
#     vyčtené z prověřovaných scénářů:
#     ok      - Informace o tom, zda jsou prověřované scénáře bez chyb
#     mentioned_places - Množina názvů všech dosud zmíněných prostorů
#     entered_actions  - Množina názvů všech doposud zadaných akcí
#     seen_items       - Množina názvů všech dosud zahlédnutých objektů
#     start_step       - Počáteční krok v základním úspěšném scénáři
#     end_step         - Poslední krok základního úspěšného scénáře
#     basic_actions    - Přepravka s názvy základních (povinných) akcí
#     ns_actions       - Seznam seznamů názvů nestandardních akcí
#     name2type_group  - Slovník mapující názvy akcí na skupinu jejich typů
#     scenarios        - Seznam prověřovaných scénářů
#     results          - Výsledky prověření jednotlivých scénářů
#     """
#     def __init__(self,
#                  portal          : IPkgInitor,
#                  ok               : bool     = None,
#                  mentioned_places : set[str] = None,
#                  entered_actions  : set[str] = None,
#                  seen_items       : set[str] = None,
#                  start_step       : ScenarioStep         = None,
#                  end_step         : ScenarioStep         = None,
#                  basic_actions    : BasicActions         = None,
#                  ns_actions       : list[list[str]]      = None,
#                  name2type_group  : dict[str:TypeOfStep] = None,
#                  scenarios        : tuple[Scenario]      = None,
#                  results          : list[bool]           = None
#         ):
#         """Vytvoří požadovanou přepravku, avšak počítá se s tím,
#         že většina hodnot atributů bude zadávána až dodatečně,
#         takže tělo initoru skoro nic doopravdy nenaplní, jenom zařídí,
#         že příslušné atributy jsou již vytvořeny.
#         """
#         self.author = f'{portal.AUTHOR_ID} - {portal.AUTHOR_NAME}'
#         self.portal          : IPkgInitor             = portal
#         self.ok               : bool                 = None
#         self.mentioned_places : set[str]             = None
#         self.entered_actions  : set[str]             = None
#         self.seen_items       : set[str]             = None
#         self.start_step       : ScenarioStep         = None
#         self.end_step         : ScenarioStep         = None
#         self.basic_actions    : BasicActions         = None
#         self.ns_actions       : list[list[str]]      = None
#         self.name2type_group  : dict[str:TypeOfStep] = None
#         self.scenarios        : tuple[Scenario]      = None
#         self.results          : list[bool]           = None
#
#
#     def __repr__(self) -> str:
#         S = "+++ PROŠLY +++" if self.ok else "!!! NEPROŠLY !!!"
#         r =(_pil('Hra autora: ', self.author)
#             + _pil('Scénáře               ', S)
#             + _pil('Zmíněné prostory      ', self.mentioned_places)
#             + _pil('Zadané akce:          ', self.entered_actions)
#             + _pil('Viděné h-objekty:     ', self.seen_items)
#             + _pil('Názvy povinných akcí: ', self.basic_actions)
#             + _pil('Nepovinné akce:       ', self.ns_actions)
#             + _pil('Název_akce -> typ:    ', self.name2type_group)
#             + _pil('Kontrolované scénáře: ', self.scenarios)
#             + _pil('Výsledky testů:       ', self.results)
#             + '\nPočáteční krok:\n' + self.start_step
#             + '\nKoncový krok šťastného scénáře:\n' + self.end_step
#             )
#         return r
#
#
#
############################################################################

_Names = namedtuple('_Names', 'type last current')


def _neighbors() -> _Names:
    """Vrátí dvojici n-tic s názvy sousedů v minulém a aktuálním kroku.
    """
    return _Names('neighbors',
                  _previous_step.neighbors, _current_step.neighbors)


def _items() -> _Names:
    """Vrátí dvojici n-tic s názvy objektů v aktuálním prostoru
    v minulém a aktuálním kroku.
    """
    return _Names('items', _previous_step.items, _current_step.items)


def _bag() -> _Names:
    """Vrátí dvojici n-tic s obsahem batohu v minulém a aktuálním kroku.
    """
    return _Names('bag', _previous_step.bag, _current_step.bag)


############################################################################

def _ERR(message: str, *, steps: int = 1) -> None:
    """Vypíše chybovou zprávu a vyvolá výjimku.
    Argument steps určuje počet zobrazovaných kroků následovně:
    0 - Jenom zpráva, žádný testovací krok se netiskne
    1 - Tiskne se pouze aktuálně testovaný krok
    2 - Tiskne se předchozí krok a aktuálně testovaný krok.
    """
    print(f'{N_HASH_N}CHYBA: {message}\n')
    if steps >= 2:
        print(f'Předchozí krok:\n{_previous_step}')
    if steps >= 1:
        print(f'Aktuální krok:\n{_current_step}')
    print(HASH_N)
    raise Exception(message)


############################################################################

def _initialize_for_all() -> None:
    """Inicializuje souhrnné kontejnery přes všechny testy.
    """
    global _all_entered_actions;    _all_entered_actions    = set()
    global _all_mentioned_places;   _all_mentioned_places   = set()
    global _all_seen_items;         _all_seen_items         = set()
    global _all_bag_items;          _all_bag_items          = set()
    global _entered_ns_actions;     _entered_ns_actions     = set()

    global _action_2_group;         _action_2_group = {}
    global _group_2_action;         _group_2_action = {}

    global _happy_tested;           _happy_tested = False
    # global _scenarios             = Již inicializované
    global _start_step;             _start_step = _scenarios[0].steps[0]


def _derive_basic_actions():
    """Z hodnot uložených ve slovníku odvodí názvy povinných akcí.
    """
    move = _group_2_action.get(tsGOTO,      "NEPŘIŘAZENO")
    take = _group_2_action.get(tsTAKE,      "NEPŘIŘAZENO")
    put  = _group_2_action.get(tsPUT_DOWN,  "NEPŘIŘAZENO")
    help = _group_2_action.get(tsHELP,      "NEPŘIŘAZENO")
    end  = _group_2_action.get(tsEND,       "NEPŘIŘAZENO")

    result = BasicActions(MOVE_NAME=move, PUT_DOWN_NAME=put,
                          TAKE_NAME=take, HELP_NAME=help, END_NAME=end)
    return result


# @dbg.prSEda()
def _test_scenario(scenario: Scenario) -> bool:
    """Prověří zadaný scénář, zapíše výsledek na standardní výstup
    a vrátí logickou hodnotu oznamující, zda scénář úspěšně prošel testem.
    Během testu zaznamenává souhrnné údaje pro ScenariosSummary
    """
    global _scenario_in_test
    _scenario_in_test = scenario
    _initialize()
    if stDEMO == scenario.type:
        """Verifikovat demo-scénář"""
    else:
        _verify_testable_scenario()
    # Šťastný scénář musí být vždy testován jako první,
    # takže následující příkaz bude platit i po každém dalším testu
    global _happy_tested
    _happy_tested = True
    _finalize()
    return _scenario_OK


# ===========================================================================

def _initialize() -> None:
    """Inicializuje globální proměnné používané v testu jednoho scénáře
    a vypíše zprávu o zahájení testu daného scénáře.
    """
    # Příkazy jsou seřazeny dle abecedy, aby se to snáze kontrolovalo
    global _entered_actions;        _entered_actions = set()
    global _finished;               _finished = True
    global _mentioned_places;       _mentioned_places = set()
    global _not_used_action_types;  _not_used_action_types = set(ALL_TYPES)
    global _ns_actions_by_args;     _ns_actions_by_args = (
                                        set(), set(), set(), set())
    global _num_of_step;            _num_of_step    = 0
    global _previous_step;          _previous_step  = None
    global _scenario_OK;            _scenario_OK    = True
    global _seen_items;             _seen_items     = set()
    global _bag_items;              _bag_items      = set()
    global _visited_places;         _visited_places = set()
    global _conditions;             _conditions     = {}

    print(f'{N_HASH_N}'
          f'Scenario: {_scenario_in_test.name}'
          f'{N_DOUBLE}')


# @dbg.prSEd()
def _finalize() -> None:
    """Provede závěrečný úklid.
    """

    def verify_completeness(step_types: set[TypeOfScenario]):
        """Vrátí typy kroků, které nebyly použité, přestože použité být měly.
        """
        not_used = set(step_types)
        for step in _scenario_in_test.steps:
            not_used.discard(step.typeOfStep)
        return not_used

    def notUsedNSTypes():
        """Vrátí typy NS kroků, které nebyly použité ve scénář MISTAKES_NS.
        """
        not_used = {ts.name for ts in EXTEND_MISTAKES}
        for step in _scenario_in_test.steps:
            if step.typeOfStep.subtype == SubtypeOfStep.MISTAKE_NS:
                not_used.discard(step.command.split()[0].lower()
                                 + '_' + step.typeOfStep.name)
        return not_used

    scen_type = _scenario_in_test.type
    if scen_type == stHAPPY:
        not_used = verify_completeness(HAPPY_TYPES)
    elif scen_type == stMISTAKES:
        not_used = verify_completeness(MISTAKE_TYPES)
    elif scen_type == stMISTAKES_NS:
        not_used = notUsedNSTypes()
    else:
        not_used = set()

    global _all_mentioned_places, _mentioned_places, _visited_places
    _all_mentioned_places.update(_mentioned_places)
    _all_entered_actions .update(_entered_actions)
    _all_seen_items      .update(_seen_items)
    _all_bag_items       .update(_bag_items)

    not_visited = _mentioned_places - _visited_places
    _showResults(not_visited, not_used)


# @dbg.prSEd()
def _verify_testable_scenario() -> None:
    """Prověří aktuální scénář a připraví podklady pro zapsání výsledku.
    Při odhalení chyby vytiskne zprávu a nastaví atribut _scenario_OK na False.
    """
    global _scenario_in_test, _previous_step, _current_step
    start = True
    for step in _scenario_in_test.steps:
        _current_step = step
        if start:
            # Prověří nestartovní krok v chybové scénáři
            start = False
            _verify_wrong_start(step)
        if _verify_not_alive():
            break  # Falešně zadaný příkaz neběžící hře
        _process_step()
        _previous_step = _current_step


# ===========================================================================

def _check_nonstandard(name: str) -> None:
    """Při procházení šťastného scénáře zaeviduje použité nestandardní
    kroky a při procházení chybových scénářů dohlédne na to,
    aby nebyly zadány nové nestandardní kroky (pravděpodobně překlepem).
    """
    if (_scenario_in_test.type == stHAPPY) and (not _happy_tested):
        # Testujeme krok šťastného scénáře - v něm musejí být použity
        # všechny druhy nestandardních kroků - tak použité zaregistrujeme
        st  = _current_step.typeOfStep.subtype
        SOS = SubtypeOfStep
        if (st == SOS.NONSTANDARD)  or  (st == SOS.SUCCESS):
            if name not in _entered_ns_actions:
                _entered_ns_actions.add(name)
                # Ještě začlenit do skupin podle počtu argumentů
                index = _current_step.typeOfStep.group.arg_count
                _ns_actions_by_args[index].add(name)
    elif _scenario_in_test.type in (stMISTAKES, stMISTAKES_NS):
        # Jestli se v non-happy scénáři nepoužívá nová nestandardní akce
        subtype = _current_step.typeOfStep.subtype
        if (subtype in (SubtypeOfStep.NONSTANDARD,
                        SubtypeOfStep.MISTAKE_NS) and
                name not in _entered_ns_actions
        ):
            _ERR(f'Testujete {_scenario_in_test.type.description}\n'
                 f'V něm mohou být jen nestandardní akce použité '
                 f've šťastném scénáři.\n'
                 f'Zadali jste nepoužitou akci {name}', steps=1)


def _command_argument():
    """Vrátí argument zadaného jednoparametrického příkazu
    uloženého v globální proměnné _words_in_command.
    Není-li zadán, ohlásí chybu.
    """
    if len(_words_in_command) < 2:
        _ERR(f'Příkaz {_words_in_command[0]} vyžadující argument '
             f'byl zadán bez argumentů', steps=1)
        return ''
    return _words_in_command[1]


def _pil(text: str, data: object,
         container=True, limit: int = 79, end='\n') -> str:
    """Vrátí zadaný text a za ním obsah zadaného kontejneru,
    který zalomí tak, aby řádky nepřesáhly maximální povolenou délku
    a následující řádky byly odsazeny pod začátek prvního.
    """
    return dbg.prIndLim(text, data, container, limit, end)


# @dbg.prSEd()
def _record_step_info() -> None:
    """Zaznamená do "statistik" důležité objekty z tohoto kroku.
    """
    global _visited_places, _mentioned_places, _seen_items, _bag_items
    _visited_places.add(_current_step.place.lower())
    _mentioned_places.add(_current_step.place.lower())
    _mentioned_places.update([s.lower() for s in _current_step.neighbors])
    _seen_items.update([s.lower() for s in _current_step.items])
    _bag_items .update([s.lower() for s in _current_step.bag])
    # dbg.prIN(1, f'{_current_step.items = }\n'
    #             f'{_seen_items         = }\n'
    #             f'{_current_step.bag   = }\n'
    #             f'{_bag_items          = }' )


# @dbg.prSEdar()
def _satisfy(announced: int, required: int) -> str:
    """Zjišťuje, zda byl splněn požadovaný počet objektů daného typu.
    Používá se pro test počtu kroků, použitých příkazů,
    navštívených místností, zmíněných místností apod.
    Vrátí text oznamující nalezený počet objektů doplněný v případě
    nesplnění podmínky minimálním požadovaným počtem objektů.
    """
    global _scenario_OK
    # if _scenario_in_test.type != stHAPPY:
    #     return ''                           # ==========>
    # # Testuje se pouze u šťastného scénáře
    yes = announced >= required
    _scenario_OK = _scenario_OK and yes
    result = ('vyhovuje' if yes else
              f'!!! NEVYHOVUJE (min = {required})')
    return result


# @dbg.prSEd()
def _showResults(not_visited: set[str], absent: set[str]) -> None:
    """Zobrazí výsledky provedeného testu
    spolu se základní charakteristikou testovaného scénáře.
    """
    global _entered_actions, _mentioned_places, _mentioned_places
    global _not_used_action_types, _entered_ns_actions, _visited_places
    global _num_of_step, _entered_ns_actions
    global _visited_places, _entered_actions, _not_used_action_types
    global _seen_items, _bag_items
    num_absent = len(absent)
    num_entered = len(_entered_actions)
    num_mentioned = len(_mentioned_places)
    num_not_used = len(_not_used_action_types)
    num_own_actions = len(_entered_ns_actions)
    num_visited = len(_visited_places)

    from . import LIMITS
    happy_msg = ((
                         f'Počet kroků:           {_num_of_step:2} - '
                         f'{_satisfy(_num_of_step, LIMITS.minSteps)}\n'
                         + (
                             s1 := f'Nestandardních akcí:   {num_own_actions:2d} - ')
                         + _satisfy(num_own_actions,
                                    LIMITS.minNSActions) + '\n'
                         + _pil(len(s1) * ' ', _entered_ns_actions)
                         + (
                             s1 := f'Zmíněných prostorů:    {num_mentioned:2d} - ')
                         + _satisfy(num_mentioned, LIMITS.minPlaces) + '\n'
                         + _pil(len(s1) * ' ', str(_mentioned_places))
                         + (
                             s1 := f'Navštívených prostorů: {num_visited:2} - ')
                         + _satisfy(num_visited, LIMITS.minVisited) + '\n'
                         + _pil(len(s1) * ' ', str(_visited_places))
                         + _pil(
                     f'Zadaných akcí:         {num_entered:2} - ',
                     _entered_actions)
                         + (
                             s1 := f'Nezadaných povinných:  {num_absent:2} - ')
                         + _satisfy(0, num_absent) + '\n'
                         + _pil(len(s1) * ' ',
                                (absent if num_absent > 0 else '{}'))
                 ) if _scenario_in_test.type == stHAPPY else '')
    global _scenario_OK
    # _scenario_OK = _scenario_OK and (num_absent == 0)

    message = (
            '===== Souhrnná zpráva testu =====\n'
            + happy_msg
            + _pil(f'Nezadané typy kroků:   {num_not_used:2} - ',
                   sorted([t.name for t in _not_used_action_types]))
            + (s1 := f'Z toho povinných:      {num_absent:2} - ')
            + _satisfy(0, num_absent) + '\n'
            + _pil(len(s1) * ' ', (absent if num_absent > 0 else '{}'))
            + _pil(f'Viděné h-objekty:      ',
                   (_seen_items if len(_seen_items) > 0 else '{}'))
            + _pil(f'Prošedší batohem:      ',
                   (_bag_items  if len(_bag_items)  > 0 else '{}'))
            + _pil(f'Nenavštívené prostory: ',
                   (not_visited if len(not_visited) > 0 else '{}'))
            + '===== Provedený test: ' + _scenario_in_test.name
            + f'''\n===== Test {("prošel" if _scenario_OK
                                 else "NEPROŠEL")}{N_HASH_N}'''
    )
    print(message)


def _verify_array_content(array: tuple[str], text: str,
                          should_contain: bool):
    """Zjistí, zda zadané pole textů array obsahuje/neobsahuje zadaný text,
    přičemž argument should_contain určuje, zda požadujeme přítomnost
    (True) či nepřítomnost (False) zadaného textu.
    """
    found = False
    txt = text.lower()
    for s in array:
        if s.lower() == txt:
            found = True
            break
    return found == should_contain


def _verify_wrong_start(step: ScenarioStep) -> None:
    """Ověří, že chybový scénář začíná správným startovním krokem
    a odebere jeho typ kroku z nepoužitých.
    """
    if (stMISTAKES == _scenario_in_test.type and
            step.typeOfStep != tsNOT_START
    ):
        _ERR('Chybový scénář musí začínat testem definujícím reakci \n'
             'na chybně zadaný nestartovní (= neprázdný) příkaz \n'
             f'zadaný neběžící hře: {_current_step}', steps=1)
    else:  # Odeber tuto akci z dosud nerealizovaných
        _not_used_action_types.remove(tsNOT_START)


############################################################################

# @dbg.prSEd()
def _process_step() -> None:
    """Zpracuje aktuální krok scénáře v atributu _current_step.
    """
    global _previous_step, _current_step, _num_of_step, _words_in_command
    # Vytiskne index, typ a příkaz testovaného kroku
    current_tos = _current_step.typeOfStep
    msg = (f'{_current_step.index:-2}. {str(current_tos):18}'
           f'- {_current_step.command}')
    print(msg)
    _not_used_action_types.discard(current_tos) # Aktuální typ byl použit

    # Nelze testovat stav nespuštěné hry
    if current_tos == tsNOT_START: return  # ==========>

    _num_of_step += 1
    # Zda se jedná o modifikační krok v některých obhajobách
    modifiedStep: bool = (current_tos.subtype == SubtypeOfStep.MODIFIED)
    _words_in_command = _current_step.command.split()
    if (not modifiedStep and (len(_words_in_command) > 0) and
            (_current_step.typeOfStep not in {tsDIALOG, tsUNKNOWN})
    ):  # Byl zadán některý z nestartovních a nemodifikačních příkazů
        name = _words_in_command[0].lower()
        _entered_actions.add(name)
        _check_nonstandard(name)
    check_message_length(f'zprávy v {_current_step.index}. kroku',
                         _current_step.message)
    _record_step_info()
    if not modifiedStep:
        # _check_step(_current_step.typeOfStep) # Pomocná náhrada - viz dále
        _tos_2_handle[_current_step.typeOfStep]()
    _previous_step = _current_step

# @dbg.prSEdar()
# def _check_step(tos:TypeOfStep) -> TypeOfStep:
#     """Spustí funkci prověřující korektnost kroku zadaného typu.
#     Slouží jen jako pomocná náhrada přímého volání při ladění.
#     """
#     _tos_2_handle[tos]()
#     return tos


############################################################################

# @dbg.prSEda()
def _assign_group(lower_name, group_of_step):
    """Přiřadí zadanou akci skupině typů kroků, přičemž v případě
    nestandardních kroků tuto skupinu nejprve vytvoří.
    """
    # Pro danou akci ještě ještě nebyla zadána skupinu typů kroků
    if group_of_step.subtype == SubtypeOfStep.NONSTANDARD:
        # U nestandardních je to složitější, protože skupina musí
        # obsahovat i název sdružené akce - bude se vytvářet ve scen_types
        group_of_step = create_extended_types_for(lower_name, group_of_step)
    else:
        if rival := _group_2_action.get(group_of_step):
            # Daná skupina se již k někomu hlásí
            _ERR(f'Skupina {group_of_step} již byla přidělena '
                 f'akci {rival}\n'
                 f'    nyní se pokoušíte použít akci {lower_name}')
    # Daná skupina ještě není zavedena
    _action_2_group[lower_name] = group_of_step
    _group_2_action[group_of_step] = lower_name


def _verify_absence(pair: _Names, absent: str, now_less: bool) -> None:
    """Ověří, že se texty v zadaných polích v minulém a tomto zkušebním
    kroku shodují s výjimkou zadaného názvu, který v jedné verzi chybí.
    """
    last = sorted([s.lower() for s in pair.last])
    current = sorted([s.lower() for s in pair.current])
    absentl = absent.lower()
    smaller = current if now_less else last
    bigger = last if now_less else current
    try:
        if len(bigger) - (LS := len(smaller)) != 1:
            raise Exception  # ##########>
        else:
            for i in range(LS): bigger.remove(smaller[i])
            if (absentl != bigger[0]):
                raise Exception  # ##########>
    except:
        diff = 'chybět' if now_less else 'přibýt'
        _ERR(f'Rozdíly v seznamech objektů typu {pair.type} mezi minulým '
             f'a tímto krokem\n'
             f'neodpovídají akci typu {_current_step.typeOfStep}\n'
             f'Má {diff} objekt {absent}\n'
             f'Minule: {pair.last}\n'
             f'Nyní:   {pair.current}', steps=2)


def _verify_action_name():
    """Ověří, že název právě ohlášené akce je stejného typu jako doposud
    zadané akce se stejným názvem a jedná-li se o první výskyt akce
    s daným názvem, přidá jej do seznamu názvů spolu s typem kroku
    pro kontroly konzistence akcí zadaných v budoucnu.
    """
    global _action_2_group, _group_2_action
    type_of_step = _current_step.typeOfStep
    if type_of_step == tsUNKNOWN:
        # Neznámé akci je nesmysl přiřazovat skupinu typů
        # Akce tsNOT_START se sem ani neprobojuje
        return
    group_of_step = type_of_step.group
    if len(_words_in_command) > 0:
        action_name = _words_in_command[0]
    elif type_of_step == tsEMPTY:
        action_name = ''
    else:
        _ERR(
            f'Prázdný příkaz není možno zadat jako akci typu {type_of_step}')
    lower_name = action_name.lower()
    action_group = _action_2_group.get(lower_name)
    # Byla-li akci přidělena skupina, předpokládám, že v rámci toho byla
    # skupině přidělena správná akce => už to nekontroluju
    if not action_group:
        # Akci ještě nebyla přidělena skupina typů kroků
        _assign_group(lower_name, group_of_step)


def _verify_argument_in_answer():
    """Ověří, že zpráva končí zadaným argumentem.
    """
    if _current_step.typeOfStep not in (tsTAKE, tsPUT_DOWN, tsNS_1):
        return
    argument = _words_in_command[1].lower()
    if _current_step.message.lower().endswith(argument):
        return
    _ERR(f'Zpráva hry nekončí názvem argumentu {_words_in_command[1]}')


def _verify_equal_containers(*pairs: _Names):
    """Ověří, že se texty v zadaných polích (názvy pojmenovaných objektů)
    v minulém a tomto testovacím kroku shodují
    (např. že se při přechodu do jiného prostoru nezměnil stav batohu).
    """
    for pair in pairs:
        last = sorted([s.lower() for s in pair.last])
        current = sorted([s.lower() for s in pair.current])
        equals = True
        if len(last) != len(current):
            equals = False
        else:
            for i in range(len(current)):
                if last[i] != current[i]:
                    equals = False
                    break  # ---------->
        if equals:
            return  # ==========>

        _ERR(f'Seznamy objektů v poli {pair.type} v minulém a tomto kroku '
             f'si neodpovídají.\nMinule: {last}\nNyní:   {current}',
             steps=2)


def _verify_equality_of_all_fields():
    """Ověří, že se v minulém a tomto testovacím kroku shoduje
    aktuální prostor a s ním i názvy v polích reprezentujících
    sousedy prostoru, předměty v prostoru a obsah batohu.
    """
    _verify_same_place()
    _verify_equal_containers(_neighbors(), _items(), _bag())


# @dbg.prSEd()
def _verify_needs():
    """Ověří splnění očekávaného nastavení podmínek.
    """
    expects = _current_step.needs   # Nastavení očekávané v daném kroku
    current = _conditions           # Aktuální stav příznaků
    # dbg.prIN(1, f'{expects=}\n{current=}')
    if not expects:
        _ERR(f'Krok nemá zadány očekávané příznaky',
             steps=1)
    for key in expects:
        if key == 'conditions':
            # TODO Zapracovat vyhodnocení podmínky
            ...
        elif not (key in current):
            _ERR(f'Očekávaný příznak neexistuje.\n'
                 f'Očekáváno: {key}\n'
                 f'Nastaveno: {[x for x in current]}',
                 steps=1)
        elif current[key] != expects[key]:
            _ERR(f'Zadaný příznak nemá očekávanou hodnotu.\n'
                 f'Očekáváno: {key} : {expects[key]}\n'
                 f'Nastaveno: {key} : {current[key]}',
                 steps=1)


# @dbg.prSEd()
def _verify_needs_wrong_cond():
    """Ověří splnění očekávaného nastavení podmínek.
    """
    expects = _current_step.needs   # Nastavení očekávané v daném kroku
    current = _conditions           # Aktuální stav příznaků
    if not expects:
        _ERR(f'Krok nemá zadány očekávané příznaky',
             steps=1)
    result = False
    for key in expects:
        if key == 'conditions':
            # TODO Zapracovat vyhodnocení podmínky
            ...
        elif not (key in current):
            _ERR(f'Očekávaný příznak neexistuje.\n'
                 f'Očekáváno: {key}\n'
                 f'Nastaveno: {[x for x in current]}',
                 steps=1)
    # Ověří, že alespoň jedna podmínka není splněna
    for key in expects:
        if key == 'conditions':
            # TODO Zapracovat vyhodnocení podmínky
            return
        elif current[key] != expects[key]:
            return
    else:
        _ERR(f'Všechny očekávané podmínky byly splněny,\n'
             f'Nebyl proto důvod k ohlášení chyby.\n'
             f'Očekáváno: {expects}\n'
             f'Nastaveno: {current}',
             steps=1)


# @dbg.prSEd()
def _verify_no_needs_sets():
    """Ověří, že daný krok neočekává ani nenastavuje žádné podmínky.
    """
    needs = _current_step.needs   # Nastavení očekávané v daném kroku
    sets  = _current_step.sets    # Nastavení nastavované v daném kroku
    if needs:
        _ERR('V daném kroku se nemá očekávat splnění nějakých podmínek')
    if sets:
        _ERR('V daném kroku se nemají nastavovat hodnoty podmínek')


def _verify_not_alive() -> None:
    """Ověří, že byl-li zadán nestartovní příkaz, tak hra již běžela.
    Nastala-li chyba, vrátí True, jinak vrátí False.
    """
    if (_finished and
            not ((tsSTART == _current_step.typeOfStep) or
                 (tsNOT_START == _current_step.typeOfStep))
    ):
        _ERR('Zadaný krok scénáře je před začátkem nebo  za koncem hry\n'
             'tj. hra ještě není odstartovaná anebo je již ukončená'
             f'{_current_step}', steps=1)


# @dbg.prSEd()
def _verify_not_in_happy(action_type:str):
    """Ověří, že příkaz nebyl zadán ve šťastném scénáři.
    """
    print(f'Testuje se konec:\n{_scenario_in_test=}\n{_scenarios[0]}')
    if _scenario_in_test == _scenarios[0]:
        _ERR(f'Příkaz aktivující {action_type} je zadán ve šťastném scénáři.')


def _verify_ns_action(action_name: str, lower_name: str,
                      group_of_step: TypeOfStep):
    """Ověří, jak je to se skupinou typů pro danou akci,
    a v případě potřeby ji vyrobí.
    """
    _entered_ns_actions.add(lower_name)


def _verify_number_of_arguments():
    """Ověří, že počet argumentů zadaných v příkazu odpovídá typu kroku.
    """
    ags_num = _current_step.typeOfStep.arg_count
    if (na := len(_words_in_command) - 1) != ags_num:
        _ERR(f'Požadovaný počet argumentů je {ags_num}, '
             f'avšak příkaz má {na} argumentů')
    if na == 1:
        _verify_argument_in_answer()


def _verify_place_reached():
    """Ověří, že po vykonání příkazu hráč skončil v prostoru,
    který byl zadán jako argument.
    """
    place = _command_argument()
    if place.lower() != _current_step.place.lower():
        _ERR('Hráč se nepřesunul do prostoru zadaného v příkazu.', steps=2)


def _verify_same_place():
    """Ověří, že po vykonání příkazu hráč skončil v prostoru,
    který byl zadán jako argument.
    """
    global _previous_step, _current_step
    if _previous_step.place.lower() != _current_step.place.lower():
        _ERR('Při vykonávání tohoto příkazu se nesmí změnit '
             'aktuální prostor.', steps=2)


def _verify_sets():
    """Ověří splnění očekávaného nastavení podmínek. """
    sets    = _current_step.sets   # Očekávané nastavování v daném kroku
    current = _conditions          # Aktuální stav příznaků
    if not sets:
        _ERR(f'Příkaz nemá zadány nastavované příznaky',
             steps=1)
    for key in sets:
        if not (key in current):
            _ERR(f'Očekávaný příznak neexistuje.\n'
                 f'Očekáváno: {key}\n'
                 f'Nastaveno: {[x for x in current]}',
                 steps=1)
        current[key] = sets[key]
        if current[key] != sets[key]:
            _ERR(f'Zadaný příznak nemá očekávanou hodnotu.\n'
                 f'Očekáváno: {key} : {sets[key]}\n'
                 f'Nastaveno: {key} : {current[key]}',
                 steps=1)


############################################################################

def _verifyType_BAD_ITEM() -> None:
    """Ověří, že byl zadána příkaz pro zvednutí objektu,
    že v aktuálním prostoru už zadaný objekt doopravdy není, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()
    _verify_number_of_arguments()
    if _verify_array_content(_current_step.items,
                             obj := _command_argument(), True):
        _ERR(f'Objekt {obj} v aktuálním prostoru zůstal.', steps=2)


def _verifyType_BAD_NEIGHBOR() -> None:
    """Ověří plán reakce hry na pokus přejít do prostoru,
    který v daném okamžiku není sousedem aktuálního prostoru, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()
    _verify_number_of_arguments()
    if _verify_array_content(_current_step.neighbors,
                             obj := _command_argument(), True):
        _ERR(f'Souseda {obj} aktuální prostor měl.', steps=2)


def _verifyType_BAG_FULL() -> None:
    """Ověří plán reakce na pokus zvednout předmět v situaci,
    kdy je batoh již plný a současně ověří, že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()
    _verify_number_of_arguments()


def _verifyType_DEMO() -> None:
    """Ohlásí chybu, protože demonstrační typ kroku
    se v testovacím scénáři nesmí objevit.
    """
    _ERR('Demonstrační typ kroku nepatří do testovacího scénáře', steps=1)


def _verifyType_DIALOG() -> None:
    """Všechny kontroly tohoto typu kroku již byl provedeny.
    """


def _verifyType_EMPTY() -> None:
    """Ověří korektnost zadání, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()


def _verifyType_END() -> None:
    """Nastaví příznak konce, aby bylo možno ověřit, že zadaný krok testu
    je skutečně poslední (každý další krok by způsobil chybu), a ověří, že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()
    _verify_not_in_happy('předčasné ukončení')
    _finished = True


def _verifyType_GOTO() -> None:
    """Ověří naplánování reakce na přesun hráče z prostoru do prostoru.
    Při zpracování příkazu se nesmí změnit obsah batohu.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_place_reached()
    _verify_equal_containers(_bag())


def _verifyType_GOTO_WA() -> None:
    """Ověří naplánovanou reakci na příkaz k přesunu do jiného prostoru
    zadaný bez argumentu. Přitom současně ověří, že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_HELP() -> None:
    """Ověří, že při žádosti o nápovědu
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()
    _verify_not_in_happy('nápovědu')


# @dbg.prSEd()
def _verifyType_NON_STANDARDx() -> None:
    """Ověří, že tuto akci lze konzistentně zařadit mezi nestandardní,
    a že příkaz má požadovaný počet argumentů.
    """
    _verify_action_name()
    _verify_number_of_arguments()
    # dbg.prIN(1, f'{_LID = }')
    if _LID > Level.HAPPY:
        _verify_needs()
        _verify_sets()


def _verifyType_NOT_IN_BAG() -> None:
    """Ověří, že byl zadána příkaz pro položení objektu
    a že zadaný objekt v batohu doopravdy není. Přitom současně ověří, že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_NOT_SET() -> None:
    """Upozornění na zákaz používání tohoto typu kroku.
    """
    _ERR(f'Typ kroku {tsNOT_SET} nesmí být používán '
         f'v testovaných scénářích.', steps=1)


def _verifyType_NOT_START() -> None:
    """Ošetření zákazu neprázdného příkazu neběžící hře.
    """
    if not _finished:
        _ERR('Předchozí hra ještě nebyla ukončena.\n' +
             'Nová hra může odstartovat až po ukončení té předchozí.',
             steps=1)
    elif len(_current_step.command) == 0:
        _ERR('Příkaz v testu špatného odstartování hry nesmí být prázdný',
             steps=1)


# @dbg.prSEd()
def _verifyType_NOT_SUCCESS() -> None:
    """Ověří reakci na předčasně zadaný příkaz k řádnému ukončení hry,
    při němž musí být splněna některá ze vyžadovaných podmínek a
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_needs_wrong_cond()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_PUT_DOWN() -> None:
    """Ověří plánovanou reakci na položení předmětu.
    Při zpracování příkazu se nesmí změnit aktuální prostor.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_same_place()
    _verify_number_of_arguments()
    _verify_equal_containers(_neighbors())
    to_put = _command_argument()
    if len(to_put) > 0:
        _verify_absence(_items(), to_put, False)
        _verify_absence(_bag(), to_put, True)


def _verifyType_PUT_DOWN_WA() -> None:
    """Ověří reakci na příkaz k položení předmětu zadaný bez argumentu, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_START() -> None:
    """Ošetření zákazu neprázdného příkazu neběžící hře.
    """
    global _finished
    if not _finished:
        _ERR('Předchozí hra ještě nebyla ukončena.\n' +
             'Tento typ testovacího kroku se vkládá před start hry.',
             steps=1)
    elif len(_current_step.command) != 0:
        _ERR('Úvodní akce každého scénáře musí mít prázdný název.',
             steps=1)
    elif _current_step != _start_step:
        _ERR('Startovní krok není shodný se startovním krokem šťastného '
             'scénáře.\nVšechny startovní kroky musejí být shodné.',
             steps=1)
    _finished = False
    if (_LID > Level.HAPPY) and (not _current_step.sets):
        _ERR('Startovní krok nenastavuje výchozí hodnoty příznaků.',
             steps=1)
    if _current_step.needs:
        _ERR('Startovní krok nemá vyžadovat výchozí hodnoty příznaků.',
             steps=1)
    global _conditions
    _conditions = _current_step.sets.copy()
    # dbg.prIN(1, f'{_conditions = }')


def _verifyType_SUCCESS() -> None:
    """Ověří reakci na příkaz k řádnému ukončení hry, při němž musejí být
    platné všechny vyžadované podmínky a
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_number_of_arguments()
    if _current_step.sets:
        _ERR('Závěrečný krok nemá nastavovat žádné hodnoty příznaků.',
             steps=1)
    if _LID > Level.HAPPY:
        _verify_needs()
    _finished = True


def _verifyType_TAKE() -> None:
    """Ověří plánovanou reakci na zvednutí předmětu.
    Při zpracování příkazu se nesmí změnit aktuální prostor.
    """
    _verify_action_name()
    _verify_same_place()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equal_containers(_neighbors())
    to_take = _command_argument()
    if len(to_take) > 0:
        _verify_absence(_items(), to_take, True)
        _verify_absence(_bag(), to_take, False)


def _verifyType_TAKE_WA() -> None:
    """Ověří reakci na příkaz ke zvednutí předmětu zadaný bez argumentu, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_UNKNOWN() -> None:
    """Ověří reakci hry na neznámý příkaz
    zůstane stav před zadáním příkazu a po jeho vykonání shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_equality_of_all_fields()


def _verifyType_UNMOVABLE() -> None:
    """Ověří reakci na pokus zvednout nezvednutelný objekt, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_no_needs_sets()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()


def _verifyType_WRONG_NS() -> None:
    """Ověří, že tuto akci lze konzistentně zařadit mezi nestandardní,
    že příkaz má požadovaný počet argumentů, a že
    plánovaný stav před zadáním příkazu a po jeho vykonání bude shodný.
    """
    _verify_action_name()
    _verify_number_of_arguments()
    _verify_equality_of_all_fields()
    if _current_step.typeOfStep in (tsNS1_0Args, tsNS2_1Args, tsNS3_012Args):
        _verify_no_needs_sets()
    else:
        _verify_needs_wrong_cond()


############################################################################

from typing import Callable

"""Funkce, jež jsou v následujícím slovníku uvedené jako hodnoty,
zpracují krok zadaného typu, přičemž zkontrolují,
zda se stav hry oproti minulému změnil úměrně typu provedeného kroku
a zda už daná akce nebyla použita pro nekonzistentní typ kroku.
"""
_tos_2_handle: dict[TypeOfStep:Callable[[], None]] = {
    tsNOT_SET:          _verifyType_NOT_SET,

    tsSTART:            _verifyType_START,
    tsNOT_START:        _verifyType_NOT_START,
    tsEMPTY:            _verifyType_EMPTY,
    tsUNKNOWN:          _verifyType_UNKNOWN,

    tsSUCCESS:          _verifyType_SUCCESS,
    tsNOT_SUCCESS:      _verifyType_NOT_SUCCESS,
    
    tsEND:              _verifyType_END,
    tsHELP:             _verifyType_HELP,

    tsGOTO:             _verifyType_GOTO,
    tsGOTO_WA:          _verifyType_GOTO_WA,
    tsBAD_NEIGHBOR:     _verifyType_BAD_NEIGHBOR,

    tsTAKE:             _verifyType_TAKE,
    tsTAKE_WA:          _verifyType_TAKE_WA,
    tsBAD_ITEM:         _verifyType_BAD_ITEM,
    tsUNMOVABLE:        _verifyType_UNMOVABLE,
    tsBAG_FULL:         _verifyType_BAG_FULL,

    tsPUT_DOWN:         _verifyType_PUT_DOWN,
    tsPUT_DOWN_WA:      _verifyType_PUT_DOWN_WA,
    tsNOT_IN_BAG:       _verifyType_NOT_IN_BAG,

    tsNS_0:             _verifyType_NON_STANDARDx,
    tsNS_1:             _verifyType_NON_STANDARDx,
    tsNS_2:             _verifyType_NON_STANDARDx,
    tsNS_3:             _verifyType_NON_STANDARDx,
    tsNS0_WrongCond:    _verifyType_WRONG_NS,
    tsNS1_WrongCond:    _verifyType_WRONG_NS,
    tsNS2_WrongCond:    _verifyType_WRONG_NS,
    tsNS1_0Args:        _verifyType_WRONG_NS,
    tsNS2_1Args:        _verifyType_WRONG_NS,
    tsNS3_012Args:      _verifyType_WRONG_NS,
    tsNS1_WRONG_ARG:    _verifyType_WRONG_NS,
    tsNS2_WRONG_1stARG: _verifyType_WRONG_NS,
    tsNS2_WRONG_2ndARG: _verifyType_WRONG_NS,
    tsNS3_WRONG_1stARG: _verifyType_WRONG_NS,
    tsNS3_WRONG_2ndARG: _verifyType_WRONG_NS,
    tsNS3_WRONG_3rdARG: _verifyType_WRONG_NS,

    tsDIALOG:           _verifyType_DIALOG,
    tsDEMO:             _verifyType_DEMO,

}

############################################################################
TADY_JSOU_GLOBÁLNÍ_PROMĚNNÉ = ""  # Pouhé návěští pro hledání sekce
_LID:int                # Level ID - nastavená hladina kontroly
_portal: IPkgInitor    # Aktuálně testovaný modul

# Kontejnery sdružující data ze všech scénářů
_action_2_group: dict[str:TypeOfStep]  # Převod názvu akce na skupinu typů
_group_2_action: dict[TypeOfStep:str]  # Převod skupiny typů kroků
# na název příslušné akce

_all_entered_actions: set[str]  # Množina názvů zadaných akcí
_all_mentioned_places: set[str]  # Množina názvů navštívených prostorů
_all_seen_items: set[str]  # Množina názvů zahlédnutých objektů v prostorech
_all_bag_items:  set[str]  # Názvy h-objektů, které se objevily v batohu

_finished: bool  # Jestli je hra nespuštěná
_happy_tested: bool  # Zda již je happy otestován
_scenarios: tuple[Scenario]  # N-tice testovaných scénářů
_start_step: ScenarioStep  # Startovní krok šťastného scénáře

# Data týkající se právě analyzovaného scénáře či dokonce kroku
_scenario_in_test: Scenario  # Aktuálně testovaný scénář
_scenario_OK: bool  # Korektnost testovaného scénáře
_current_step: ScenarioStep  # Aktuálně testovaný krok
_previous_step: ScenarioStep  # Předchozí testovaný krok
_num_of_step: int  # Počet doposud prověřených kroků

_words_in_command: list[str]  # Seznam slov příkazu

_entered_actions: set[str]  # Názvy použitých akcí
_entered_ns_actions: set[str]  # Názvy použitých rozšiřujících akcí
_not_used_action_types: set[TypeOfStep]  # Nepoužité typy akcí
_ns_actions_by_args: tuple[list[str]]  # Rozšiřující akce dle počtu arg.
_used_action_types: set[TypeOfStep]  # Použité typy akcí

_mentioned_places: set[str] # Názvy zmíněných prostorů
_visited_places: set[str]   # Názvy navštívených prostorů
_seen_items: set[str]       # Názvy zahlédnutých h-objektů
_bag_items: set[str]        # Názvy h-objektů, které se objevily v batohu

_conditions: dict[object]   # Sada testovaných a nastavovaných podmínek



############################################################################

ALL_ACTIONS  : set[str]     = set()
BASIC_ACTIONS: BasicActions = None



############################################################################
dbg.stop_mod(0, __name__)
