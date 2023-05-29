#include <stdio.h>
#include <string.h>

void sort(char towns[][10]);

void swap(char s1[], char s2[]);

int main(){
	int i;
	char towns[15][10] = {"Istanbul", "Ankara", "Izmir", "Manisa", "Aydin", "Antalya", "Mugla", "Edirne", "Kayseri", "Malatya", "Hatay", "Gaziantep"};
	//printf("%s", "before func");
	sort(towns);
	
	for(i=0;i<12;i++)
		printf("%s ", towns[i]);
	return 0;
}


void sort(char towns[][10]){
	int i, j;
	//printf("%s", "\nbefore loop");
	for(i=0;i<11;i++){
		//printf("\n%s","before second loop");
		for(j=1;j<12;j++){
			//printf("\n%s","before comp");
			if(strcmp(towns[i],towns[j]) > 0){
				//printf("\n%s","before swap calling");
				printf("%s %s->", towns[i],towns[j]);
				swap(towns[i],towns[j]);
				printf("%s %s\n", towns[i],towns[j]);
			}
				
		}
	}
}

void swap(char s1[], char s2[]){
	//printf("\n%s", "in swap start");
	char temp[10];
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
	//printf("\n%s", "in swap end");
}
