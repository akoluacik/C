#include<stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int, int, int, int);

int main(int argc, char *argv[])
{
	int nodisk;
	int prevpeg;
	int nextpeg;
	int temp;

	if (argc == 1)
	{
		nodisk = 4;
		prevpeg = 1;
		nextpeg = 2;
		temp = 3;
	}
	else if(argc == 2)
	{
		nodisk = atoi(argv[1]);
		prevpeg = 1;
		nextpeg = 2;
		temp = 3;
	}
	else if(argc == 3)
	{
		nodisk = atoi(argv[1]);
		prevpeg = atoi(argv[2]);
		nextpeg = 2;
		temp = 3;
	}
	else if(argc == 4)
	{
		nodisk = atoi(argv[1]);
		prevpeg = atoi(argv[2]);
		nextpeg = atoi(argv[3]);
		temp = 3;
	}
	else if(argc == 5)
	{
		nodisk = atoi(argv[1]);
		prevpeg = atoi(argv[2]);
		nextpeg = atoi(argv[3]);
		temp = atoi(argv[4]);
	}
	TowerOfHanoi(nodisk, prevpeg, nextpeg, temp);
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
