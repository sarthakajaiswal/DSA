/*
    PRACTISE SET 1 

    @Goal:      Write a program that finds and returns the index of the first occurence
                of a target element in an array. Return -1 if not found. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int find_index(int A[], int N, int target); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 

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
    int A[5] = {5, 18, 22, 9, 17}; 
    int N = 5; 
    int target = 22; 
    int index = -1; 

    index = find_index(A, N, target); 
    if(index >= 0)
        printf("target found at index = %d\n", index); 
    else 
        printf("target not found\n"); 
} 

void test_2(void) 
{
    int A[1] = {5}; 
    int N = 1; 
    int target = 5; 
    int index = -1; 

    index = find_index(A, N, target); 
    if(index >= 0)
        printf("target found at index = %d\n", index); 
    else 
        printf("target not found\n"); 
} 

void test_3(void) 
{
    int A[1] = {5}; 
    int N = 1; 
    int target = 22; 
    int index = -1; 

    index = find_index(A, N, target); 
    if(index >= 0)
        printf("target found at index = %d\n", index); 
    else 
        printf("target not found\n"); 
} 

int find_index(int A[], int N, int target) 
{
    for(int i = 0; i < N; ++i)  
    {
        if(A[i] == target) 
            return (i); 
    }

    return (-1); 
} 

