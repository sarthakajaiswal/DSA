/*
    PRACTISE SET 1 

    @Goal:      Write a program that prints array in reverse order(from last to first). 
                The original array should remain unchanged. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void print_array_reverse_order_iteratively(int A[], int N); 
void print_array_reverse_order_recursively(int A[], int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 

    return (0); 
} 

void test_1(void) 
{
    int A[5] = {10, 20, 30, 40, 50}; 
    int N = 5; 

    puts("Printing array iteratively:"); 
    print_array_reverse_order_iteratively(A, N); 
    printf("\n"); 

    puts("Printing array resursively:"); 
    print_array_reverse_order_recursively(A, N); 
    printf("\n"); 
} 

void test_2(void) 
{
    int A[1] = {10}; 
    int N = 1; 

    puts("Printing array iteratively:"); 
    print_array_reverse_order_iteratively(A, N); 
    printf("\n"); 

    puts("Printing array resursively:"); 
    print_array_reverse_order_recursively(A, N); 
    printf("\n"); 
} 

void print_array_reverse_order_iteratively(int A[], int N) 
{
    int i; 

    for(i = N-1; i >= 0; --i)
        printf("%d ", A[i]); 
} 

void print_array_reverse_order_recursively(int A[], int N) 
{
    if(N < 1) 
        return; 

    if(N == 1) 
        printf("%d ", A[0]); 
    
    else 
        printf("%d ", A[N-1]); 
        print_array_reverse_order_recursively(A, N-1);  
} 
