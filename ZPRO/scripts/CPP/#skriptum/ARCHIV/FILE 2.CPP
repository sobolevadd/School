// Priklad: zapouzdreni prace se soubory
// do objektovych typu
#include <stdio.h>
#include <string.h>

class file {
  FILE *f;
 public:
  enum stav {nedefinovan=0,
             zavren     =1,
             vstup      =2,
             vystup     =4
            };
 private:
  stav Stav;
  char jmeno[100];
 public:
  file();
  file(char*, stav = vstup|vystup);
  int otevri(char*, stav = vstup|vystup);
  int zavri();
  ~file();
  int zapis(int);
};

file::file() {
 f = NULL;
 Stav = nedefinovan;
 jmeno[0]='\0';
}

int file::otevri(char* jm, stav St)
{
 char *vs="r", *vy = "w", *vv = "r+";
 char *re;
 switch(St) {
  case vstup: re = vs; break;
  case vystup:re = vy; break;
  case vstup|vystup: re = vv; break;
  default: return 0;
 }
 f = fopen(jm, re);
 if(!f) return 0;
 Stav = St;
 strcpy(jmeno, jm);
 return 1;
}

file::file(char* jm, stav St)
{
 otevri(jm, St);
}

int file::zavri() {
 if(Stav > zavren) return fclose(f);
 else return 0;
}

file::~file() {
 zavri();
}

int file::zapis(int i) {
 return fprintf(f,"%d", i);
}


int main()
{
  file F;
  F.otevri("vystup.dta", file::vystup);
  for(int i = 0; i < 10; i++)F.zapis(i);
  return 0;
}
