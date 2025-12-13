/*
    PRACTISE SET 1 

    @Goal:      Write a program to find second largest element in array. If elements are same 
                return -1 do not sort the array. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int second_largest_element(unsigned int A[], int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 
    void test_4(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    puts("test_3():"); 
    test_3(); 
    puts("test_4():"); 
    test_4(); 

    return (0); 
} 

void test_1(void) // normal case 
{
    unsigned int A[] = {12, 35, 1, 10, 34, 1}; 
    int N = 6; 

    printf("second largest element = %d\n", second_largest_element(A, N)); 
} 

void test_2(void) // exactly two elements 
{
    unsigned int A[] = {12, 35}; 
    int N = 2; 

    printf("second largest element = %d\n", second_largest_element(A, N)); 
} 

void test_3(void) // all elements same 
{
    unsigned int A[] = {12, 12, 12, 12}; 
    int N = 4; 

    printf("second largest element = %d\n", second_largest_element(A, N)); 
} 

void test_4(void) // elements less than required (here 2) 
{
    unsigned int A[] = {12}; 
    int N = 1; 

    printf("second largest element = %d\n", second_largest_element(A, N)); 
} 

int second_largest_element(unsigned int A[], int N) 
{
    int largest_element_1, largest_element_2; 

    largest_element_1 = A[0]; 
    largest_element_2 = -1; 

    for(int i = 1; i < N; ++i) 
    {
        if(A[i] > largest_element_1)
        {
            largest_element_2 = largest_element_1; 
            largest_element_1 = A[i]; 
        }
        else if(A[i] < largest_element_1 && A[i] > largest_element_2) 
        {
            largest_element_2 = A[i]; 
        }
    } 

    return (largest_element_2); 
} 
