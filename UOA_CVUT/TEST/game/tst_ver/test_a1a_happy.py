#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tst_ver/test_a1a.py
"""
Pomocný modul pro zrychlené zadávání testů.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

def test(solution):
    from ..tests                    import Level
    from ..tests.test_interface     import test as ti
    ti(solution, Level.HAPPY)

# root    = 'c:/_S/SVN_D_TXT/Přednášky/p1_Python_111/p1_PGM/p1_EDU_Demo'
# package = 'game'

# root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D05a_Stastny_scenar'
# package = 'game'

root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D05b_Stastny_scenar'
package = 'game'

def test_me():
    from tst import test_all_solutions
    test_all_solutions('D05a_Stastny_scenar', root, test, package, True)

# from game.tst_ver.test_a1a import test_me;  test_me()


###########################################################################q
dbg.stop_mod(1, __name__)
