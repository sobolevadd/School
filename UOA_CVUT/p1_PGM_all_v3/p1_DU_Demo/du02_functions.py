#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_DU_Demo/du02_functions.py
"""
Dokumentační komentář modulu.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

# Login autora/autorky programu zadaný VELKÝMI PÍSMENY
AUTHOR_ID = 'DU02'

# Jméno autora/autorky programu ve formátu PŘÍJMENÍ Křestní
AUTHOR_NAME = 'FUNCTIONS Karel'

# Jméno autora/autorky programu v jeho/jejím rodném jazyce
AUTHOR_NATIVE_NAME = 'FUNKCE Karel'



###########################################################################q

from robotcz import *


def turn_right(k:Karel) -> Karel:
    """Otočí zadaného robota o 90° vpravo. """
    k.hide();  (
        k.turn_left(), k.turn_left(), k.turn_left()
    );k.unhide()
    return k


def step_to_left(k:Karel) -> Karel:
    """Udělá se zadaným robotem úkrok vlevo. """
    k.hide();  (
        turn_left(k),
        step(k),
        turn_right(k),
    );k.unhide()
    return k


def step_to_right(k:Karel) -> Karel:
    """Udělá se zadaným robotem úkrok vpravo. """
    hide(k);  (
        turn_right(k),
        step(k),
        turn_left(k),
    );unhide(k)
    return k


def go_about_on_left(k:Karel) -> Karel:
    """Obejde se zadaným robotem pole před ním zleva."""
    step_to_left(k)
    step(k); step(k)
    step_to_right(k)
    return k



###########################################################################q

def test_du02():
    """Prověří splnění zadaného úkolu."""
    new_world('012345', '0#23#5')
    k = Karel()
    go_about_on_left(k)
    step(k)
    go_about_on_left(k)



###########################################################################q
dbg.stop_mod(1, __name__)
