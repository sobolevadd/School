#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/robotcz/test/test_manual.py
"""
Dokumentační komentář modulu.
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q

from .. import *



###########################################################################q

def turn_about(k:Karel):
    """Provede rychlou otočku o 180°."""
    with k:
        k.turn_left()
        k.turn_left()
    return k
Karel.turn_about = turn_about

def turn_right(k:Karel):
    """Provede rychlou otočku o 90° vpravo."""
    with k:
        k.turn_left()
        k.turn_left()
        k.turn_left()
    return k
Karel.turn_right = turn_right


def step_to_left(k:Karel) -> Karel:
    """Udělá se zadaným robotem úkrok vlevo. """
    with k:
        turn_left(k)
        step(k)
        turn_right(k)
    return k
Karel.step_to_left = step_to_left


def step_to_right(k:Karel) -> Karel:
    """Udělá se zadaným robotem úkrok vpravo. """
    with k:
        turn_right(k)
        step(k)
        turn_left(k)
    return k
Karel.step_to_right = step_to_right



###########################################################################q

def set_up():
    """Připraví prostředí pro testy."""
    global k, r
    new_world(1, 5)  # Prázdný svět o jednom řádku a pěti sloupcích
    new_world('0123456789',  # Svět o dvou řádcích a deseti sloupcích
              ' .:…∷…:. #')  # s políčky obsahujícími značky nebo zeď
    k = Karel()  # Umístí robota do levého dolního rohu
    r = Karel(-1, -2)


def more_robots():
    """Demo současné činnosti více robotů."""
    new_world(2, 10)
    with Multihider():
        k1 = Karel(0, 0);       k2 = Karel(0, -1, dir4=WEST)
        k3 = Karel(1, 0);       k4 = Karel(1, -1, dir4=WEST)
    for i in range(4):
        with Multihider(k1, k2, k3, k4):
            k1.step();   k2.step();   k3.step();   k4.step()


def test_manual():
    """Ručně odřízený test správného provádění skrytí a odkrytí.
    """
    w = new_world(2, 7)
    k = Karel()
    k.turn_left()
    input('Budeme se otáčet vpravo')
    turn_right(k)
    input('Ukročíme vpravo')
    step_to_right(k)



###########################################################################q
dbg.stop_mod(1, __name__)
