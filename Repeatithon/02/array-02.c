//1
#include <stdio.h> 

int main(void) 
{
    // variable declarations 
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80}; 
    int i; 

    // code 
    printf("Showing array before shifting the elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    // declare tmp variable to store value at last index 
    int tmp = arr[7]; 

    i = 6; 
    while(i >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    }

    printf("Just after getting out of loop: i = %d\n", i); 
    arr[i+1] = tmp; 

    printf("Showing array after shifting elements to right: \n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
}

// 2 
#include <stdio.h> 

int main(void) 
{
    // variable declarations 
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80}; 
    int i; 

    // code 
    printf("Before shifting array elements to right\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("Arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    int tmp = arr[7]; 

    i = 6; 
    while(i > -1) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 

    arr[i+1] = tmp; 

    printf("After shifting elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 3 
#include <stdio.h> 

int main(void) 
{
    // variable declarations 
    int arr[5] = {20, 10, 40, 50, 39}; 
    int i; 
    
    // code 
    printf("Before shifting array elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    int tmp = arr[4]; 

    i = 3; 
    while(i >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 

    arr[i + 1] = tmp; 

    printf("After shifting elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 4 
#include <stdio.h> 

int main(void) 
{
    // variable declarations 
    int arr[8] = {10, 40, 30, 60, 30, 30, 20, 50}; 
    int i; 
    
    // code 
    printf("Array before shifting elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    int tmp = arr[7]; 
    i = 6; 
    while(i >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    }  
    arr[i+1] = tmp; 

    printf("Array after shifting elements:\n"); 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 5 
#include <stdio.h> 

int main(void) 
{
    // variable declarations 
    int arr[5] = {30, 20, 10, 50, 40}; 
    int i; // counter variable 

    // code 
    printf("Array before shifting the elements:\n"); 
    i = 0; 
    while(i < 5)
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    int tmp = arr[4]; 

    i = 3; 
    while(i >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    }
    arr[i + 1] = tmp; 

    printf("Showing array after shifting:\n"); 
    i = 0; 
    while(i < 5) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
}

