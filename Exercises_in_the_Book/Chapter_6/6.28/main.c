#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20

int randomGen();

int main(){
	int i;
	int j;
	int k;
	int length;
	int arr[SIZE];

	length = 20;
	srand(time(NULL));
	for(i = 0;i < SIZE; i++)
		arr[i] = randomGen();
	for(i = 0;i < SIZE; i++)
		printf("%d ", arr[i]);
	for(i = 0;i < length; i++){
		for(j = i + 1; j < length; j++){
			if(arr[i] == arr[j]){
				for(k = j; k < length - 1; k++){
					arr[k] = arr[k + 1];
				}
				length--; // to achieve possible smallest array length
				j--;
			}
		}
	}
	
	
	printf("\nArray elements after deleting duplicates : \n");
    for(i=0; i<length; i++)
    {
        printf("%d ", arr[i]);
    }
	
	
	
	
	
}

int randomGen(){
	return rand()%20;
}


