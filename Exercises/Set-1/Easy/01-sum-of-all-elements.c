/*
    PRACTISE SET 1 

    @Goal:      Write a program that takes an array of integers and calculates
                the sum of all elements in the array 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int sum_of_all_elements(int A[], int N); 
int sum_of_all_elements_recursive(int A[], int N); 

void test_1(void); 
void test_2(void); 

int main(void) 
{
    puts("test_1():"); 
    test_1(); 
    puts("test_2():");  
    test_2(); 
    return (0); 
} 

void test_1(void) 
{
    int A[5] = {4, 7, 2, 9, 5}; 
    int N = 5; 
    int sum = 0; 

    sum = sum_of_all_elements(A, N); 
    printf("sum(iteratively calculated) of array elements = %d\n", sum); 

    sum = 0; 
    sum = sum_of_all_elements_recursive(A, N); 
    printf("Sum(calculated recursively) of array elements = %d\n", sum); 

} 

void test_2(void) 
{
    int A[5] = {10}; 
    int N = 1; 
    int sum = 0; 

    sum = sum_of_all_elements(A, N); 
    printf("sum(iteratively calculated) of array elements = %d\n", sum); 

    sum = 0; 
    sum = sum_of_all_elements_recursive(A, N); 
    printf("Sum(calculated recursively) of array elements = %d\n", sum); 

} 

int sum_of_all_elements(int A[], int N) 
{
    int i; 
    int sum = 0; 

    for(i = 0; i < N; ++i)
        sum = sum + A[i]; 

    return (sum); 
} 

int sum_of_all_elements_recursive(int A[], int N) 
{
    if(N == 0) 
        return 0; 

    if(N == 1) 
        return A[0]; 
    
    else 
        return (A[0] + sum_of_all_elements_recursive(A+1, N-1)); 
} 
