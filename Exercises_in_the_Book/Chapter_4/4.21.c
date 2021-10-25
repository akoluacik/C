#include<stdio.h>
int main(){
	int i,j;
	for(i=0;i<255;i++){
		if(i%10 == 0) puts(""); // constraints: 10 characters per line
		printf("%c:%d ", i, i);
	}
	return 0;
}
