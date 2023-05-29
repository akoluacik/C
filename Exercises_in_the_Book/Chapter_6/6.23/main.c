/*************************************************************************************************

If pen is down, turtle draws something, otherwise, it moves freely without writing anything.

Assume turtle always starts (0, 0) and and its pen is up.

1 -> Pen up
2 -> Pen down
3 -> Turn right
4 -> Turn left
5, x -> Move forward x spaces
6 -> Print the floor matrix
9 -> End of the program

**************************************************************************************************/

#include<stdio.h>
int Floor[50][50] =  {0};

void move(int, int, int);
void draw();

int main(){
	int command; 
	int pen; // initially pen is up.
	int direction; //right = 0, left = 1
	int position_main; // to hold position
	
	pen = 0;
	position_main = 0;
	while(command != 9){
		printf("Enter a command: "); scanf("%d", &command);
		switch(command){
			case 1:
				pen = 0;
				printf("Case 1 pen is 0 means up\n");
				break;
			case 2:
				pen = 1;
				printf("Case 2 pen is 1 means down\n");
				break;
			case 3:
				direction = 0;
				printf("Case 3, direction is 0\n");
				break;
			case 4:
				direction = 1;
				printf("Case 4, direction is 1\n");
				break;
			case 5:
				printf("%s", "Enter how much unit the turtle forward: "); scanf("%d", &position_main);
				printf("\nmove is called!");
				move(pen, position_main, direction);
				break;
			case 6:
				draw();
				break;
		}
	}
	
	return 0;
}

void move(int pen, int position, int direction) {
	
	if(pen == 0) return;
	
	static int position_func;
	int i;
	int j;
	
	position_func = 0;
	
	if(direction == 1) { // if left
		for(i = position_func;i < position_func + position; i++){
			for(j = 1;j <= position; j++){
				Floor[i][position_func - j] = 1;
			}
		}
		
		position_func -= position;
	
	} else { // if right
		for(i = position_func;i < position + position_func; i++){
			for(j = position_func;j < position + position_func; j++){
				Floor[i][j] = 1;
			}
		}
		position_func += position;
	
	}
	printf("position_func: %d\n", position_func);
}

void draw() {
	int i, j;
	for(i = 0; i < 50; i++){
		for(j = 0;j < 50; j++){
			//printf("floor[%d][%d] = %d\n", i, j, floor[i][j]);
			if(Floor[i][j] == 1) {
				printf("%s", "*");
			} else{
				printf("%c", ' ');
			}
		}
		puts(" ");
	}
}
