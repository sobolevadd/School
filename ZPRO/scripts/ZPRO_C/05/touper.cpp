#include <iostream>

using namespace std;

int ToUpper(int c)
{
	if((c < 'a') || (c > 'z'))
	{
		return c;
	}
	return c - 'a' + 'A';
}

const char malaPismena[] =  "������������������"; 
const char velkaPismena[] = "�����ͼ�����؊���ݎ";

int NajdiMale(int c)
{
	int i = 0;
	while(malaPismena[i])
	{
		if(malaPismena[i] == c)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int NaVelka(int c)
{
	if((c >= 'a') && (c <= 'z'))
	{
		return c - 'a' + 'A';
	}
	int i = NajdiMale(c);
	if(i != -1)
	{
		return velkaPismena[i];
	}
	return c;

}

int main()
{
	cout << (char)ToUpper('f') << endl;
	char c = '�';
	cout << c << (char)NaVelka(c) << endl ;
}