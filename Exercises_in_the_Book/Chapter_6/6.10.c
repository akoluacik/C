#include<stdio.h>

int main(){
	int ranges[9] = {0};
	int salary, grossSales, i;
	while(grossSales > 0) {
		printf("%s", "Enter the gros sales of a salesperson: ");scanf("%d", &grossSales);
		salary = 200 + grossSales * 0.09;
		if(salary > 1000) ++ranges[9];
		else if(salary >= 200) ++ranges[salary / 100];
	}
	
	for(i = 2;i < 10; i++){
		printf("$%d00 - $%d99: %d\n", i, i, ranges[i-2]);
	}
	return 0;
}