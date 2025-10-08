/*
    @GOAL:  starting from last element, shift the elements of array 
            to the right until negative element is occured 
    @DATE:  05 OCT 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int main(void) 
{
    // function prototypes 
    void display(int arr[], int size); 

    // variable declarations 
    int a[8] = {-15, -5, -8, 20, 10, 50, 40, 80}; 

    // code 
    printf("ARRAY BEFORE SHIFTING POSITIVE NUMBERS TO THE RIGHT:\n"); 
    display(a, 8); 

    int tmp = a[7]; // save the last indexed element in tmp variable 
    int i = 6;      // initialize i to the second last element 

    // keep shifting array elements to their right index 
    // until negative element is encountered 
    // Assumptions: There is atleast one negative number 
    while(a[i] >= 0) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp;   // save the last indexed element 
                    // at the first positive index 
    printf("ARRAY AFTER SHIFTING POSITITVE NUMBERS TO THE RIGHT:\n"); 
    display(a, 8); 

    return (0); 
} 

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


