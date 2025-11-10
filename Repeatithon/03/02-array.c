/*
    @goal:  you will be given a non empty array of integers. 
            The array is filled in such a way that all negative 
            numbers are stacked in left side of the array 
            and all non-negative numbers are stacked on the 
            right side of array 

            Your job is to right shift and rotate all non-negative elements. 
    
    @boudary case:  There may not be any negative element, it that case
                    the entire array will be right shifted and rotated 
*/ 

#include <stdio.h> 

void display(int arr[], int size); 
void right_shift_and_rotate(int arr[], int size); 

int main(void) 
{
    int a[8] = {-10, -5, 4, -3, 30, 40, 20, 10}; 
    int b[8] = {30, 10, 3, 6, 23, 56, 45, 2}; 

    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 8); 
    right_shift_and_rotate(a, 8); 
    printf("Showing array \'a\' AFTER right shift and rotate:\n"); 
    display(a, 8); 

    printf("Showing array \'b\' BEFORE right shoft and rotate:\n"); 
    display(b, 8); 
    right_shift_and_rotate(b, 8); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 8); 

    return (0); 
} 

void display(int arr[], int size) 
{
    int i; 

    i = 0; 
    while(i < size) 
    {
        printf("arr%d]: %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

void right_shift_and_rotate(int arr[], int size) 
{
    int tmp = arr[size-1]; 
    int i = size - 2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

// ================= 

// 1 
int main(void) 
{
    int a[6] = {-10, 4, 6, 657, 34, 2}; 
    int b[2] = {0, 5};
    
    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 6); 
    right_shift_and_rotate(a, 6); 
    printf("Showing array \'a\' after right shift and rotate:\n"); 
    display(a, 6); 

    printf("Showing array \'b\' before right shift and rotate:\n"); 
    display(b, 2); 
    right_shift_and_rotate(b, 2); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 2); 

    return (0); 
}

// 2 
int main(void) 
{
    int a[10] = {-10, -20, -30, -40, -50, -60, -70, -80, -90,-100}; 
    int b[1] = {1}; 

    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 10); 
    right_sift_and_rotate(a, 10); 
    printf("Showing array \'a\' AFTER right shift and rotate:\n"); 
    display(a, 10); 

    printf("Showing array \'b\' BEFORE right shift and rotate:\n"); 
    display(b, 1); 
    right_shift_and_rotate(b, 1); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 1); 

    return (0); 
} 

// 3 
int main(void) 
{
    int a[4] = {-10, -20, -10, 0}; 
    int b[3] = {10, 20, 30}; 

    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 4); 
    right_shift_and_rotate(a, 4); 
    printf("Showing array \'a\' AFTER right shift and rotate:\n"); 
    display(a, 4); 

    printf("Showing array \'b\' BEFORE rigt shift and rotate:\n"); 
    display(b, 3); 
    right_shift_and_rotate(b, 3); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 8); 

    return (0); 
} 

// 4 
int main(void) 
{
    int a[5] = {10, 20, 30, 40, 50}; 
    int b[8] = {-10, 0, 40, 20, 40, 56, 34, 23}; 

    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 5); 
    right_shift_and_rotate(a, 5); 
    printf("Showing array \'a\' AFTER right shift and rotate:\n"); 
    display(a, 5); 

    printf("Showing array \'b\' BEFORE right shift and rotate:\n"); 
    display(b, 8); 
    right_shift_and_rotate(b, 8); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 8); 

    return (0); 
}

// 5 
int main(void) 
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int b[7] = {-10, -20, -30, -40, -50, -60, 1}; 

    printf("Showing array \'a\' BEFORE right shift and rotate:\n"); 
    display(a, 10); 
    right_shift_and_rotate(a, 10); 
    printf("Sjhowing array \'a\' AFTER right shift and rotate:\n"); 
    display(a, 10); 

    printf("Showing array \'b\' BEFORE right shift and rotate:\n"); 
    display(b, 7); 
    right_shift_and_rotate(b, 7); 
    printf("Showing array \'b\' AFTER right shift and rotate:\n"); 
    display(b, 7); 

    return (0); 
}

// ============ 
// 1 
void right_shift_and_rotate(int arr[] , int size) 
{
    int tmp = arr[size-1];
    int i = size - 2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

// 2 
void right_shift_and_rotate(int arr[], int size) 
{
    int tmp = arr[size-1]; 
    int i = size - 2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

// 3 
void right_shift_and_rotate(int arr[], int size) 
{
    int tmp = arr[size - 1]; 
    int i = size - 2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

// 4 
void right_shift_and_rotate(int arr[], int size) 
{
    int tmp = arr[size-1]; 
    int i = size-2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

// 5 
void right_shift_and_rotate(int arr[], int size) 
{
    int tmp = arr[size-1]; 
    int i = size-2; 

    while(i >= 0 && arr[i] >= 0) 
    {
        arr[i+1] = arr[i]; 
        i = i - 1; 
    } 
    arr[i+1] = tmp; 
} 

//=========== 
//1 
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
void display(int arr[] ,int size) 
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

