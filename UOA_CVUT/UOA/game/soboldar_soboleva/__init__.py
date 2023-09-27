#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_EDU_Demo/game/a1j_whole/__init__.py
"""
Demonstrační balíček v němž jsou definovány moduly
zprostředkující robustní realizaci všech akcí včetně nestandardních.
"""
import dbg; dbg.start_pkg(1, __name__)
###########################################################################q

# Login autora/autorky programu zadaný VELKÝMI PÍSMENY
AUTHOR_ID = 'SOBOLDAR'

# Jméno autora/autorky programu ve formátu PŘÍJMENÍ Křestní,
# tj. nejprve příjmení psané velkými písmeny a za ním křestní jméno,
# u nějž bude velké pouze první písmeno a ostatní písmena budou malá.
# Má-li autor programu více křestních jmen, může je uvést všechna.
AUTHOR_NAME = 'SOBOLEVA Daria'

# Jméno autora/autorky programu ve formátu PŘÍJMENÍ Křestní
# zapsané v jeho/jejím rodném jazyce
AUTHOR_NATIVE_NAME = 'SOBOLEVA Daria'

# Čas začátku kroužku, který navštěvujete (AUTHOR_GROUP)
GROUP_TIME = '0001'  # Zadejte čtyřčíslí odpovídající času začátku kroužku



###########################################################################q

def NAME_2_SCENARIO():
    """Vrátí odkaz na slovník převádějící názvy scénářů na dané scénáře
    Scénáře musejí být instancemi třídy `game.api.scenario.Scenario`
    """
    from . import vareni_scenarios
    return vareni_scenarios.NAME_2_SCENARIO


def GAME():
    """Vrátí odkaz na hru, která musí implementovat protokol
    `game.api.interfaces.IGame`
    """
    from . import vareni_main
    return vareni_main



###########################################################################q
# Testy

# Definované hladiny - na dané hladině se testuje:
# PORTAL      = 0 #_ Jenom initor balíčku
# HAPPY       = 1 #a Jen šťastný scénář
# SCENARIOS   = 2 #b Čtyři základní scénáře: startovní, šťastný,
#                 #c chybový a chybový scénář nadstandardních akcí
# ARCHITECTURE= 3 #d Přítomnost požadovaných objektů a metod
# START       = 4 #e Hra úspěšně odstartuje
# WORLD       = 5 #f Hra úspěšně vybuduje svůj svět
# BASIC       = 6 #g Zprovoznění základních akcí při korektním zadání
# MISTAKES    = 7 #h Základní akce jsou navržené robustní
# RUNNING     = 8 #i Zprovoznění všech akcí při korektním zadání
# WHOLE       = 9 #j Úspěšné zprovoznění hry, všechny akce jsou robustní
# MODIFIED    =10 #k Aplikace s nadstavbovými úpravami pro obhajobu
# EXTENDED    =11 #l Aplikace upravená pro obhajobu s dalším scénářem


def self_test():
    """
    Otestuje, zda stav projektu odpovídá zadané hladině rozpracovanosti.
    """
    # Nastavení hladiny rozpracovanosti aplikace
    from game.tests import Level
    LEVEL = Level.WHOLE

    # Nastavení hladiny podrobnosti výpisu průběhu testu
    import game.tests as gt
    # Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
    gt.VERBOSITY = gt.Verbosity.STEPS

    from importlib import import_module
    me = import_module(__package__)   # Importuje modul svého balíčku
    from game.tests import test
    test(me, LEVEL)         # Testuje implementaci na nastavené hladině
    # from game.tests.visitor.vma_notentered \
    #                 import Visitor_NotEntered as visitor
    # test(me, LEVEL, visitor)    # Testuje implementaci na nastavené hladině


# Test spustíte nastavením požadované hladiny ve funkci self_test(),
# zadání vlastního modulu v posledním řádku tohoto komentáře
# a zadáním následující dvojice příkazů v interaktivním režimu:
# import game.a1j_whole as at; at.self_test()



###########################################################################q
dbg.stop_pkg(1, __name__)
