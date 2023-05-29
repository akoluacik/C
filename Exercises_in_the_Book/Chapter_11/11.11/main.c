#include <stdio.h>
#include <string.h>
struct person{
    char lastname[15];
    char firstname[15];
    char age[4];
};


void initialize(struct person person[]);
void initialize_person(struct person [], size_t);
void initialize_with_data(struct person[]);
void update(struct person person[]);
void print_struct(struct person []);


int main(){
    int i, choice;
    struct person person[20];
    char surname[15];
    initialize(person);
    initialize_with_data(person);
    printf("**********************************\n");
    printf("%s", "1-Printing\n2-Updating\n3-Deleting\n0-Terminating\nYour choice: ");
    scanf("%d", &choice);
    while(choice){
        switch (choice)
        {
        case 1:
            print_struct(person);
            break;
        case 2:
            printf("Enter a surname to be updated: "); scanf("%14s", surname);
            for(i = 0; strcmp(person[i].lastname, surname); ++i);
            printf("Enter updated name, surname and age, respectively: "); scanf("%14s %14s %3s", person[i].firstname, person[i].lastname, person[i].age);
            update(person);
            break;
        case 3:
            printf("Enter a surname to be deleted: "); scanf("%14s", surname);
            for(i = 0; strcmp(person[i].lastname, surname); ++i);
            printf("%s\n", "After for");
            initialize_person(person, i);
            update(person);
            break;
        default:
            printf("%s\n", "Wrong choice!Try again");
            break;
        }
        printf("%s", "1-Printing\n2-Updating\n3-Deleting\n0-Terminating\nYour choice: ");
        scanf("%d", &choice);
    }
}


void initialize(struct person person[]){
    int i;
    for(i = 0;i < 20; ++i){
        strcpy(person[i].firstname, "");
        strcpy(person[i].lastname, "unasigned");
        strcpy(person[i].age, "0");
    }
}

void initialize_person(struct person person[], size_t i){ // will be modified with default parameters
    strcpy(person[i].firstname, "");
    strcpy(person[i].lastname, "unasigned");
    strcpy(person[i].age, "0");
}

void update(struct person person[]){
    FILE *f;
    int i;
    char name[15], surname[15], age[4], *line;

    if(!(f = fopen("nameage.dat", "w"))){
        printf("%s\n", "[ERROR] File could not found!");
        return;
    }
    for(i = 0; i < 20; ++i)
        fprintf(f, "\n%-15s%-15s%-4s", person[i].firstname, person[i].lastname, person[i].age);
    
    fclose(f);
}

void print_struct(struct person person[]){
    size_t i;
    for(i = 0; i < 20; ++i){
        printf("%s %s %s\n", strlen(person[i].firstname)?person[i].firstname:"No Info", person[i].lastname, 
        person[i].age);
    }
}

void initialize_with_data(struct person person[]){
    strcpy(person[1].firstname, "John");
    strcpy(person[1].lastname, "Doe");
    strcpy(person[1].age, "22");

    strcpy(person[2].firstname, "Goytacaz");
    strcpy(person[2].lastname, "Jr");
    strcpy(person[2].age, "21");

    strcpy(person[3].firstname, "George");
    strcpy(person[3].lastname, "Parrot");
    strcpy(person[3].age, "50");
}