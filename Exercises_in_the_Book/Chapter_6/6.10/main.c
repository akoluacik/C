#include <stdio.h>
#include <stdlib.h>

#define ZERO_INITIALIZE(X, LEN) for (size_t i = 0; i < LEN; i++) \
									X[i] = 0;
							
int main(){
	int ranges[9];
	int salary;
	int grossSales;
	int i;

	ZERO_INITIALIZE(ranges, 9);

	while(grossSales > 0) {
		printf("%s", "Enter the gros sales of a salesperson: ");scanf("%d", &grossSales);
		salary = 200 + grossSales * 0.09;
		if(salary > 1000) ++ranges[9];
		else if(salary >= 200) ++ranges[salary / 100];
	}
	for(i = 2;i < 10; i++)
		printf("$%d00 - $%d99: %d\n", i, i, ranges[i-2]);
	return 0;
}