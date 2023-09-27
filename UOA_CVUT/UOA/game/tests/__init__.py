#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tests/__init__.py
"""\
Balíček s testy hry v jednotlivých fázích vývoje.¤

Data:
    LIMITS          - Minimální povinné počty klíčových objektů

Třídy:
    Level           - Výčtový typ definující hladinu testování

Funkce:
    print_err_msg() - Tiskne zásobník s popisem aktuální chyby

Podbalíčky:
    common          - Balíček modulů s pomocnými programy

Moduly:
    test_portal    - Test továrního objektu
    test_scenario   - Test scénářů
    test_game       - Test hry

Soubory:


"""
import dbg; dbg.start_pkg(1, __name__, __doc__)
############################################################################

from collections import namedtuple


LIMITS = (namedtuple('Limits', 'minSteps minPlaces minVisited minNSActions')
          (12,  # Minimální počet kroků scénáře HAPPY
            5,  # Minimální počet prostorů
            5,  # Minimální počet navštívených prostorů
            2)) # Minimální počet vlastních (= nestandardních) akcí



############################################################################

from enum import IntEnum

class Level(IntEnum):
    """Hladiny rozpracovanosti aplikace a jim odpovídajících testů.
    """
    # Definované hladiny - na dané hladině se testuje:
    PORTAL      = 0 #_ Jenom initor balíčku
    HAPPY       = 1 #a Jen šťastný scénář
    SCENARIOS   = 2 #b Čtyři základní scénáře: startovní, šťastný,
                    #c chybový a chybový scénář nadstandardních akcí
    ARCHITECTURE= 3 #d Přítomnost požadovaných objektů a metod
    START       = 4 #e Hra úspěšně odstartuje
    WORLD       = 5 #f Hra úspěšně vybuduje svůj svět
    BASIC       = 6 #g Zprovoznění základních akcí při korektním zadání
    MISTAKES    = 7 #h Základní akce jsou navržené robustní
    RUNNING     = 8 #i Zprovoznění všech akcí při korektním zadání
    WHOLE       = 9 #j Úspěšné zprovoznění hry, všechny akce jsou robustní
    MODIFIED    =10 #k Aplikace s nadstavbovými úpravami pro obhajobu
    EXTENDED    =11 #l Aplikace upravená pro obhajobu s dalším scénářem



############################################################################

class Verbosity(IntEnum):
    """Míra podrobnosti kontrolních tisků.
    """
    SUMMARY     = 0     # Info: prošel / neprošel
    DETAILS     = 1     # Základní charakteristika
    STEPS       = 2     # Výpis jednotlivých kroků
    STEP_ATTR   = 3     # Výpis kroků i s jejich atributy


def prVb(verbosity, *objects, sep=' ', end='\n'):
    """Je-li aktuálně nastavená hladina podrobností tisku
    menší nebo rovna než hodnota argumentu `verbosity`,
    vytiskne zadané objekty.
    """
    if VERBOSITY >= verbosity:
        print(*objects, sep=sep, end=end, flush=True)



############################################################################


from ..api.interfaces   import IPkgInitor

# @dbg.prSEd(msg=f'(game/tests/__init__)')
def test(module:IPkgInitor, ID:Level, visitorClass:type=None) -> bool:
    """Otestuje zadaný tovární objekt a jím poskytnuté objekty hry.
    Zprávu o testu tiskne na standardní výstup.
    """
    if not visitorClass:
        from .visitor import Visitor
        visitorClass = Visitor
    # from . import test_interface as ti; print(f'test_interface = {ti}')
    from .test_interface import test
    result = test(module, ID, visitorClass)
    return result



############################################################################

def print_err_msg():
    """Zjistí si aktuální chybu a vytiskne výpis zásobníku.
    """
    import sys, traceback as TB
    tbo = sys.exc_info()[2]
    TB.print_tb(tbo)



############################################################################

# Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
VERBOSITY = Verbosity.STEP_ATTR



############################################################################
dbg.stop_pkg(1, __name__)
