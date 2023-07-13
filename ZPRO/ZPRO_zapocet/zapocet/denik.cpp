#include "denik.hpp"
#include <fstream>

struct denik
{
    prvek *zacatek;
    prvek *konec;
    unsigned int capacita;
};

denik *vytvoritDenik()
{
    denik *d = new (nothrow) denik;
    if (!d){
        cerr << "Nepodarilo se vytvorit denik" << endl;
        return nullptr;
    }
    prvek *docasny = new (nothrow) prvek;
    if(!docasny){
        cerr << "Nepodarilo se vytvorit prvek" << endl;
        return nullptr;
    }
    d->zacatek = docasny;
    d->konec = d->zacatek;
    d->capacita = 0;
    return d;
}


bool nacistZeSouboru (denik *d, string soubor)
{
    ifstream nacitanySoubor;
    nacitanySoubor.open(soubor); //otevre soubor ze ktereho se nacitaji veci
    string radek;
    if (!nacitanySoubor.is_open()) // pokud se soubor neotevrel
    {
        cerr << "Soubor: " << soubor << " se neotevrel" << endl;
        return false;
    }else {
        while(nacitanySoubor){ // ekvivalentni k nacitanySoubor.good()
            if(nacitanySoubor.eof()) // eof je end of file
            {
                break;
            }
            getline (nacitanySoubor, radek); //nacte radek ze souboru
            int i = 0;
            int typ = 0; // typ ve kterem se nachazim (autor, zanr atd)
            mojeData md;
            string docasny; // uklada se textovy retezec napr. autor nebo titul atd
            while(true){
                if(radek[i] == ';') //rozdeli radek podle stredniku
                {
                    if(typ == 0){
                        md.autor = docasny;
                    }else if(typ == 1){
                        md.titul = docasny;
                    }else if (typ == 2){
                        md.zanr = docasny;
                    }else if (typ == 3){
                        md.rokVydani = stoi(docasny); //stoi prevede string na int
                    }else {
                        md.pocetStran = stoi(docasny);
                    }
                    typ++;
                    docasny = "";
                }else {
                    docasny += radek[i]; // prida charakter na pozici i k docasnemu rezetezci
                }
                if (radek[i] == '\0' || radek[i] == '\n' || radek[i] == EOF)
                //ukonceny retezec || novy radek || end of file
                {
                    break;
                }
                i++;
            }
            pridatPrvek(d, md); 
        }
    }
    nacitanySoubor.close();
    return true;
}

bool zapsatDoSouboru (denik *d, string soubor)
{
    ofstream zapisovanySoubor; //outputFile
    zapisovanySoubor.open(soubor);
    if(!zapisovanySoubor.is_open()){
        cerr << "Nepovedlo se otevrit soubor pro zapsani" << endl;
        return false;
    }else {
        string zapisovanyRetezec;
        for(prvek *pomocny = d->zacatek; pomocny != d->konec; pomocny = pomocny->dalsi){
            string vystup;
            vystup = pomocny->data.autor + ";";
            vystup += pomocny->data.titul + ";";
            vystup += pomocny->data.zanr + ";";
            vystup += to_string(pomocny->data.rokVydani) + ";";
            vystup += to_string(pomocny->data.pocetStran) + ";";
            if (pomocny->dalsi == d->konec){
                zapisovanyRetezec += vystup;
            }else{
                zapisovanyRetezec += vystup + "\n";
            }
        }
        zapisovanySoubor << zapisovanyRetezec;
        zapisovanySoubor.close();
    }
    return true;
}

void pridatPrvek (denik *d, mojeData data)
{
    prvek *docasny = new (nothrow) prvek;
    if(!docasny){
        cerr << "Nepodarilo se vytvorit prvek" << endl;
        return;
    }
    d->konec->data = data;
    d->konec->dalsi = docasny;
    docasny->dalsi = nullptr;
    d->konec = docasny;
    d->capacita++;
}

void smazatPrvek (denik *d)
{
    if(!jePrazdny(d)){
        prvek *docasny = new (nothrow) prvek;
        if (!docasny){
            cerr << "Nepodarilo se vytvorit prvek" << endl;
            return;
        }
        docasny = d->zacatek;
        d->zacatek = d->zacatek->dalsi;
        delete docasny;
        d->capacita--;
    }
}

void smazatPrvky (denik *d)
{
    while (!jePrazdny(d))
    {
        smazatPrvek(d);
    }
}

void smazatDenik (denik *&d){
    smazatPrvky(d);
    delete d->zacatek;
    delete d;
}

bool jePrazdny (denik *d)
{
    return d->capacita == 0;
}

void smazatZa (denik *d, prvek *kde)
{
    prvek *tmp = kde->dalsi;
    if (tmp == d->konec){
        d->konec = kde;
        kde->dalsi = tmp->dalsi;
    }else{
        kde->dalsi = tmp->dalsi;
    }
    delete tmp;
    d->capacita--;
}

void vytiskniDenik (denik *d){
    cout << "---------------------------------------------" << endl;
    for (prvek *pomocny = d->zacatek; pomocny != d->konec; pomocny = pomocny->dalsi) 
    //for(pocatecni hodnota; dokud je to pravda; o kolik se prida, na co se to zmeni)
    { 
        cout << pomocny->data.autor << "    ";
        cout << pomocny->data.titul << "    ";
        cout << pomocny->data.zanr << "    ";
        cout << pomocny->data.rokVydani << "    ";
        cout << pomocny->data.pocetStran << "    " << endl;
        cout << "---------------------------------------------" << endl;
    }
}

bool smazatAutora (denik *d, string autor)
{
    if (d->zacatek->data.autor == autor)
    {
        smazatPrvek(d); // maze prvni prvek se seznamu
        return true;
    }
    for (prvek *pomocny = d->zacatek; pomocny != d->konec; pomocny = pomocny->dalsi)
    {
        if (pomocny->dalsi->data.autor == autor){
            smazatZa(d, pomocny);
            return true;
        }
    }
    return false;
}

bool smazatTitul (denik *d, string titul)
{
    if (d->zacatek->data.titul == titul)
    {
        smazatPrvek(d); // maze prvni prvek se seznamu
        return true;
    }
    for (prvek *pomocny = d->zacatek; pomocny != d->konec; pomocny = pomocny->dalsi)
    {
        if (pomocny->dalsi->data.titul == titul){
            smazatZa(d, pomocny);
            return true;
        }
    }
    return false;
}

void najitAutora (denik *d, string autor)
{
    for (prvek *docasny = d->zacatek; docasny != d->konec; docasny = docasny->dalsi){
        if (docasny->data.autor == autor){
            cout << "Author: " << autor << " exists!" << endl;
        }
    }
}

void najitTitul (denik *d, string titul)
{
    for (prvek *docasny = d->zacatek; docasny != d->konec; docasny = docasny->dalsi){ 
        if (docasny->data.titul == titul){
            cout << "Titul: " << titul << " exists!" << endl;
        }
    }
}


/*
bool vymazat(denik *d, mojeData data)
{
    prvek *tmp = najít(d, mojeData data);
    if (!tmp){
        return false;
    }
    tmp->data = tmp->dalsi->data;
    smazatZa(d, tmp);
    return true;
}
*/
