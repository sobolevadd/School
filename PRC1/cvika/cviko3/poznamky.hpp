/*

struktura - 
struct Foo {
    int bar;
};

Foo f;
f.bar = 42;
Foo *uf = &f; // ukazatel na structura ukladame adresu f
uf -> bar = 21;  (*uf).bar = 21; // sipka ukazatel deferencuje, pak pristoupime k te polozce



Zasobnik (stack)
LIFO (last in first out)

kam data muzeme ukladat kdyz jsou stejneho typu -  do pole nebo spojoveho seznamu

Seznam funkci s sturct:
push
top
pop

create //vytvorit prazdny zasobnik
destroy

empty
full


Podmineny vyraz (Ternarni operator)

x = P? V1:V2 // hodnota bud v1 anebo v2, zalezi na podmince
if(p) x = v1
else x = v2 //pokud podminka neplati


hw:prevadec z desitkove do 16kove soustavy, muzeme pouzit zasobnik.

*/