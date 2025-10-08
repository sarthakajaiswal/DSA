/*
    Pre-conditions: 
        (1) N >= 2 
        (2) a[0]...a[N-2] are sorted but a[0]..a[N-1] are not 
            necesaarily sorted. 

    Post-condition: a[0]...a[N-1] i.e. entire array is sorted. 

    @GOAL:      Design a function for above pre and post conditions 
    @DATE:      08 OCT 2025 
    @AUTHOR:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int main(void) 
{
    // function declarations 
    void insert_at_sorting_position(int a[], int N); 
    void display(int a[], int N, const char* msg); 

    // variable declarations 
    int a[6] = {10, 20, 30, 40, 50, 15}; 
    int b[5] = {100, 200, 300, 400, 5}; 

    // code 
    display(a, 6, "Displaying \'a\' before insert_at_sorting_position():"); 
    insert_at_sorting_position(a, 6); 
    display(a, 6, "Displaying \'b\' after insert_at_sorting_position():\n"); 
    
    display(b, 5, "Displaying \'b\' before insert_at_sorting_position():\n"); 
    insert_at_sorting_position(b, 5); 
    display(b, 5, "Displaying \'b\' after insert_at_sorting_position()\n"); 

    return (0); 
} 

void insert_at_sorting_position(int a[], int N) 
{
    // variables  
    int tmp; 
    int i; 

    // code 
    tmp = a[N-1]; 
    i = N - 2; 
    while(i >= 0 && a[i] > tmp) 
    {
        a[i+1] = a[i]; 
        i = i - 1; 
    } 

    a[i+1] = tmp; 
} 

void display(int a[], int N, const char* msg) 
{
    // code 
    if(msg != NULL) 
        puts(msg); 

    int i; 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, a[i]); 
        i = i + 1; 
    } 
} 
