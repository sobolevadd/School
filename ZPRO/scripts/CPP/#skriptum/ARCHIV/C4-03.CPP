#include <graphics.h>
#include <iostream.h>
#include <process.h>
#include <conio.h>

/******************** P59klad C4-03 *********************/

const char *cesta = "C:\\aplikace\\prekl\\bc31\\bgi";

// V˜‡tov˜ typ s indexy metod, p©edefinovan˜ch
// v odvozen˜ch t©¡d ch
enum met { ZOBRAZ, H_POSUN, _met};

class go
{
 public:
  go();
  ~go();
  void nakresli();
  void smaz();
  void zobraz(int barva);
  void h_posun(int okolik);
// Typ: ukazatel na metodu
  typedef void (go::*prvtab)(int);
// Nov  metoda
  void zavolej(int met, int par);
 protected:
  int sviti;
// ukazatel na prvn¡ prvek tabulky
  prvtab *uTM;
 private:
// Pole ukazatel– na p©edefinovan‚ metody
  static prvtab TM[_met];
  friend class go_init;
};

go::prvtab go::TM[_met] = {0,};

typedef go* pgo;

class bod: public go{
 public:
  bod(int xx, int yy);
  ~bod();
  void zobraz(int barva);
  void moveto();
  void lineto();
  void h_zmena(int okolik);
  void h_posun(int okolik);
// Typ: ukazatel na metodu
  typedef void (bod::*prvtab)(int);
 private:
  int x,y;
// Pole ukazatel– na metody
  static prvtab TM[_met];
  friend class go_init;
};

bod::prvtab bod::TM[_met] = {0,};

class usecka: public go {
 public:
  usecka(int xx1, int yy1, int xx2, int yy2);
  ~usecka();
  void zobraz(int barva);
  void h_posun(int okolik);
// Typ: ukazatel na metodu
  typedef void (usecka::*prvtab)(int);
 private:
  bod poc, kon;
// Pole ukazatel– na metody
  static prvtab TM[_met];
//  static void init();
  friend class go_init;
};

usecka::prvtab usecka::TM[_met] = {0,};


class go_init {
 public:
  go_init();
};

go_init::go_init(){
  static int hotovo = 0;
  if(!hotovo) {
   hotovo = 1;
  // inicializace tabulky t©¡dy go
   go::TM[ZOBRAZ] = &go::zobraz;
   go::TM[H_POSUN] = &go::h_posun;
  // inicializace tabulky t©¡dy bod
   bod::TM[ZOBRAZ] = &bod::zobraz;
   bod::TM[H_POSUN] = &bod::h_posun;
  // inicializace tabulky t©¡dy usecka
   usecka::TM[ZOBRAZ] = &usecka::zobraz;
   usecka::TM[H_POSUN] = &usecka::h_posun;
  }
}

go::go()
: sviti(0), uTM(&go::TM[0])
{}

go::~go()
{}

void go::zavolej(int metoda, int param)
{
 (this->* uTM[metoda])(param);
}

void go::nakresli()
{
  sviti = 1;
  zavolej(ZOBRAZ, WHITE);
}

void go::smaz()
{
  sviti = 0;
  zavolej (ZOBRAZ, BLACK);
}

void go::zobraz(int)
{
 cout << "Jak se zobraz¡ obecn˜ grafick˜ objekt?"<< endl;
 getch ();
 exit(1);
}

void go::h_posun(int) {
 cout << "Jak se posune obecn˜ graficj˜ objekt?" << endl;
 getch ();
 exit(1);
}

bod::bod(int xx, int yy)
: x(xx), y(yy)
{
  (prvtab *)uTM = TM;
}

bod::~bod()
{}

void bod::zobraz(int barva)
{
 putpixel(x,y,barva);
}


void bod::moveto()
{
 ::moveto(x,y);
}

void bod::lineto()
{
 ::lineto(x,y);
}

void bod::h_zmena(int okolik){
  x += okolik;
}

void bod::h_posun(int okolik) {
 smaz();
 h_zmena(okolik);
 nakresli();
}

usecka::usecka(int xx1, int yy1, int xx2, int yy2)
: poc(xx1, yy1), kon(xx2, yy2)
{
  (prvtab *)uTM = TM;
}

usecka::~usecka()
{}

void usecka::zobraz(int barva)
{
  setcolor(barva);
  poc.moveto();
  kon.lineto();
}

void usecka::h_posun(int okolik) {
 smaz();
 poc.h_zmena(okolik);
 kon.h_zmena(okolik);
 nakresli();
}

void test()
{
 int gd = DETECT, gm;
 initgraph(&gd, &gm, cesta);
 usecka cara(10,20,50,80);
 pgo ugo = &cara;
 ugo->nakresli();
 getch();
 ugo->zavolej(H_POSUN,100);
 getch();
 ugo->smaz();
 getch();
 closegraph;
};

static go_init goinit;

int main(){
 go g;
 test();
 return 0;
}
