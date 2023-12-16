/** This example calls a simple fortran function
 * from this plain C code.
 * Copyright (c) 2017 Aimirim STI
 */

#include <stdio.h>
#include "fortran_func.h"

int main() {
    
    // Variable definition
    double x = 34;
    double y = 42.973;
    double z;

    // Call Fortran function
    z = sum2(x,y);

    // Print Results
    printf("Test Result:%7.3f\n",z);

    return(0);
}
