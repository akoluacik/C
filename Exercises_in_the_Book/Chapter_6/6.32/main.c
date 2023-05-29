#include<stdio.h>

#define SIZE 100

size_t binarySearch(const int [], int, size_t, size_t);

int main() {
	int arr[SIZE];
	int i, key;
	size_t index;
	
	for(i = 0;i < SIZE; i++){
		arr[i] = 2 * i;
	}
	printf("Enter search key: "); scanf("%d", &key);
	index = binarySearch(arr, key, 0, SIZE - 1);
	if(index != -1)
		printf("Value %d found at %ld\n", key, index);
	else
		printf("%s", "Key not found!");
	return 0;
}

size_t binarySearch(const int arr[], int searchKey, size_t low, size_t high){
	// loop until low index is greater than high index
	size_t middle;
	
	middle = (low + high) / 2;
	if(low > high) return -1; // key not found, stop the process.
	else if(searchKey == arr[middle]) return middle;
	else if(searchKey < arr[middle]) binarySearch(arr, searchKey, low, middle - 1); // if key is smaller than the middle, search the key inside the first half.
	else binarySearch(arr, searchKey, middle + 1, high); // else, search it inside the second half.
}