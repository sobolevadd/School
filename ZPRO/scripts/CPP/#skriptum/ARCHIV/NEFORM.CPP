#include <fstream.h>

fstream F("data.d", ios::out|ios::binary);


int main(){
 if(!F) return 1;
 for(int i = 10; i < 20; i++) F.write((char*)&i,2);
 F.close();
 F.open("data.d", ios::in|ios::binary);
 if(!F) return 1;
 do{
  F.read((char*)&i, 2);
  if(!F) break;
  cout << i << endl;
 } while(1);
 F.clear();
 F.close();

 return 0;
}