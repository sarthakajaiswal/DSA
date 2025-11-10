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

// ================================== 

#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

void display(int arr[], int size); 
void display(int arr[], int size); 
void display(int arr[] ,int size); 
void display(int arr[], int size); 
void display(int arr[], int size); 

// 1 
int main(void) 
{
    int a[8] = {-15, -5, -8, 10, 10, 50, 40, 80}; 
    
    printf("ARRAY BEFORE SHIFTING:\n"); 
    display(a, 8); 

    int tmp = a[7]; 
    int i = 6; 
    while(a[i] >= 0) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 

    printf("ARRAY AFTER SHIFTING:\n"); 
    display(a, 8); 

    return (0); 
} 

// 2 
int main(void) 
{
    int arr[8] = {-10, -4, -5, 10, 20, 30, 0, 1}; 

    printf("ARRAY BEFORE SHIFTING:\n"); 
    display(arr, 8); 

    int tmp = arr[7]; 
    int i = 6; 
    while(arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 

    printf("ARRAY AFTER SIFTING:\n"); 
    display(arr, 8); 

    return (0); 
}

// 3 
int main(void) 
{
    int arr[8] = {-15, 0, 0, 1, 5, 34, 76, 87, 40}; 

    printf("ARRAY BEFORE SHIFTING POSITIVE NUMBERS TO RIGHT:\n"); 
    display(arr, 8); 

    int tmp = arr[7]; 
    int i = 6; 

    while(arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 

    printf("ARRAY AFTER SHIFTING POSITIVE NUMBERS ELEMENTS TO RIGHT:\n"); 
    display(arr, 8); 

    return (0); 
}

// 4 
int main(void) 
{
    int a[5] = {-10, 0, 4, 5, 23}; 

    printf("BEFORE SHIFTING POSITIVE INTEGERS TO RIGHT:\n"); 
    display(a, 8); 

    int tmp = a[4]; 
    int i = 3; 
    while(a[i] >= 0) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 

    printf("AFTER SHIFTING POSITTIVE INTEGERS TO RIGHT:\n"); 
    display(a, 8); 

    return (0); 
}

// 5 
int main(void) 
{
    int a[10] = {-1, 4, 0, 23, 7, 5, 23, 76, 54, 12}; 

    printf("ARRAY BEFORE SHIFTING POSITIVE ELEMENTS TO RIGHT:\n"); 
    display(a, 10); 

    int tmp = a[9]; 
    int i = 8; 
    while(a[i] >= 0) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 
    a[i+1] = tmp; 

    printf("ARRAY AFTER SHIFTING POSITIIVE ELEMENTS TO RIGHT:\n"); 
    display(a, 8); 

    return (0); 
} 

// ============ 

// 1 
void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]:%d\n", i, arr); 
        i = i + 1; 
    } 
} 

// 2 
void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

// 3 
void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

// 4 
void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

// 5 
void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr[%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 


