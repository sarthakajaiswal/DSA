/*
    PRACTISE SET 1 

    @Goal:      Write a program that calculates and returns the average of all elements
                in an array. Return result as floating-point number. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

float calculate_average(int A[], int N); 

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
    float average = 0.0f; 

    average = calculate_average(A, N); 
    printf("Average of array element = %f\n", average); 
} 

void test_2(void) 
{
    int A[5] = {10}; 
    int N = 1; 
    float average = 0.0f; 

    average = calculate_average(A, N); 
    printf("Average of array element = %f\n", average); 
} 

float calculate_average(int A[], int N) 
{
    int sum_of_all_elements(int A[], int N); 

    float average = 0.0f; 

    average = sum_of_all_elements(A, N) / (float)N; 
    return (average); 
} 

int sum_of_all_elements(int A[], int N) 
{
    int i; 
    int sum = 0; 

    for(i = 0; i < N; ++i)
        sum = sum + A[i]; 

    return (sum); 
} 
