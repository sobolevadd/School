#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_EDU_Demo/game/a1j_whole/ck_actions.py
"""
Představuje správce akcí, který řídí celkové chování hry
a v závislosti na tom, je-li hra právě aktivní, rozhoduje,
která akce dostane na starost zpracování aktuálního příkazu.
Současně obsahuje definice všech akcí.
"""
import dbg; dbg.start_pkg(1, __name__)
############################################################################

from .              import vareni_world as world
from .vareni_scenarios  import *



############################################################################

def execute_command(command: str) -> str:
    """Zpracuje zadaný příkaz a vrátí text zprávy pro uživatele.
    """
    command = command.strip()   # Smaže úvodní a závěrečné bílé znaky
    if command == '':
        return _execute_empty_command()
    elif is_active:
        return _execute_standard_command(command)
    else:
        return NOT_START


def _execute_empty_command() -> str:
    """Zpracuje prázdný příkaz, tj. příkaz zadaný jako prázdný řetězec.
    Tento příkaz odstartuje hru, ale v běžící hře se nesmí použít.
    """
    global is_active    # Aby nevytvořil lokální proměnnou
    if is_active:
        return EMPTY
    else:
        is_active = True
        _initialize()
        return WELCOME


def _execute_standard_command(command: str) -> str:
    """Připraví parametry pro standardní akci hry,
    tuto akci spustí a vrátí zprávu vrácenou metodou dané akce.
    Byla-li zadána neexistující akce, vrátí oznámení.
    """
    words = command.lower().split()
    action_name = words[0]
    try:
        action  = NAME_2_ACTION[action_name]
    except KeyError:
        return UNKNOWN + action_name
    return action.execute(words)


def _initialize():
    """V rámci startu hry inicializuje všechny potřebné objekty.
    """
    global conditions
    conditions = {
        'OBTAINED' : False,
        'ARGUMENT' : False,
        'cibule.bought': True,
        'cibule.inkitchen': False,
        'brambory.bought': True,
        'brambory.inkitchen': False,
        'payable': ('brambory', 'okurky', 'jahody')
    }
    world.initialize()



############################################################################

class Action(world.ANamed):
    """Instance třídy řeší reakce na zadané příkazy
    a realizují tak požadované akce.
    """

    def __init__(self, name:str, execute):
        """Vytvoří akci se zadaným názvem, stručným popisem
        a funkcí pro zpracování zadaného příkazu."""
        super().__init__(name)
        self.execute = execute


    @property
    def description(self) -> str:
        """Vrátí popis příkazu s vysvětlením jeho funkce,
        významu jednotlivých parametrů a možností (resp. účelu) použití
        daného příkazu. Tento popis tak může sloužit jako nápověda
        k použití daného příkazu.
        """
        return self.execute.__doc__



############################################################################
# Základní pětice povinných akcí

def end(arguments: str) -> str:
    """
    Ukončí hru a převede ji do pasivního stavu.
    """
    global is_active
    is_active = False
    return END


def goto(arguments: list[str]) -> str:
    """
    Ověří, že zadaný prostor patří mezi sousedy aktuálního prostoru,
    a Karkulku do něj přemístí.
    """
    if len(arguments) < 2:
        return MOVE_WA
    destination_name = arguments[1]
    destination = world._current_place \
                       .name_2_neighbor(destination_name)
    if destination:
        world._current_place = destination
        return (GOTO + destination.description)
    else:
        return (BAD_NEIGHBOR + destination_name)


def help(arguments: list[str]) -> str:
    """
    Zobrazí základní cíl hry spolu se stručným návodem k jeho dosažení
    a za ním pak vypíše seznam dostupných akcí spolu s jejich popisy.
    """
    result = (SUBJECT + '\n'
           + 'Hra umožňuje vyvolat následující akce:\n\n')
    for a in NAME_2_ACTION.values():
        result += f'{a.name}\n{a.description}\n\n'
    return result


def put(arguments: list[str]) -> str:
    """
    Ověří existenci zadaného h-objektu v košíku a je-li tam,
    vyjme jej z košíku a přesune do aktuálního prostoru.
    """
    if len(arguments) < 2:
        return PUT_DOWN_WA
    item_name = arguments[1]
    item      = world.BAG.remove_item(item_name)
    if item:
        world._current_place.add_item(item)
        return PUT_DOWN + item.name
    else:
        return NOT_IN_BAG + item_name


def take(arguments: list[str]) -> str:
    """
    Ověří existenci zadaného h-objektu v aktuálním prostoru
    a je-li tam a vejde se do košíku, tak jej do něj přesune.
    """
    if len(arguments) < 2:
        return TAKE_WA
    item_name = arguments[1]
    item      = world._current_place.remove_item(item_name)
    if not item:
        return BAD_ITEM + item_name
    if item.weight == world.Item.HEAVY:
        world._current_place.add_item(item)
        return UNMOVABLE + item.name
    if world.BAG.add_item(item):
        return TAKE + item.name
    else:
        world._current_place.add_item(item)
        return BAG_FULL + item.name



############################################################################
# Sada vlastních nestandardních akcí

# @dbg.prSEda()

