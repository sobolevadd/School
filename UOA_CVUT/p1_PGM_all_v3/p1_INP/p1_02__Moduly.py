#Příliš žluťoučký kůň úpěl ďábelské ó - PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ Ó
#P:/p1_INP/p1_02__Moduly.py
"""
Příkazy zadávané ve výpisech kapitoly:
P02. Moduly
"""
import dbg; dbg.start_mod(1, __name__)
###########################################################################q



#Stránka 1.2	Třída – instance – typ
###########################################################################q
print(f'{type(123) = }\n{type(1.0) = }\n{type("X") = }')



#Stránka 2.4.2	Příklad: želva a želví grafika
###########################################################################q
turtle.Turtle()   # Před importem jsou atributy nepoužitelné
import turtle        # Importujeme modul
t = turtle.Turtle()  # Vytvoříme instanci želvy
t.forward(50)        # Pojedeme s ní 50 kroků vpřed
t.left(90)           # Otočíme ji o 90° doleva
t.forward(50)        # Opět popojedeme o 50 kroků



#Stránka 2.4.2	Reakce na neschopnost přijmout non-ASCII znaky v komentáři
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
turtle.Turtle()   # Před importem jsou atributy nepoužitelné
import turtle        # Importujeme modul
t = turtle.Turtle()  # Vytvoříme instanci želvy
t.forward(50)
t.left(90)
t.forward(50)



#Stranka 2.5	Continuation of the previous modification for the following listing 2.5
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
from turtle import Turtle as Zelva
zz = Zelva()
zz.right(90); zz.forward(50)

exit()
# Aby bylo možno pokračovat v zadávání textů s diakritikou přes schránku,
# je nutno interpret restartovat
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q
# XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX q



#Stránka 2.5	Přímý import vyjmenovaných objektů
###########################################################################q
from turtle import Turtle as Želva      # Proměnná Želva
žž = Želva()            #odkazuje na třídu turtle.Turtle
žž.right(90); žž.forward(50)        # Nakreslí čáru dolů



#Stránka 3.1	Příklad: demonstrační modul p1_02a_Script
###########################################################################q
"""
Je uloženo v souboru
#P:/p1_INP/p1_02a_Script.py
"""



#Stránka 3.1.1	Import modulu p1_02a_Script
###########################################################################q
import p1_02a_Script

p1_02a_Script.pozdrav      # Atributy jiného modulu =>
p1_02a_Script.__name__     # => je třeba kvalifikovat
__name__   # Atributy aktuálního modulu se nekvalifikují



#Stránka 3.1.2	Spuštění skriptu z příkazového řádku
###########################################################################q
# p1_02a_Script.py



#Stránka 3.4.1	Šablona modulů v doprovodných programech
###########################################################################q
"""
Je uloženo v souboru
#P:/p1_INP/p1_00a_module_template.py
"""



#Stránka 3.4.2	Tělo modulu  p1_02b_ModuleDemo
###########################################################################q
"""
Je uloženo v souboru
#P:/p1_INP/p1_02b_ModuleDemo.py
"""



#Stránka 3.4.3	Práce s vytvořeným modulem
###########################################################################q
import p1_02b_ModuleDemo as m
m       # Systémový podpis načteného modulu
m.text  # Atribut importovaného modulu
m.dbg.prDict()



#Stránka 3.5	Přímý import a jeho vlastnosti
###########################################################################q
text
from p1_02b_ModuleDemo import text
text
m.text = 'Modifikovaný ' + text
print(f'{m.text = }\n{text   = }')
from p1_02b_ModuleDemo import text  # Nové přiřazení hodnoty
text



#Stránka 3.6	Hvězdičkový import
###########################################################################q
m.dbg.prDict() # Půjčím si atribut dbg modulu m, svůj nemám
from p1_02b_ModuleDemo import *  # Importuji všechny veřejné
dbg.prDict()  # Už ho mám, právě jsem jej importoval
m._text  # Explicitním zadáním získám i neveřejné atributy



#Stránka 4.1	Opětné načtení upraveného modulu
###########################################################################q
from importlib import reload
reload(dbg)  # Jako argument předá odkaz na načítaný modul



#Stránka 4.1.1	Opětné načtení modulu p1_02b_ModuleDemo
###########################################################################q
import p1_02b_ModuleDemo as m2 # Objekt modulu již existuje =>
m2.text     # => nic se nenačetlo, atribut má původní hodnotu
from importlib import reload
reload(m)   # Argumentem je proměnná odkazující na modul
m2.text     # Atribut modulu se změnil
text        # Přímo importovaný atribut je beze změn



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
