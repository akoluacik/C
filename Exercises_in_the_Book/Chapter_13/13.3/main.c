#include <stdio.h>

#define YES 1
#define NO 0

#line 3000

#if defined(TRUE)
    #undef TRUE
    #define TRUE 1
#else
    #define TRUE 1
#endif

#if 0 // kind of a commenting out a code
    #ifdef(TRUE)
        #undef TRUE
        #define TRUE 1
    #endif
#endif

#if TRUE
    #define FALSE 0
#else
    #define FALSE 1
#endif

#define CUBE_VOLUME(X) ((X)*(X)*(X))

int main(){
    printf("%d\n", TRUE);
    printf("%d\n", FALSE);
    printf("volume:%d\n", CUBE_VOLUME(3));
}