def permit(arguments:tuple[str]) -> str:
     """
     Ověří, že se v aktuálním prostoru nachází objekt, jehož je možno
     odnest do kuchyně, a pokud ještě nebyl koupen, tak jej koupí.
     """
     if len(arguments) < 2:
         return 'Příkaz ZÍSKAT neznám.'
     item = '_'+arguments[1]
     if (not conditions['OBTAINED'] and arguments[1] == 'povolení'):
         world.BAG.MojeVelikost = 3
         conditions['OBTAINED'] = True
         world.BAG.add_item(world.Item(item))
         return 'Dosažení cíle vám umožní právě získaný objekt POVOLENÍ'
     else:
         return 'Příkaz ZÍSKAT neznám.'



def is_bought(arguments:tuple[str]) -> str:
    """
    Ověří, že se v aktuálním prostoru nachází objekt, jehož je možno
    odnest do kuchyně, a pokud ještě nebyl koupen, tak jej koupí.
    """
    vars = {}
    if len(arguments) < 2:
        return NS1_0Args                    # Není zadán argument
    if item := argument_present(arguments, vars):
        lower_name = vars['lower_name']
    else:
        return NS1_WRONG_ARGa + arguments[1]    # Zadaný není v prostoru
    if not argument_payable(arguments, vars):
        return NS1_WRONG_ARGb + item.name   # Se zadaným nelze komunikovat
    if conditions[lower_name + '.bought']:
        conditions[lower_name + '.bought'] = False
        return NS_1 + item.name             # Zadaného jsme probudili
    else:
        return NS1_WrongCond + item.name    # Zadaný již byl probuzen


# @dbg.prSEdr()
def take_to_kitchen(arguments:tuple[str]) -> str:
    """
    Ověří, že se v aktuálním prostoru nachází koupený objekt,
    jehož je možné vzít do kuchyně, tak jeho vem.
    """
    vars = {}
    if payable_present(arguments, vars):
        low_name = vars['low_name']
    else:
        return NS0_WrongCondA       # Není koho zdravit
    if conditions[low_name + '.bought']:  # Zadaný objekt ještě spí
        return (f'{NS0_WrongCond1}{low_name}{NS0_WrongCond2}')
    if conditions[low_name + '.inkitchen']:   # Zadaný již byl probuzen
        # Objekt již byl pozdraven
        return f'{NS0_WrongCondB1}{low_name}{NS0_WrongCondB2}'
    else:
        conditions[low_name + '.inkitchen'] = True
        return NS_0 + low_name      # Objekt jsme pozdravili


def wish(arguments:tuple[str]) -> str:
    """
    Ověří, že se v aktuálním prostoru nachází objekt,
    s nímž je možno komunikovat, a že tento objekt již byl pozdraven.
    Je-li tomu tak, tak objektu popřeje vše nejlepší k narozeninám
    a ukončí hru.
    """
    if not (item := payable_present(arguments)):
        return NOT_SUCCESa 
    world.BAG.MojeVelikost = 2
    if not conditions[item.name.lower() + '.inkitchen']:
        return NOT_SUCCESSb1 + item.name + NOT_SUCCESSb2
    elif (not conditions['OBTAINED']):
        return 'K úspěšnému ukončení hry je třeba nejprve získat povolení.'
    else: 
        global is_active
        is_active = False
        return SUCCESS1 + item.name + SUCCESS2   # Objektu jsme popřáli
   
    
    



############################################################################
# Pomocné testy

def argument_payable(arguments:tuple[str], vars:dict={}) -> bool:
    """
    Zjišťuje, zda je argument aktuálního příkazu
    názvem probuditelného objektu.
    """
    lower_name = vars.get('lower_name')
    if not lower_name: lower_name = arguments[1].lower()
    return lower_name in conditions['payable']


def argument_present(arguments:tuple[str], vars:dict={}) -> bool:
    """Zjišťuje, zda je argument aktuálního příkazu
    názvem h-objektu přítomného v aktuálním prostoru.
    """
    item_name  = arguments[1]
    lower_name = item_name.lower()
    item       = world.current_place().item(lower_name)
    vars['lower_name'] = lower_name
    return item


def payable_present(arguments:tuple[str], vars:dict={}) -> 'Item':
    """Zjišťuje, zda je v aktuálním prostoru přítomen nějaký
    probuditelný objekt.
    """
    cp = world.current_place()
    for item in cp.items:
        if (low_name:=item.name.lower()) in conditions['payable']:
            vars['low_name'] = low_name
            return item                   # Je tu zdravitelný objekt
    return False



############################################################################

# Příznak toho, zda hra právě běží (True), anebo jen čeká na další spuštění
is_active: bool = False     # Na počátku hra čeká, až ji někdo spustí

# Slovník s podmínkami testovanými a nastavovanými
# při provádění nestandardních akcí
conditions:dict[str:object] = {}

# Testovací funkce evidované v prvku conditions[conditions]
# a prověřující složitější podmínky
tests:dict[str:'Callable[[], bool]'] = dict(
    argument_payable = argument_payable,
    argument_present  = argument_present,
    payable_present  = payable_present
)

# Slovník, jehož klíče jsou názvy akcí převedené na malá písmena
# a hodnoty jsou příslušné akce
NAME_2_ACTION = {
'jdi':      Action('Jdi',       goto),
'vezmi':    Action('Vezmi',     take),
'polož':    Action('Polož',     put),
'?':        Action('?',         help),
'konec':    Action('Konec',     end),
'kup':   Action('Kup',    is_bought),
'odnes':  Action('Odnes',   take_to_kitchen),
'popřej':   Action('Popřej',    wish),
'získat': Action('získat',  permit),
}



############################################################################
dbg.stop_mod(1, __name__)
