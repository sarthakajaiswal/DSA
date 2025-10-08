/*
    @GOAL: shift all elements of array to right 
            and the last element in first position
    @DATE: 05 OCT 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int main(void) 
{
    // Declare and initialize array of 8 elements as given 
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 0}; 

    // counter variable for array 
    int i; 

    // show array before shifting the elements 
    printf("Showing array before shifting elements to right:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    }

    // declare tmp variable to store the value of last index 
    int tmp = arr[7]; 

    i = 6; 
    while(i >= 0) 
    {
        arr[i + 1] = arr[i]; 
        i = i - 1; 
    }

    printf("Just after getting out of while loop: i = %d\n", i); // predicted value = -1 
    arr[i + 1] = tmp; 

    // show array after shifting the elements 
    printf("Showing array after shifting elements to right:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
}


