#include<stdio.h>

void TowerOfHanoi(int, int, int, int);
int main() {
	TowerOfHanoi(4, 1, 2, 3);
	return 0;
}


void TowerOfHanoi(int nodisk, int prevpeg, int nextpeg, int temp){
	if(nodisk == 1){
		printf("%d -> %d\n", prevpeg, nextpeg);
		return;
	}
	TowerOfHanoi(nodisk - 1, prevpeg, temp, nextpeg);
	printf("%d -> %d\n", prevpeg, nextpeg);
	TowerOfHanoi(nodisk - 1, temp, nextpeg, prevpeg);
}
