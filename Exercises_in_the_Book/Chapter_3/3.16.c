#include <stdio.h>

int main(){
    double state_tax, total_amount;
    char month[11], temp;
    while(1){
        printf("%s", "Enter total amount collected (-1 to quit): "); scanf("%lf", &total_amount);
        if(total_amount == -1){
            break;
        }
        scanf("%c", &temp);
        printf("Enter name of month: "); scanf("%s", month);
        printf("%s%.2lf\n", "Total Collections: $", total_amount);
        printf("%s%.2lf\n", "Sales: $", total_amount / 1.09); // sales + sales * 0.04 + sales * 0.05 = total_amount
        printf("%s%.2lf\n", "County Sales Tax: $", (total_amount / 1.09) * 0.04); 
        printf("%s%.2lf\n", "State Sales Tax: $", (total_amount / 1.09) * 0.05);
        printf("%s%.2lf\n", "Total Sales Tax Collected: $", (total_amount / 1.09) * 0.04 + (total_amount / 1.09) * 0.05);
    }
}