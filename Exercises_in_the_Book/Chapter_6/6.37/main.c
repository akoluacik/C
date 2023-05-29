#include <stdio.h>

int argmin(int [], size_t);

int main(){
	
	int arr[] = {7, 2, 15, 48, 61, 44, 4, 17, 8};
	size_t len;
	int min;
	
	min = argmin(arr, len);
	len = sizeof(arr) / sizeof(int);
	printf("argmin(arr): %d\n", min);
	return 0;
}

int argmin(int arr[], size_t len){
	if(len == 1) return arr[0]; // stop processing and return the element
	return (arr[len - 1] < argmin(arr, len - 1)) ? arr[len - 1] : argmin(arr, len - 1);
}
