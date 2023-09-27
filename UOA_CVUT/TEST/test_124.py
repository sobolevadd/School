#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/!_test_124.py
"""
Modul spouštějící testování modulu zadaného v kódu spouštěném
při aktivaci modulu jako skriptu
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

import game.soboldar_soboleva as PACKAGE


from game.tests import Level
LEVEL = Level.EXTENDED

import game.tests as gt
# Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
gt.VERBOSITY = gt.Verbosity.STEP_ATTR   # Podrobnost výpisu průběhu testu

if LEVEL == Level.MODIFIED:
    import game.tests.visitor.vmb_notvisited as vm

import game.tests.visitor.vpb_magic as vm
vm.prepare_test_scenario(PACKAGE)


from game.tests.visitor.vpb_magic \
                import VisitorMagic as visitor
from game.tests import test
test(PACKAGE, LEVEL, visitor)


###########################################################################q
dbg.stop_mod(1, __name__)
