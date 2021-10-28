#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3
/*
NOTE !! : never put & in front of string array in scanf. Because a
string could be evaluated as pointer. That's why we can use them 
directly without adding &. Adding & will be evaluated to (char (*)[SIZE]
and scanf waits char *.
And never forget to put SIZE-1 befor s in scanf to overcome overflow case.
*/
int main()
{
    char s1[SIZE], s2[SIZE], s3[SIZE], s4[SIZE],s5[SIZE],s6[SIZE];
    scanf("%2s %2s %2s %2s %2s %2s", &s1, &s2, &s3, &s4, &s5, &s6);
    int num1,num2,num3,num4,num5,num6;
    num1=atoi(s1);
    num2=atoi(s2);
    num3=atoi(s3);
    num4=atoi(s4);
    num5=atoi(s5);
    num6=atoi(s6);
    printf("%d %d %d %d %d %d", num1, num2, num3, num4, num5, num6);
    return 0;
}

