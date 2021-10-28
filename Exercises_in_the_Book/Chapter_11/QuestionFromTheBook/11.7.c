#include <stdio.h>
void createMasterFile(FILE **fPtr);
void createTransactionFile(FILE **fPtr);

int main(){
	/*FILE *fPtr = fopen("master_file.txt", "w");
	createMasterFile(&fPtr);*/
	FILE *fPtr = fopen("transaction_file.txt", "w");
	createTransactionFile(&fPtr);
	return 0;
}

void createMasterFile(FILE **fPtr){
	if(!*fPtr){
		printf("[ERROR] File could not be opened/created.\n");
	} else {
		char name[20], surname[20];
		unsigned int acct_num;
		double balance;
		
		puts("Enter account number, name, surname and balance, respectively: ");
		fprintf(*fPtr, "%-20s%-15s%-15s%-15s\n", "Account Number", "Name", "Surname", "Balance");
		
		scanf("%u%19s%19s%lf", &acct_num, name, surname, &balance);
		while(!feof(stdin)){
			fprintf(*fPtr, "%-20u%-15s%-15s%.2lf\n", acct_num, name, surname, balance);
			scanf("%u%19s%19s%lf", &acct_num, name, surname, &balance);
		}
		fclose(*fPtr);
	}
}

void createTransactionFile(FILE **fPtr){
	if(!*fPtr){
		printf("[ERROR] File could not be opened/created.\n");
	} else {
		
		unsigned int acct_num;
		double balance;
		
		puts("Enter account number, and amount, respectively: ");
		fprintf(*fPtr, "%-20s%s\n", "Account Number", "Amount");
		
		scanf("%u%lf", &acct_num, &balance);
		while(!feof(stdin)){
			fprintf(*fPtr, "%-20u%.2lf\n", acct_num, balance);
			scanf("%u%lf", &acct_num, &balance);
		}
		fclose(*fPtr);
	}
}
