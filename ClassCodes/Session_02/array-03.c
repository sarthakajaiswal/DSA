/*
    @GOAL: To define a generalised function to print any array 
    @DATE: 05 OCT 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> // for declaration of printf() function 

int main(void) 
{
    // function declarations 
    void display(int arr[], int size); 

    // variable declarations 
    int a[5] = {10, 20, 30, 40, 50}; 
    int b[3] = {1000, 2000, 3000}; 
    int c[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 

    // code 
    printf("Printing array a:\n"); 
    display(a, 5); // call of display() 

    printf("Printing array b:\n"); 
    display(b, 3); // call of display() 

    printf("Printing array c:\n"); 
    display(c, 8); // call of display() 

    return (0); 
} 

// definition of display() 
void display(int arr[], int size) 
{
    // variable declarations 
    int i; 

    // code 
    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

