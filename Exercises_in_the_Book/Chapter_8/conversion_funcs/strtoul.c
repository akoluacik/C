#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


char *article[] = {"article 1","article 2","article 3","article 4","article 5"};
char *noun[] = {"noun 1","noun 2","noun 3","noun 4","noun 5"};
char *verb[] = {"verb1","verb2","verb3","verb4","verb5"};
char *preposition[] = {"at", "in", "on", "of", "by"};

char *generateSentence(){
    char *sentence = calloc(81, sizeof(char));
    strcat(sentence, article[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, noun[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, verb[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, preposition[rand()%5]);
    sentence[0] = toupper(sentence[0]);
    
    return sentence;
}

int main()
{
    
    
    srand(time(NULL));
    int i;
    for(i=0;i<20;i++){
        char *sentence = generateSentence();
        printf("%s.\n", sentence);
        free(sentence);
    }
    
    return 0;
}
/*with parameters*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char *generateSentence(char **article, char **noun, char **verb, char **preposition){
    char *sentence = calloc(81, sizeof(char));
    strcat(sentence, article[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, noun[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, verb[rand()%5]);
    strcat(sentence, " ");
    strcat(sentence, preposition[rand()%5]);
    sentence[0] = toupper(sentence[0]);
    
    return sentence;
}

int main()
{
    char *article[] = {"article 1","article 2","article 3","article 4","article 5"};
    char *noun[] = {"noun 1","noun 2","noun 3","noun 4","noun 5"};
    char *verb[] = {"verb1","verb2","verb3","verb4","verb5"};
    char *preposition[] = {"at", "in", "on", "of", "by"};
    
    srand(time(NULL));
    int i;
    for(i=0;i<20;i++){
        char *sentence = generateSentence(article, noun, verb, preposition);
        printf("%s.\n", sentence);
        free(sentence);
    }
    
    return 0;
}

*/
