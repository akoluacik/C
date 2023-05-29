#include<stdio.h>

int main(){
	int i;
	int j;

	for(i = 0; i < 255; i++){
		if(i % 10 == 0) // constraint: 10 characters per line 
			puts("");
		printf("%c:%d ", i, i);
	}
	return (0);
}
