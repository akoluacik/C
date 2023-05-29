#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MODULUS 34
#define EXPONENTIAL 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void printMemory(float memory[], float accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand);


int main(){
	
	printf("%s\n","*** Welcome to Simpletron! ***");
	printf("%s\n", "*** Please enter your program one instruction ***");
	printf("%s\n", "*** (or data word) at a time. I will type the ***");
	printf("%s\n", "*** location number and a question mark (?). ***");
	printf("%s\n", "*** You then type the word for that location. ***");
	printf("%s\n", "*** Type the sentinel -99999 to stop entering ***");
	printf("%s\n\n", "*** your program. ***");
	
	float accumulator = 0.0f;
	int instructionCounter=0, operationCode=0, operand=0, instructionRegister=0;
	float memory[MAX]={0.0f};
	
	printf("%-25s%+05f\n","Accumulator:",accumulator);
	printf("%-28s%02d\n","instructionCounter:", instructionCounter);
	printf("%-25s%+05d\n","instructionRegister:",instructionRegister);
	printf("%-28s%02d\n","operationCode:", operationCode);
	printf("%-28s%02d\n","operand:", operand);
	
	
	
	
	while(1){
		printf("%s", "Enter 4-digit word: ");scanf("%f", &memory[instructionCounter]);
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch(operationCode){
		case READ:
			scanf("%f", &memory[operand]);
			while(memory[operand]<-9999 || memory[operand]>9999){
				printf("Number should be within -9999 to 9999: "); scanf("%d", &memory[operand]);
			}
			
			instructionCounter++;
			break;
		case WRITE:
			printf("%f", memory[operand]);
			instructionCounter++;
			break;
		case LOAD:
			accumulator = memory[operand];
			instructionCounter++;
			break;
		case STORE:
			memory[operand] = accumulator;
			instructionCounter++;
			break;
		case ADD:
			accumulator += memory[operand];
			instructionCounter++;
			break;
		case SUBTRACT:
			accumulator -= memory[operand];
			instructionCounter++;
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			instructionCounter++;
			break;
		case DIVIDE:
			if(memory[operand] == 0.0f){
				printf("\n\n*** [ERROR]: Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***");
				printMemory(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
				exit(0);
			}
			accumulator /= memory[operand];
			instructionCounter++;
			break;
		/*case MODULUS:
			accumulator = accumulator % memory[operand];
			instructionCounter++;
			break;*/
		case EXPONENTIAL:
			accumulator = pow(accumulator, memory[operand]);
			instructionCounter++;
			break;
		case BRANCHNEG:
			if(accumulator < 0.0f) instructionCounter = operand;
			else printf("[ERROR] Accumulator is not NEGATIVE!\n");
			break;
		case BRANCHZERO:
			if(accumulator == 0.0f) instructionCounter = operand;
			else printf("[ERROR] Accumulator is not 0(ZERO)!\n");
			break;
		case BRANCH:
			instructionCounter = operand;
			break;
		case HALT:
			printMemory(memory,accumulator,instructionCounter,instructionRegister,operationCode,operand);
			instructionCounter++;
			break;
		}
	
	}
	
	
	return 0;
}

void printMemory(float memory[], float accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand){
	int adder = 0, i, j;
	printf("\n\n%s\n", "*** Simpletron execution terminated ***");
	printf("%s", "REGISTERS:\n");
	printf("%-25s%+05f\n","Accumulator:",accumulator);
	printf("%-28s%02d\n","instructionCounter:", instructionCounter);
	printf("%-25s%+05d\n","instructionRegister:",instructionRegister);
	printf("%-28s%02d\n","operationCode:", operationCode);
	printf("%-28s%02d\n","operand:", operand);
	printf("%13s  %6s %7s %7s %7s %7s %7s %7s %7s %7s\n", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
	for(i=0;i<10;i++){
		printf("%d", i);
		for(j=0;j<10;j++){
			printf("\t%+05.2f", memory[i+j+adder]);
		}
		adder += 9;
		puts(" ");
	}
}


