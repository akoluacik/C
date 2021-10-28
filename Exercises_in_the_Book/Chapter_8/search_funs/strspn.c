#include <stdio.h>
#include <string.h>

/*

strspn, ikinci parametredeki HER BIR KARAKTER ikinci DIZIDE ka� defa
ge�iyorsa onu d�nd�r�r.

T de�eri ilk dizide 1 defa,
h de�eri ilk dizide 1 defa
e de�eri ikinci dizide 2 defa
.
.
bo�luk ilk dizide 3 defa
.
.
.
toplam 13.

*/


int main(){
	const char *string1 = "The value is 3.14159";
	const char *string2 = "aehi lsTuv";
	
	printf("%s%s\n%s%s\n\n%s\n%s%u",
		"string1 = ", string1, "string2 = ", string2,
		"The length of the initial segment of string1",
		"containing only chars from string2 = ", strspn(string1, string2)); 	
}
