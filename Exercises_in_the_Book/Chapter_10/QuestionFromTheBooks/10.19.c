#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct {
	char fname[20];
	char lname[20];
	int day, month, year;
	double height, weight;
} HealthProfile;

void setHealthProfile(HealthProfile *, char [], char [], int, int, int, double, double);

int calculateAge(HealthProfile);
int calculateMaxHeartRate(HealthProfile);
double calculateTargetHeartRate(HealthProfile);
double calculateBMI(HealthProfile);

int main(){
	HealthProfile hp;
	char name[20], surname[20], temp;
	int day, month, year;
	double height, weight;
	printf("%s", "Enter your name, surname, day, month and year of your birthday, your height and weight, respectively:"); scanf("%19s %19s %d %d %d %lf %lf", name, surname, &day, &month, &year, &height, &weight);
	setHealthProfile(&hp, name, surname, day, month, year, height, weight);
	printf("%s\n", hp.lname);
	printf("%d\n", hp.year);
	printf("Age: %d\n", calculateAge(hp));
	printf("Maximum Heart Rate: %d\n", calculateMaxHeartRate(hp));
	printf("Target Heart Rate: %lf\n", calculateTargetHeartRate(hp));
	printf("Body-Mass Index: %lf", calculateBMI(hp));
	return 0;
}

void setHealthProfile(HealthProfile *hp, char fname[], char lname[], int day, int month, int year, double height, double weight){
	strcpy(hp->fname, fname);
	strcpy(hp->lname, lname);
	hp->day = day;
	hp->month = month;
	hp->year = year;
	hp->height = height;
	hp->weight = weight;
}

int calculateAge(HealthProfile hp){
	time_t seconds = time(NULL); // 00:00:00 UTC January 1, 1970
	struct tm* current_time = localtime(&seconds);
	return (current_time->tm_year + 1900) - hp.year;
}

int calculateMaxHeartRate(HealthProfile hp){
	return 220 - calculateAge(hp);
}

double calculateTargetHeartRate(HealthProfile hp){
	return (double)(calculateMaxHeartRate(hp)*0.85);
}

double calculateBMI(HealthProfile hp){
	return hp.weight/(hp.height*hp.height);
}
