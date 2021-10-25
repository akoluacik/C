#include <stdio.h>
void printChars(char *cPtr){
    for(;*cPtr!='\0';cPtr++)
        printf("%c", *cPtr);
}
int main()
{
    char test[]="Merhaba";
    /*char* cPtr=test;
    for(;*cPtr!='\0';cPtr++)
        printf("%c", *cPtr);*/
    
    printChars(test);

    return 0;
}
