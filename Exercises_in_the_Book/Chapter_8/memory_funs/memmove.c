#include <stdio.h>
#include <string.h>

/*
memmove does same thing with memcpy, but memmove is more efficient
if there is an overlapping.
*/


int main(){
	char x[] = "Home Sweet Home";
	printf("%s%s\n", "The string in array x before memmove is: ", x);
	printf("%s%s\n", "The string in array x after memmove is: ", (char *) memmove(x, &x[2], 6));
	// yukar�daki �rnek 3.karakterden itibaren 6 karakter kopyal�yor ve en ba�a at�yor.
	// yani Home Sweet Home ifadesinden me Swe k�sm�n� al�yor ve ilk 6 karakterin yerine koyuyor.
	// orijinal dizide ilk 6 karakter Home Sw, bunun yerine me Swe koyuluyor.
	// dizideki kalan ifade elde edilenin sonuna ekleniyor.
	// me Sweweet Home
}
