#include <stdio.h>
#include <limits.h>

int main() {
    // The meaning of 'x' is defined by the state of a 32-bit register where the maximum for a 32-bit signed integer is 2147483647
    int x = 2147483647; 

    printf("The current machine state is: %d\n", x);

    
    x = x + 1; 
    // Adding 1 changes the bit pattern from 0111... to 1000... making the machine interpret it as a negative number.

    printf("The new machine state (with overflow) is: %d\n", x);     // Outputs: -2147483648

    return 0;
}