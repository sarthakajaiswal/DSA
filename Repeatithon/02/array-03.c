#include <stdio.h> 

int main(void) 
{
    // function declarations 
    void display(int arr[], int size); 

    // variable declarations 
    int a[5] = {10, 20, 30, 40, 50}; 
    int b[2] = {200, 100}; 
    int c[6] = {1, 5, 4, 3, 5, 2}; 

    // code 
    printf("Printing array a:\n"); 
    display(a, 5); 

    printf("Printing arrayb:\n"); 
    display(b, 2); 

    printf("Printing array c:\n"); 
    display(c, 6); 

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

// 2 
#include <stdio.h> 

int main(void) 
{
    // function declarations 
    void display(int arr[], int size); 

    // variable declarations 
    int a[5] = {100, 200, 300, 400, 500}; 
    int b[2] = {10, 20}; 
    int c[8] = {1, 2, 3, 4, 5, 6, 7, 78}; 

    // code 
    printf("Printing array a:\n"); 
    display(a, 5); 

    printf("Printing array b:\n"); 
    display(b, 2); 

    printf("Printing array c:\n"); 
    display(c, 8); 

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

// 3 
#include <stdio.h> 

int main(void) 
{
    // function declarations 
    void display(int arr[], int size); 
    
    // variable declarations 
    int x[5] = {1, 2, 3, 4, 5}; 
    int y[1] = {2}; 
    int z[8] = {10, 20, 30, 40, 50, 60, 70, 80}; 
    
    // code 
    printf("Printing array x:\n"); 
    display(x, 5); 

    printf("Printing array y:\n"); 
    display(y, 1); 

    printf("Printing array z:\n"); 
    display(z, 8); 

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

// 4 
#include <stdio.h> 

int main(void) 
{
    // function prototypes 
    void display(int arr[], int size); 

    // variable declarations 
    int a[1] = {10}; 
    int b[5] = {4, 5, 6, 8, 1}; 
    int c[7] = {7, 6, 5, 4, 3, 2, 1}; 

    // code 
    printf("Printing array a:\n"); 
    display(a, 1); 

    printf("Printing array b:\n"); 
    display(b, 5); 

    printf("Printing array c:\n"); 
    display(c, 7); 

    return (0); 
} 

void display(int arr[], int size) 
{
    // vavriable declarations 
    int i; 

    // code 
    i = 0; 
    while(i < size) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

// 5 
#include <stdio.h> 

int main(void) 
{
    // function prototypes 
    void display(int arr[], int size); 

    // variable declarations 
    int a[5] = {100, 400, 300, 200, 500}; 
    int b[6] = {3, 2, 6, 1, 2}; 
    int c[1] = {0}; 

    // code 
    printf("Printing array a:\n"); 
    display(a, 5); 
    
    printf("Printing array b:\n"); 
    display(b, 6); 

    printf("Printing array c:\n"); 
    display(c, 1); 

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

