/*
    PRACTISE SET 1 

    @Goal:      Write a program that checks whether a given target element exist in an array. 
                Return "Found" if present otherwise "Not Found". 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

#define FOUND       1 
#define NOT_FOUND   0 

typedef int status_t; 

status_t check_if_element_exist(int A[], int N, int f_element); 

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
    int A[10] = {5, 12, 8, 3, 17}; 
    int N = 6; 
    int target = 8; 

    int result = check_if_element_exist(A, N, target); 
    if(result == FOUND) 
        printf("Found\n"); 
    else 
        printf("Not Found\n"); 
}

void test_2(void) 
{
    int A[10] = {-5, 2, 34, 3, 17}; 
    int N = 6; 
    int target = 8; 

    int result = check_if_element_exist(A, N, target); 
    if(result == FOUND) 
        printf("Found\n"); 
    else 
        printf("Not Found\n"); 
}

status_t check_if_element_exist(int A[], int N, int f_element) 
{
    int i; 

    for(i = 1; i < N; ++i)  
        if(A[i] == f_element) 
            return (FOUND); 
            
    return (NOT_FOUND); 
} 

