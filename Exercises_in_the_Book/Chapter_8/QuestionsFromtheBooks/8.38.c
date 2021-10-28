/*
Program works by the ratio of the number of spam phrases by number of word.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

double isSpam(char []);

int main(){
	char message[] = "congratulations, you are the winner of our giveaway. This propose is limited time. Urgent.";
	char message2[] = "hey, this is Freeman from Wycombe. I am a free footballer and willing to negotiate with you. hope we will. see you soon.";
	
	if(isSpam(message2) >= 30.0) printf("[WARNING] Potential Spam mail!"); printf("[OK] Message seems safe.");

	return 0;
}
double word_number(char message[]){
	int i, counter=0;
	for(i=0;message[i]!='\0';i++){
		if(isspace(message[i])) counter++;
	}
	return (double)counter;
}

double isSpam(char message[]){
	char spam_words[][20] = {"click below", "link", "free gift", "free access", "save", "best price", "off", "double",
						 "cash", "income", "earn", "last call", "limited time", "New customers only", "lower rates",
						 "urgent", "you are the winner", "congratulations", "cancel at any time", "do it today", "click link",
						 "make money", "extra cash", "extra money", "extra income", "free money", "giveaway", "free trial",
						 "risk-free", "Unsecured credit"};
	
	int i,j,counter=0;
	char *sub;
	for(i=0;i<30;i++){
		sub = strstr(message, spam_words[i]);
		if(sub) ++counter;
	}
	return (counter/word_number(message))*100;
}
