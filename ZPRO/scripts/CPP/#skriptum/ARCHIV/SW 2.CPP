// priklad na pouziti prikazu switch

#include <stdio.h>
#include <conio.h>

int I;

void pozdrav(int i)
{
 switch(i) {
  case 0: printf("Ahoj.\n");
          break;
  case 1: printf("Bud pozdraven.\n");
          break;
  case 2: printf("Te pic.\n");
          break;
  case 3: printf("Uctiva poklona.\n");
          break;
  case 4: printf("Dobrou noc.\n");
          break;
  default:printf("Trhni si nohou.\n");
 }
}

int main()
{
 clrscr();
 printf("Vyber si zpusob pozdravu - cele cislo 0 - 4: ");
 scanf("%d", &I);
 pozdrav(I);
 getch();
 return 0;
}