/*
    PRACTISE SET 1 

    @Goal:      Write a program that finds and returns the largest element in array of integers. Do not
                use any buit-in max function. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int get_largest_element(int A[], int N); 
void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void) 
{
    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    puts("test_3():"); 
    test_3(); 

    return (0); 
} 

void test_1(void) 
{
    int A[10] = {45, 12, 78, 34, 56}; 
    int N = 5; 

    printf("Largest element of array = %d\n", get_largest_element(A, N)); 
} 

void test_2(void) 
{
    int A[10] = {23, 7, -45, 0, 89, 3}; 
    int N = 6; 

    printf("Largest element of array = %d\n", get_largest_element(A, N)); 
} 

void test_3(void) 
{
    int A[1] = {23}; 
    int N = 1; 

    printf("Largest element of array = %d\n", get_largest_element(A, N)); 
} 

int get_largest_element(int A[], int N) 
{
    int largest_element; 
    int i; 

    largest_element = A[0]; 
    for(i = 1; i < N; ++i)  
    {
        if(A[i] > largest_element) 
            largest_element = A[i]; 
    }

    return (largest_element); 
} 

