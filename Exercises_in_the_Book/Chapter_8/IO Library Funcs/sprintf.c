#include <stdio.h>
#include <string.h>
/*
Use sprintf to print the values of integer variables x, y and z into array s1.
Each value should be printed with field width of 7.
*/
int main(){
	int x = 3, y=4, z=5;
	char s1[22];
	char s2[]="yay", s3[]="piuuw";
	sprintf(s1, "%7d%7d%7d",x,y,z);
	int len = sprintf(s1, "%s%s%s", s1,s2,s3);
	printf("%s", s1);
}

/*
sprintf'i strcat yerine kullanabilirsin.
bunun i�in ilk parametreye olu�turmak istedi�in string de�i�kenini koy�
arkas�ndan format� yaz. string i�in %s, char i�in %c ve int i�in %d gibi.
e�er concat yapmak istersen format k�sm�na orjinal stringide belirten specifieri de koy
sonra en sona kayna�� yaz.
*/
/*
snprintf de ayn� i�i yapar ve ayn� �eyi d�nd�r�r. Ama formattan �nce boyut bildiren
bir integer girilmeli.
*/
