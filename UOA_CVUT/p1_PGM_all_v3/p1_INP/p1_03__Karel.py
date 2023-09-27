#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/p1_04__Karel.py
"""
Příkazy zadávané ve výpisech kapitoly:
P04. Balíčky, knihovny, Karel
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q



#Stránka 3.3.1	Příklady vytvoření světa s robotem
###########################################################################q
from robotcz import *
new_world(1,5)    # Prázdný svět o jednom řádku a pěti sloupcích
new_world('0123456789', # Svět o dvou řádcích a deseti sloupcích
          ' .:…∷…:. #') # s políčky obsahujícími značky nebo zeď
k = Karel()     # Umístí robota do levého dolního rohu
             # Tisk podpisu naposledy vytvořeného světa



#Stránka 3.5.1	Demonstrace akcí
###########################################################################q
step(k)            # Posune robota o krok vpřed
turn_left(k)       # Otočí robota vlevo
put(k); step(k)    # Položí značku a popojde
pick(k); turn_left(k); step(k)  # Zvedne, otočí se a popojde
step(k)  # Pokusí se posunout o krok vpřed do okrajové zdi



#Stránka 3.6.1	Demonstrace testů
###########################################################################q
is_wall(k)                  # Stojí čelem k okrajové zdi
is_east(k)                  # Hledí na jih
turn_left(k);   is_east(k)  # Po otočce hledí na východ
r = Karel(-1,-2)    # Nový robot vpravo před zdí
robot_before(r)     # Před ním je zeď, ne robot => vrátí None
is_wall(r)          # Testuje neokrajovou zeď



#Stránka 3.7.1	Demonstrace zakrytí a odkrytí
###########################################################################q
turn_left(k);  turn_left(k);  turn_left(k)  # Pomalá vpravo
hide(k); turn_left(k); turn_left(k); turn_left(k); unhide(k)



#Stránka 4.2.1	Vnoření příkazů k zakrytí a odkrytí
###########################################################################q
def turn_about(k:Karel) -> Karel:
    """Otočí zadaného robota čelem vzad."""
    hide(k)    # Zapínáme skryté, zrychlené provádění
    turn_left(k);  turn_left(k)
    unhide(k)  # Vracíme se k veřejnému provádění
    return k

def step_back(k:Karel) -> Karel:
    """Udělá se zadaným robotem krok zpět."""
    hide(k)    # Zapínáme skryté, zrychlené provádění
    turn_about(k);  step(k);  turn_about(k)
    unhide(k)  # Vracíme se k veřejnému provádění
    return k

turn_about(k); step_back(r)  # První se otočí, druhý couvne



#Stránka 5.2	Použití příkazu with pro robota Karla – funkce
###########################################################################q
turn_left(k);   turn_left(k);   turn_left(k)
with r:   # Udělá totéž, ale rychle
    turn_left(r);   turn_left(r);   turn_left(r)



#Stránka 5.3	Použití příkazu with v definovaných metodách
###########################################################################q
def turn_about(k:Karel) -> Karel:
    """Otočí zadaného robota čelem vzad."""
    with k:    # Zapínáme zrychlené provádění
        turn_left(k);  turn_left(k)
    return k

def step_back(k:Karel) -> Karel:
    """Udělá se zadaným robotem krok zpět."""
    with k:    # Zapínáme zrychlené provádění
        turn_about(k);   step(k);   turn_about(k)
    return k

turn_about(k); step_back(r)  # První se otočí, druhý couvne




#Stránka 5.3.1	Funkce turn_right()
###########################################################################q
def turn_right(k:Karel) -> Karel:
    """Otočí zadaného robota o 90° vpravo."""
    with k:    # Zapínáme zrychlené provádění
        # Využíváme toho, že turn_left() je metoda robota
        k.turn_left().turn_left().turn_left()
    return k

turn_right(k);      turn_right(r)



#Stránka 5.4	Současné použití více správců kontextu
###########################################################################q
with k, r:
    step(k)   # Levý robot se posune jako první
    step(r)   # Ale posun pravého bude dříve zobrazen



#Stránka 5.4.1	Totéž, ale rozepsaný with
###########################################################################q
def embedded_with():
    """Aby interpret správně reagoval na příkaz `input()`,
    musí být celá akce definována jako funkce.
    """
    with k:
        with r: # Vnitřní with dříve skončí => dříve zobrazuje
            k.step()    # Vyrazil dřív, ale zobrazí se později
            r.step()    # Zobrazí se, až skončí jeho with
            input('Oba už popošli, ale ještě není nic vidět')
        input ('Už je vidět jak robot r popošel')
    input('Teprve nyní se zobrazilo posunutí robota k')

embedded_with()



#Stránka 5.5	Správci typu robotcz.Multihider
###########################################################################q
def more_robots():
    """Demo současné činnosti více robotů."""
    new_world(2, 10)
    with Multihider():  # Objeví se všichni najednou
        k1 = Karel(0, 0);       k2 = Karel(0, -1, dir4=WEST)
        k3 = Karel(1, 0);       k4 = Karel(1, -1, dir4=WEST)
    for i in range(4):
        with Multihider(k1, k2, k3, k4):
            k1.step();   k2.step();   k3.step();   k4.step()



#Stránka 6.2	Rozšíření portfolia metod třídy Karel
###########################################################################q
Karel.turn_about = turn_about
Karel.turn_right = turn_right
Karel.step_back  = step_back



#Stránka 6.2.1	Prověření přidaných metod
###########################################################################q
# Test právě definovaných metod
k.step_back();      r.step_back()
k.turn_about();     r.turn_about()
k.turn_right();     r.turn_right()
k.turn_right().step_back()
r.turn_left().step().step().step().turn_about()



#Stránka 0.X:	Popisek
###########################################################################q
"""
Je uloženo v souboru
#P:/p1_INP/xxx.py
"""
#---------------------------------------------------------------------------
                                                                       #SYNC
###########################################################################q
dbg.stop_mod(1, __name__)
