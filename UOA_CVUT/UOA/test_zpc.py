#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/test_zpc.py
"""
Modul spouštějící testování modulu zadaného v kódu spouštěném
při aktivaci modulu jako skriptu
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

import game.soboldar_soboleva as PACKAGE

import game.tests as gt
# Hladiny SUMMARY=0, DETAILS=1, STEPS=2, STEP_ATTR=3
gt.VERBOSITY = gt.Verbosity.STEPS   # Podrobnost výpisu průběhu testu

LEVEL = gt.Level.EXTENDED



#===========================================================================

from game.tests         import test
from game.tests.visitor import vpc_permit as vm
# Součástí importu návštěvníka bylo i nastavení prostředí

portal = vm.WrappedPortal(PACKAGE)
test(portal, LEVEL, vm.VisitorPermit)



###########################################################################q
dbg.stop_mod(1, __name__)
