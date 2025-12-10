/*
    PRACTISE SET 1 

    @Goal:      Write a program that counts how many even numbers are present in 
                array of integers. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int count_even_numbers(int A[], int N); 
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
    int A[] = {3, 8, 12, 5, 7, 10, 2}; 
    int N = 7; 

    printf("Number of even elements = %d\n", count_even_numbers(A, N)); 
} 

void test_2(void) 
{
    int A[] = {1}; 
    int N = 1; 

    printf("Number of even elements = %d\n", count_even_numbers(A, N)); 
} 

int count_even_numbers(int A[], int N) 
{
    int nr_even_numbers = 0; 

    for(int i = 0; i < N; ++i) 
        if(A[i] % 2 == 0) 
            nr_even_numbers += 1; 

    return (nr_even_numbers); 
} 
