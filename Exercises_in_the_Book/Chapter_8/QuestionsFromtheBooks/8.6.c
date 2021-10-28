#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    scanf("%s", s);
    int i;
    for(i=0;(s[i]=toupper(s[i]))!='\0';i++){}
    printf("%s\n",s);
    for(i=0;(s[i]=tolower(s[i]))!='\0';i++){}
    printf("%s",s);
    return 0;
}

