#include <stdio.h>

void printArray(int [][4]);
void getMin(int [][4]);
void getMax(int [][4]);
void average(int [][4]);

int main(){
	
	size_t choice;
	int studentGrades[3][4] = 
		{ { 77, 68, 86, 73 },
		  { 96, 87, 89, 78 },
		  { 70, 90, 86, 81 } };
	
	void (*f[4])(int [][4]) = {printArray, getMin, getMax, average};
	printf("%s","0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print the average on al tests for each student\n4 End program: ");
	scanf("%u", &choice);
	while(choice>=0 && choice <4){
		(*f[choice])(studentGrades);
		printf("\n%s","0 Print the array of grades\n1 Find the minimum grade\n2 Find the maximum grade\n3 Print the average on al tests for each student\n4 End program: ");
		scanf("%u", &choice);
	}
	printf("\nProgram was ended!");
	return 0;
}


void printArray(int arr[][4]){
	size_t i, j;
	printf("Grades of the students:\n");
	printf("\t\t[1]\t[2]\t[3]\t[4]\n");
	for(i=0;i<3;i++){
		printf("Student %d\t", i);
		for(j=0;j<4;j++){
			printf("%d\t", arr[i][j]);
		}
		puts(" ");
	}
	puts("\n");
}

void getMin(int arr[][4]){
	int minGrade = 100;
	size_t i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(arr[i][j]<minGrade)
				minGrade=arr[i][j];
				
	printf("\nMinimum grade is:%d", minGrade);
}

void getMax(int arr[][4]){
	int maxGrade = 0;
	size_t i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(arr[i][j]>maxGrade)
				maxGrade=arr[i][j];
	
	printf("\nMaximum grade is:%d", maxGrade);
}

void average(int arr[][4]){
	double avg;
	int sum=0;
	size_t i, j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			sum += arr[i][j];
			
	avg = sum/12.0;
	printf("\nThe whole average is: %lf\n", avg);
}

