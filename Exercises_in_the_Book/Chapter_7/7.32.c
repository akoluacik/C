#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillResponses(int [][10],int,int);
void printResponses(int [][10]);
double average(int [][10], int);
void realizeSurvey(int [][10]);

int main(){
	
	char *topics[] = {"Global Environment", "Military Spending", "Political Issues", "Education", "Foreign Politics"};
	int responses[5][10] = {0};
	
	srand(time(NULL));
	realizeSurvey(responses);
	printResponses(responses);
	return 0;
}

void fillResponses(int responses[][10], int rating, int issue){
	
	responses[issue][rating]++;
}

void realizeSurvey(int responses[][10]){
	int ctr, issue;
	
	for(issue=0;issue<5;issue++){
		for(ctr=0;ctr<100;ctr++){
			fillResponses(responses, rand()%10, issue);
		}
	}
}

void printResponses(int responses[][10]){
	int i ,j;
	printf(" 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\t Average\n");
	for(i=0;i<5;i++){
		for(j=0;j<10;j++){
			printf(" %d\t", responses[i][j]);
		}
		printf("%lf\n", average(responses, i));
	}
}

double average(int responses[][10], int row){
	int i, sum = 0;
	for(i=0;i<10;i++){
		sum = sum + (i+1)*responses[row][i];
	}
	return sum/10.0;
}


