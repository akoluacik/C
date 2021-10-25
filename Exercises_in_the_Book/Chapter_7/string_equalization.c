#include <stdio.h>
void copy1(char *s1, const char *s2){
    int i;
    for(;(s1[i]=s2[i])!='\0';i++){}
}

void copy2(char* s1, const char* s2){
    for(;(*s1=*s2)!='\0';s1++,s2++){}
}

int main()
{
    char str1[]="Hello";
    char str2[]="Hey";
    copy2(str1,str2);
    printf("%s",str1);
    return 0;
}
