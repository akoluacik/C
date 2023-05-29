#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hardware{
    size_t record;
    char tool_name[20];
    int quantity;
    double cost;
};

struct hardware* fill_struct();
void add_data(struct hardware);
void update_data(size_t);
void delete_record(size_t);

/*helper functions*/
void clear_data(struct hardware*);
void print_hardware();

int main(){
    int choice;
    size_t id;
    struct hardware hardware;
    printf("\n1-Add data\n2-Update data\n3-Delete data\n4-Print hardwares\n0-Terminate program\n\n");scanf("%d", &choice);
    while(choice){
        switch (choice)
        {
        case 1:
            printf("Enter id, name, quantity and cost of the new hardware: ");scanf("%lu %19s %d %lf", &hardware.record, hardware.tool_name, &hardware.quantity, &hardware.cost);
            add_data(hardware);
            break;
        case 2:
            printf("Enter the id of the hardware to be updated: ");scanf("%lu", &id);
            update_data(id);
            break;
        case 3:
            printf("Enter the id of the hardware to be deleted: ");scanf("%lu", &id);
            delete_record(id);
            break;
        case 4:
            print_hardware();
            break;
        default:
            printf("%s\n","Wrong choice!");
            break;
        }
        printf("\n\n1-Add data\n2-Update data\n3-Delete data\n4-Print hardwares\n0-Terminate program\n\n");scanf("%d", &choice);
    }

    return 0;
}

struct hardware* fill_struct(){
    FILE *f;
    if(!(f = fopen("hardware.dat", "r"))){
        printf("[ERROR] File could not be opened!");
        return;
    }
    int idx=0, i;
    char line[40];
    struct hardware *hardware = (struct hardware*)malloc(100*sizeof(struct hardware));
    while(fgets(line, 39, f)){
        if(sscanf(line, "%lu %s %d %lf", &hardware[idx].record, hardware[idx].tool_name, &hardware[idx].quantity, &hardware[idx].cost))
            ++idx;
    }
    /*puts("in fill_struct()");
    for(i=0;i<idx;++i)
        printf("%ld %s %d %lf\n", hardware[i].record, hardware[i].tool_name, hardware[i].quantity, hardware[i].cost);*/
    fclose(f);
    //puts("After fill_struct()\n");
    return hardware;
}


void add_data(struct hardware hardware){
    FILE *f;
    if(!(f = fopen("hardware.dat", "a"))){
        printf("[ERROR] File could not be opened!");
        return;
    }
    printf("%lu %s %d %lf\n", hardware.record, hardware.tool_name, hardware.quantity, hardware.cost);
    fprintf(f, "\n%zu %s %d %.2lf", hardware.record, hardware.tool_name, hardware.quantity, hardware.cost);
    fclose(f);
}

void update_data(size_t id){
    FILE *f;
    
    if(!(f = fopen("hardware.dat", "r+"))){
        printf("[ERROR] File could not be opened!");
        return;
    }
    struct hardware *hardware = fill_struct();
    char line[30];
    int idx;
    for(idx = 0; idx < 99; ++idx){
        if(hardware[idx].record == id){
            printf("Enter new quantity and cost, respectively: ");scanf("%d %lf", &hardware[idx].quantity, &hardware[idx].cost);
            break;
        }
    }
    for(idx = 0; idx < 99; ++idx){
        fprintf(f, "%lu %s %d %.2lf\n", hardware[idx].record, hardware[idx].tool_name, hardware[idx].quantity, hardware[idx].cost);
    }
    fprintf(f, "%lu %s %d %.2lf", hardware[idx].record, hardware[idx].tool_name, hardware[idx].quantity, hardware[idx].cost);
    free(hardware);
    fclose(f);
}

void delete_record(size_t id){
    FILE *f;
    int idx;
    struct hardware *hardware = (struct hardware*)malloc(sizeof(struct hardware)*100);
    hardware = fill_struct();
    for(idx = 0; idx < 100; ++idx){
        if(hardware[idx].record == id){
            printf("in if -> %lu\n", hardware[idx].record);
            printf("idx in loop:%d\n", idx);
            clear_data(&hardware[idx]);
            break;
        }
    }
    while(hardware[idx+1].record != 0){
        hardware[idx] = hardware[idx+1];
        ++idx;
    }
    printf("idx for after while:%d\n", idx);
    clear_data(&hardware[idx]);
    if(!(f = fopen("hardware.dat", "w"))){
        printf("%s\n","[ERROR] File could not found!");
        return;
    }
    
    fprintf(f, "%lu %s %d %.2lf", hardware[0].record, hardware[0].tool_name, hardware[0].quantity, hardware[0].cost);
    for(idx = 1; hardware[idx].record != 0; ++idx)
        fprintf(f, "\n%lu %s %d %.2lf", hardware[idx].record, hardware[idx].tool_name, hardware[idx].quantity, hardware[idx].cost);
    
    fclose(f);
    free(hardware);
}

/* Helper Functions */
void clear_data(struct hardware *hardware){
    printf("%s%lu%s%d%lf\n", "Data to be deleted: ", hardware->record, hardware->tool_name, hardware->quantity, hardware->cost);
    printf("\n\nIn clear_data()\n");
    hardware->record = 0;
    strcpy(hardware->tool_name, "");
    hardware->quantity = 0;
    hardware->cost = 0;
}

void print_hardware(){
    struct hardware *hardware = (struct hardware*)malloc(sizeof(hardware)*100);
    hardware = fill_struct();
    size_t idx;
    puts("\n**********************************HARDWARES******************************\n");
    //printf("%lu\n", hardware[0].record);
    for(idx = 0; hardware[idx].record != 0; ++idx)
        printf("idx:%lu->%lu %s %d %.2lf\n", idx, hardware[idx].record, hardware[idx].tool_name, hardware[idx].quantity, hardware[idx].cost);
    free(hardware);
}