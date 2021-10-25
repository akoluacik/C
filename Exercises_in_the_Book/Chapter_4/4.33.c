#include<stdio.h>
int main() {
	
	int i, n;
	for(i = 1;i <= 100; i++){
		n = i;
		while(n != 0){
			if(n == 100) {
				printf("%s", "C");
				n -= 100;
			} else if(n >= 90){
				printf("%s", "XC");
				n -= 90;
			} else if(n >= 50){
				printf("%s", "L");
				n -= 50;
			} else if(n >= 40){
				printf("%s", "XL");
				n -= 40;
			} else if(n >= 10){ 
				printf("%s", "X");
				n -= 10;
			} else if(n >= 9) {
				printf("%s", "IX");
				n -= 9;
			} else if(n >= 5) {
				printf("%s", "V");
				n -= 5;
			} else if(n >= 4) {
				printf("%s", "IV");
				n -= 4; 
			} else if(n >= 1) {
				printf("%s", "I");
				n -= 1;
			}
		}
		puts("");
	}
	return 0;
}