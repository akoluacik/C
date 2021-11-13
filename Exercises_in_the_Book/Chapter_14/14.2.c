/***************************************************************************************************
14.2 (Variable-Length Argument List: Calculating Products) Write a program 
that calculates theproduct of a series of integers that are passed to function 
product using a variable-length argument list. Test your function with several
calls, each with a different number of arguments.
****************************************************************************************************/

#include <stdio.h>
#include <stdarg.h> // variable list arguments utility

int product(int i, ...);

int main(void){
    int x = 5, y = 3, z=7, k = 11;
    printf("%s%d\n%s%d\n%s%d\n%s%d\n\n",
        "x = ", x, "y = ", y, "z = ", z, "k = ", k);
    printf("%s%d\n%s%d\n%s%d\n\n",
        "The multiplication of x and y is: ", product(2, x, y),
        "The multiplication of x, y and z is: ", product(3, x, y, z),
        "The multiplication of x, y, z and k is: ", product(4, x, y, z, k));
}

int product(int i, ...){
    int mult = 1, idx;
    va_list ap; // stores the info for va_start and va_end

    va_start(ap, i); // initializing the va_list opject

    //process variable-length argument list
    for(idx = 1; idx <= i; ++idx)
        mult *= va_arg(ap, int); // accessing each element of the list.
    
    va_end(ap); // clean up variable-length argument list
    return mult;
}