#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_EDU_Demo/game/a1j_whole/ck_main.py
"""
Balíček na starosti řízení hry a komunikaci s uživatelem.
Je schopna akceptovat zadávané příkazy a poskytovat informace
o průběžném stavu hry a jejích součástí.
"""
import dbg
dbg.start_pkg(1, __name__)
############################################################################

from game.api       import BasicActions

from .vareni_world      import Bag, BAG
from .              import vareni_actions as actions
from .vareni_actions    import Action


############################################################################

def is_alive() -> bool:
    """Vrátí informaci o tom, je-li hra aktuálně spuštěná.
    Spuštěnou hru není možno pustit znovu.
    Chceme-li hru spustit znovu, musíme ji nejprve ukončit.
    """
    return actions.is_active


def execute_command(command:str) -> str:
    """Zpracuje zadaný příkaz a vrátí text zprávy pro uživatele.
    """
    return actions.execute_command(command)


def stop() -> None:
    """Ukončí hru a uvolní alokované prostředky.
    Zadáním prázdného příkazu lze následně spustit hru znovu.
    """
    actions._END.execute(())


def all_actions() -> tuple[Action]:
    """Vrátí n-tici všech akcí použitelných ve hře.
    """
    result = tuple(actions.NAME_2_ACTION.values())
    return result


def basic_actions() -> BasicActions:
    """Vrátí přepravku s názvy povinných akcí.
    """
    return BasicActions(MOVE_NAME='Jdi', PUT_DOWN_NAME='Polož',
                        TAKE_NAME='Vezmi', HELP_NAME='?', END_NAME='KONEC')


def bag() -> Bag:
    """Vrátí odkaz na batoh, do nějž bude hráč ukládat sebrané objekty.
    """
    return BAG


def world() -> 'IWorld':
    """Vrátí odkaz na svět hry.
    """
    from . import vareni_world as w
    return w


def conditions() -> dict[str, object]:
    """Vrátí slovník s aktuálním nastavením příznaků.
    """
    return actions.conditions



############################################################################
dbg.stop_pkg(1, __name__)
