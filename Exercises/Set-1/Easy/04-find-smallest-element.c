/*
    PRACTISE SET 1 

    @Goal:      Write a program that finds and returns the smallest element in array of integers. Do not
                use any buit-in min function. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int get_smallest_element(int A[], int N); 
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
    int A[10] = {23, 7, 45, 12, 89, 3}; 
    int N = 6; 

    printf("smallest element of array = %d\n", get_smallest_element(A, N)); 
}

void test_2(void) 
{
    int A[10] = {23, -7, -45, 0, 89, 3}; 
    int N = 6; 

    printf("smallest element of array = %d\n", get_smallest_element(A, N)); 
}

void test_3(void) 
{
    int A[1] = {0}; 
    int N = 1; 

    printf("smallest element of array = %d\n", get_smallest_element(A, N)); 
}

int get_smallest_element(int A[], int N) 
{
    int smallest_element; 
    int i; 

    smallest_element = A[0]; 
    for(i = 1; i < N; ++i)  
    {
        if(A[i] < smallest_element) 
            smallest_element = A[i]; 
    }

    return (smallest_element); 
} 

