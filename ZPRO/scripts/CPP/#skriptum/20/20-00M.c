// Soubor 20-00M.c
// Pouziti nastroju z <io.h> (schema)
// Jde o nestandardni soucast C a C++

#include <io.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
	int Soubor;
	Soubor = open("C:\\WORK\\DATA.DTA", O_CREAT|O_TEXT);
	if(Soubor == -1) perror("Nìco je jinak: ");
	/* ....*/
	close(Soubor);
}

