/*
    @GOAL:      timing measurement for insertion sort algorithm 
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
    void sort(int* p_array, int N); 

    // variable declarations 
    int* a = NULL; 
    int N = 0; 

    time_t t_start; 
    time_t t_end; 
    time_t t_delta; 

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
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    input(a, N); 
    t_start = time(0); 
    sort(a, N); 
    t_end = time(0); 
    t_delta = t_end - t_start; 
    printf("INTEGRAL TIME FOR SORT: %llu\n", t_delta); 

    free(a); 
    a = NULL; 

    exit(EXIT_SUCCESS); 
} 

void input(int* p_array, int N) 
{
    // variable declrations 
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
            p_array[i + 1] = p_array[i]; 
            i = i - 1; 
        } 

        p_array[i + 1] = key; 

        j = j + 1; 
    } 
} 
