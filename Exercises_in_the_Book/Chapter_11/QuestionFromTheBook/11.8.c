#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct clientData{
	unsigned int acctNum;
	char name[7];
	char surname[7];
	double balance;
};

int nofLines(FILE*); // returns number of lines of file
struct clientData* fill_struct(); // read the files and fill the struct
void write_file(); // write the info of struct to the file
int countlines(char *);

int main(){
	
	// read_files();
	write_file();
	return 0;
}

int countlines(char *filename)
{
  // count the number of lines in the file called filename                                    
	FILE *fp = fopen(filename,"r");
	int ch=0, lines=0;

	if (!fp)
		return -1;

	lines++;
	while ((ch = fgetc(fp)) != EOF)
		if (ch == '\n')
			lines++;
	
	fclose(fp);
	return lines;
}

struct clientData* fill_struct(){
	FILE *fPtr;
	
	/*variables*/
	int acct_num; // used to get acct_num in transaction_file
	double balance; // used to get balance in transaction_file
	int i = 0, idx = 0; // loop index
	char line[100];
	struct clientData* client; // to get rid of undefined behaviour
	int len = countlines("master_file.txt");

	if(len == -1){
		printf("%s\n","[ERROR] File could not found!");
		return 0;
	}

	if(!(fPtr = fopen("master_file.txt", "r"))){
		printf("[ERROR] File could not be found!\n");
		return;
	}
	
	client = (struct clientData*)malloc(sizeof(struct clientData)*len);
	while((fgets(line, 59, fPtr))){
		// to skip header
		if(sscanf(line, "%d %s %s %lf", &client[idx].acctNum, client[idx].name, client[idx].surname, &client[idx].balance) == 4){
			//printf("%d %s %s %lf", client[idx].acctNum, client[idx].name, client[idx].surname, client[idx].balance);
			++idx;
		}
	}

	fclose(fPtr);
	if(!(fPtr = fopen("transaction_file.txt", "r"))){
		printf("[ERROR] File could not be found!\n");
		return;
	}

	while((fgets(line, 28, fPtr))){

		if(sscanf(line, "%d %lf", &acct_num, &balance) != 2)
			continue;
		
		else
			for(i = 0;i < len; ++i)
				if(client[i].acctNum == acct_num)
					client[i].balance += balance;
	}
	/*for(idx = 0; idx < len; ++idx){
		printf("%d %s %s %lf\n", client[idx].acctNum, client[idx].name, client[idx].surname, client[idx].balance);
	}*/
	fclose(fPtr);
	return client;
}

void write_file(){
	struct clientData* clients = fill_struct();
	int idx, len = countlines("master_file.txt");

	if(len == -1){
		printf("%s\n","[ERROR] File could not found!");
		return;
	}

	FILE *fPtr;
	
	if(!(fPtr = fopen("master_file2.txt", "w"))){
		printf("[ERROR] File could not be found/opened!\n");
		return;
	}
	
	fprintf(fPtr, "%-20s%-15s%-15s%-15s", "Account Number", "Name", "Surname", "Balance");
	for(idx = 0; idx < len; ++idx){
		//printf("%d %s %s %lf\n", clients[idx].acctNum, clients[idx].name, clients[idx].surname, clients[idx].balance);
		fprintf(fPtr, "\n%-20u%-15s%-15s%.2lf", clients[idx].acctNum, clients[idx].name, clients[idx].surname, clients[idx].balance);
	}
	free(clients);
	fclose(fPtr);
}