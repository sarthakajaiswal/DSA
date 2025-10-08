/*
    @GOAL:  to desing insertion sort function 
    @DATE:  08 OCT 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int main(void) 
{
    // function declarations 
    void insertion_sort(int a[], int N); 
    void insert_at_sorting_position(int a[], int N); 
    void display(int a[], int N, const char* msg); 

    // variable declarations 
    int a[6] = {50, 30, 20, 15, 10, 40}; 
    int b[5] = {400, 5, 300, 100, 200}; 
    int c[1] = {100};  

    // code 
    display(a, 6, "Displaying \'a\' before insertion_sort():"); 
    insertion_sort(a, 6); 
    display(a, 6, "Displaying \'a\' after insertion_sort():"); 
    
    display(b, 5, "Displaying \'b\' befire insertion_sort():"); 
    insertion_sort(b, 5); 
    display(b, 5, "Displaying \'b\' after insertion_sort():"); 

    display(c, 1, "Displaying \'c\' before insertion_sort():"); 
    insertion_sort(c, 1); 
    display(c, 1, "Displaying \'c\' after insertion_sort():"); 

    return (0); 
} 

void insertion_sort(int a[], int N) 
{
    // function declarations 
    void insert_at_sorting_position(int a[], int N); 

    // variable declarations 
    int subarray_size; 
    
    // code 
    subarray_size = 2; 
    while(subarray_size <= N) 
    {
        insert_at_sorting_position(a, subarray_size); 
        subarray_size = subarray_size + 1;
    } 
} 

void insert_at_sorting_position(int a[], int N) 
{
    // variable declarations 
    int tmp; 
    int i; 

    // code 
    tmp = a[N - 1]; 
    i = N - 2; 
    while(i > -1 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 

    a[i + 1] = tmp; 
} 

void display(int a[], int N, const char* msg) 
{
    // code 
    if(msg) 
        puts(msg); 

    int i; 
    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    }
} 
