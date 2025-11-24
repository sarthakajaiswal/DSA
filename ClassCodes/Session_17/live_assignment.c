/*
    @GOAL: Print elements of array in reverse order, using a recursive algorithm. 
    @DATE: 16 Nov 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

/* 
                    print(a[N-1]);        if N > 0 
                    PRN(a, N-1); 
    PRN(a, N) = 
                    print(a[0])         if N == 1 
*/

#include <stdio.h> 

void PRN(int a[], int N); 

int main(void) 
{
    int a[5] = {10, 20, 25, 50, 80}; 

    printf("Printing the array:\n"); 
    PRN(a, 5); 

    return (0); 
} 

void PRN(int a[], int N) 
{
    // if(N < 1) 
    // {
    //     return; 
    // }
    if(N == 1) 
    {
        printf("a[0]: %d\n", a[0]); 
    } 
    else if(N > 1) 
    {
        printf("a[%d]: %d\n", N-1, a[N-1]); 
        PRN(a, N-1); 
    } 
} 
