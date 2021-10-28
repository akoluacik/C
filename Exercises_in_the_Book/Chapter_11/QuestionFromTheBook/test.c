#include <stdio.h>
#include <string.h>

int main () {
    char line[30];
    FILE *fp;
    int age;
    if (!(fp = fopen("test.txt", "r"))) {  /* validate file open for reading */
        perror ("file open failed");
        return 1;
    }
    char name[20], surname[20];
    //int off = 0;
    while (fgets (line, 30, fp)) {
        if(sscanf (line, "%s%s%d", name, surname, &age)) {
            printf("%s %s %d\n", name, surname, age);
        }
    }
    fclose(fp);
    return 0;
}