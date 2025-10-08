/*
    @GOAL: To fill an array and display it. 
    @DATE: 05 Oct 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> /* for declaration of printf() function */

/* declare array of 8 integers */
int arr[8]; 

int main(void) 
{
    /* declare local variables */
    int i;      /* counter variable for array */

    /* set element at index i to (i+1) * 10 */
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i + 1) * 10; 
        i = i + 1; 
    } 

    /* Print the array */
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
}


