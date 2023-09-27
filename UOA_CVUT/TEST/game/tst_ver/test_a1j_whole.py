#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tst_ver/test_a1j_whole.py
"""
Pomocný modul pro zrychlené zadávání testů.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

def test(solution:'IPkgInitor'):
    from ..tests                 import Level
    from ..tests.test_interface  import test as ti
    ti(solution, Level.WHOLE)

# Demonstrační řešení (moje)
root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D13__Verze_WHOLE'
package = ''

def test_all():
    from tst import test_all_solutions
    test_all_solutions('D13__Verze_WHOLE', root, test, package, True)

# from add import add_tree as at; \
# at('C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D13__Verze_WHOLE'); \
# from game.tst_ver.test_a1j_whole import test_all;  test_all()


###########################################################################q
dbg.stop_mod(1, __name__)
