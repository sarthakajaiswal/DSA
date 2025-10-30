// 1 
#include <stdio.h> 

int main(void) 
{
    // function prototypes 
    void display(int arr[], int size); 

    // variable declarations 
    int a[8] = {-15, -6, -3, -5, 0, 30, 10, 0}; 
    int i; 

    // code 
    printf("Before shifting:\n"); 
    display(a, 8); 

    int tmp = a[7]; 
    i = 6; 
    while(a[i] > 0) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 

    printf("After shifting:\n"); 
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
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 
