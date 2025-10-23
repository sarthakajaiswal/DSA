/*
    @GOAL:      To implement insertion sort 
    @DATE:      08 OCT 2025 
    @AUTHOR:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

int main(void) 
{
    // function prototypes 
    void input(int* p_array, int N); 
    void output(int* p_array, int N, const char* msg); 
    void sort(int* p_array, int N); 

    // variable declarations 
    int* a = NULL; 
    int N = 0; 

    // code 
    printf("Enter size of array:"); 
    scanf("%d", &N); 

    if(N <= 0) 
    {
        puts("Bad array size"); 
        exit(EXIT_FAILURE); 
    } 

    a = (int*)malloc(N * sizeof(int)); 
    if(NULL == a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    sort(a, N); 
    output(a, N, "After sort:"); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
} 

void input(int* p_array, int N) 
{
    // variable declarations 
    int cap = N * 10; 
    int i; 

    // code 
    srand(time(0)); 

    i = 0; 
    while(i < N) 
    {
        p_array[i] = rand() % cap; 
        i = i + 1; 
    } 
}

void output(int* p_array, int N, const char* msg) 
{
    // variable declarations 
    int i; 

    // code 
    if(msg) 
        puts(msg); 

    i = 0; 
    while(i < N) 
    {
        printf("a[%d]: %d\n", i, p_array[i]); 
        i = i + 1; 
    } 
} 

void sort(int* p_array, int N) 
{
    // variable declarations 
    int i, j; 
    int key; 

    // code 
    j = 1; 
    while(j < N) 
    {
        key = p_array[j]; 

        i = j - 1; 
        while(i > -1 && p_array[i] > key) 
        {
            p_array[i+1] = p_array[i]; 
            i = i - 1; 
        }
        p_array[i + 1] = key; 

        j = j + 1; 
    } 
} 
