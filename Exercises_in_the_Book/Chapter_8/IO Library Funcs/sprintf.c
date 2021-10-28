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
bunun için ilk parametreye oluþturmak istediðin string deðiþkenini koyç
arkasýndan formatý yaz. string için %s, char için %c ve int için %d gibi.
eðer concat yapmak istersen format kýsmýna orjinal stringide belirten specifieri de koy
sonra en sona kaynaðý yaz.
*/
/*
snprintf de ayný iþi yapar ve ayný þeyi döndürür. Ama formattan önce boyut bildiren
bir integer girilmeli.
*/
