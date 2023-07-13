#include "denik.hpp"
#include <fstream>

int main()
{
    denik *d;
    d = vytvoritDenik();
    nacistZeSouboru(d, "denik_in.txt");
    string a = "Ales";
    //string b = "dr";
    smazatAutora(d, a);
    //smazatTitul(d, b);
    //nacistZeSouboru(d, "denik_in.txt");
    zapsatDoSouboru(d, "denik_out.txt");
    /*a = "Ales";
    b = "rs";
    smazatAutora(d, a);
    smazatAutora(d, a);
    smazatTitul(d, b);
    vytiskniDenik(d);
    smazatPrvky(d);
    cout << "*********************************" << endl;
    nacistZeSouboru(d, "denik_out.txt");
    nacistZeSouboru(d, "denik_out.txt");*/
    vytiskniDenik(d);
    smazatDenik(d);
}

/*
 denik *d;
    d = vytvoritDenik();
    nacistZeSouboru(d, "denik_in.txt");
    string a = "Adam";
    string b = "dr";
    smazatAutora(d, a);
    nacistZeSouboru(d, "denik_in.txt");
    zapsatDoSouboru(d, "denik_out.txt");
    a = "Ales";
    smazatAutora(d, a);
    smazatAutora(d, a);
    smazatTitul(d, b);
    vytiskniDenik(d);
    smazatPrvky(d);
    cout << "*********************************" << endl;
    nacistZeSouboru(d, "denik_out.txt");
    nacistZeSouboru(d, "denik_out.txt");
    vytiskniDenik(d);
    smazatDenik(d);
    */