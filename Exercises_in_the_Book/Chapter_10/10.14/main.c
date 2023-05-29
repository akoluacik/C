#include <stdio.h>
#include <string.h>
void reverse(unsigned int);
void print(int [], int);
int main(){
	unsigned int n;
	printf("%s", "Enter a non-negative number:");scanf("%u", &n);
	reverse(n);
	return 0;
}

void reverse(unsigned int x){
	unsigned int mask = 1 << 31;
	int res[32];
	size_t i;
	for(i = 0; i < 32; ++i){
		res[i] = (mask & x) ? 1 : 0;
		x <<= 1;
	}
	//printf("\n%d\n", strlen(res));
	print(res, 32);
}

void print(int s[], int len){
	size_t i;
	printf("%s\n", "Number in bit format:");
	for(i = 0; i < len; ++i)
		printf("%d", s[i]);
	
	puts("\nNumber in bits but reverse order:");
	
	for(i = 1; i <= 32; i++)
		printf("%d", s[len - i]);
}
