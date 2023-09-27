#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/game/tst_ver/test_a1b.py
"""
Pomocný modul pro zrychlené zadávání testů.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

def test(solution):
    from ..tests                    import Level
    from ..tests.test_interface     import test as ti
    ti(solution, Level.SCENARIOS)

# Demonstrační řešení (moje)
# root    = 'c:/_S/SVN_D_TXT/Přednášky/p1_Python_111/p1_PGM/p1_EDU_Demo'
# package = 'game'

# root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D10a_Ctverice_scenaru'
# package = 'game'

# root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/D10a_Ctverice_scenaru'
# package = ''

# root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/DU10b_Ctverice_scenaru'
# package = ''

root    = 'C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/DU10c_Ctverice_scenaru'
package = ''

def test_all():
    from tst import test_all_solutions
    test_all_solutions('D10c_4_scénáře', root, test, package, True)

# from add import add_tree as add; \
# add('C:/#E/EDU/2022w_111/06_Vyhodnoceni_DU/DU10__Ctverice_scenaru'); \
# from game.tst_ver.test_a1b_all import test_all;  test_all()


###########################################################################q
dbg.stop_mod(1, __name__)
