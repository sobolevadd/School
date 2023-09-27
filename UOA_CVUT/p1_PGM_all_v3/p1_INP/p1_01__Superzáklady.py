#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/p1_01__Superzáklady.py
"""
Příkazy zadávané ve výpisech kapitoly:
01  Superzáklady
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q



#Stránka 1.3	Komentáře a počáteční mezery
###########################################################################q
123 + 456 #Před zadáním příkazu nesmí být zbytečná mezera
 432 - 10 #Tady jedna byla



#Stránka 1.4	Literály reálných čísel
###########################################################################q
123_456_789_0_123_456_789_0_123_456_789.
123e-3
123.
123e3



#Stránka 1.4.1	Nekonečna a nesmyslná čísla
###########################################################################q
float('INF'), float('-Inf'), -float('-inf'), float('NaN')
float('-inf') * -float('inf'),  float('inf')/float('inf')
123 / float('inf'), 123 / float('-inf'), -123 / float('-inf')



#Stránka 1.5	Literály komplexních čísel
###########################################################################q
1 + 1J
1+j  # Znak j nelze zapsat samotný
2j  #Imaginární čísla se v závorkách netisknou
0+3j



#Stránka 1.6	Stringové literály
###########################################################################q
"Text v uvozovkách"                                                    #SYNC
'Text v apostrofech'                                                   #SYNC
"Potřebuji 'apostrof'"                                                 #SYNC
'Potřebuji "uvozovky"'                                                 #SYNC



#Stránka 1.6.1	Víceřádkové stringy
###########################################################################q
"""několikařádkový
text"""
'''
Jiný způsob\
'zápisu'
'''
'''Musí být 'odděleny''''
""     #Dvojice uvozovek či apostrofů označuje prázdný string
"'Sousedící' stringové literály"  'Python "automaticky" sloučí'



#Stránka 1.8	Hodnota None
###########################################################################q
None
0
print(None)



#Stránka 1.9	Hodnota Ellipsis
###########################################################################q
...



#Stránka 2.2	Program = posloupnost příkazů
###########################################################################q
2 ** 10;   0x400;    355/113



#Stránka 2.4.1	Vytvoření proměnné
###########################################################################q
a = 123     #Vytvářím a inicializuji novou proměnnou
a           #Nechávám zobrazit její hodnotu
a = a + x   #Proměnná x ještě není vytvořena
x = 456     #Vytvářím a současně inicializuji proměnnou x
a = a + x   #Proměnná x je již použitelná
a           #Obsah proměnné a se změnil



#Stránka 2.4.2	Nebezpečné změny hodnot
###########################################################################q
a = "Sto dvacet tři"  #Opět měním hodnotu proměnné a
x = a + x             #String není možné sčítat s číslem
b = 'miliónů'    #Vytvářím a inicializuji proměnnou b
a + b            #Dva stringy již sčítat mohu
a + ' ' + b
mezera = ' '
a + mezera + b



#Stránka 2.4.3	Pomocná proměnná _ a její využití	1/2
###########################################################################q
_   #Na počátku není proměnná definována
123 #Výsledek jsme neuložil => uložil se do proměnné _
_   #Už je definovaná, obsahuje neuložený výsledek
a = 7  #Nebylo třeba nic ukládat,
_      #a proto se její obsah nezměnil
456    #Nový neuložený výsledek změní hodnotu proměnné
_      #Už je tam nová hodnota



#Stránka 2.4.4	Pomocná proměnná _ a její využití	2/2
###########################################################################q
456                                                                    #SYNC
None
_



#Stránka 2.5.1	Příklady použití složeného přiřazení
###########################################################################q
a  = 1; b = 10; c = 100
# Ekvivalent: b = b  * (a+c), tj. b = 10 * (100+1)
b *= a + c; b
c**= 2*a; c # Ekvivalent: c = c ** (2*a), tj. c = c ** 2
# Často se používá pro přičtení či odečtení jedničky
c += 1;  c



#Stránka 2.6.1	Volání funkcí
###########################################################################q
a = 123;   b = 'miliónů';   mezera = ' '
print(str(a) + mezera + b)



#Stránka 2.6.2	Příklad: zadání údajů z klávesnice
###########################################################################q
input('Jak vás mám oslovovat? ')
Vaše blahorodí
print('Dobrý den,', _)



#Stránka 3.2.1	Použití formátovaných stringů
###########################################################################q
print(f'''\
Sčítání:{  6 + 4 = }, {'AB'+"CD"=};   Odčítání: {4-6=};
Násobení: {6 * 4 = }, {3*'21' = },{ '21' * 3 = };
Dělení:   {6/4=};  Celočíselné: {6//4=};  Zbytek: {6%4=};
Mocnění:  {6**4 = },  {36**2 = }
''')



#Stránka 3.2.1	Ukázka formátování f stringů
###########################################################################q
print(f'{(s1:="string")=} × s2={(s2:="STRING")};   '
      f's1={s1} × {s2=}')
print(f'{(s1:="string")=!s} × s2={(s2:="STRING")!r};   '
      f's1={s1!r} × {s2=!s}')



#Stránka 3.4	Zadání skupiny hodnot
###########################################################################q
x = y = z = 123
x, y, z
x, y, z = 10, 20, 30
x, y, z
z, x, y = x, y, z
x, y, z



#Stránka 3.4.1	N tice hodnot
###########################################################################q
1,       # Jednoprvková n tice
1,2,3,   # Použití čárky zavádí n tici i bez závorek
()       # Prázdná n-tice



#Stránka 3.5	Přiřazovací výraz
###########################################################################q
print(f"{(x:='Raz')!r} + {(y:='Dva')!r} = {x + y = !r}")



#Stránka 3.6	Více příkazů na řádku × více výrazů na řádku
###########################################################################q
x = 'Přiřazovaná hodnota';   x
a = 1;   b = 10;   c = 100;   print(a, b, c)
(a := 11);   (b := 22);   print(f'{a=}, {b=}')
(a := 99),   (b := 88),   print(f'{a=}, {b=}')



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
