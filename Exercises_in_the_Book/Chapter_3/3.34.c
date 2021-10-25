#include<stdio.h>

int main(){
	
	int i,j,n, k=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%d ", ++k);
		}
		printf("%s", "\n");
	}
	
	return 0;
}