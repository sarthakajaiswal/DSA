/*
    PRACTISE SET 1 

    @Goal:      Write a program that counts how many times a specific value appears in array. 
    @Date:      11 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

int copy_array(int A[], int N, int target); 

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
    int A[10] = {4, 2, 7, 2, 9, 2, 5}; 
    int N = 6; 
    int target = 2; 

    printf("target found %d times in array\n", copy_array(A, N, target));  
}

void test_2(void) 
{
    int A[1] = {4}; 
    int N = 1; 
    int target = 2; 

    printf("target found %d times in array\n", copy_array(A, N, target));  
}

int copy_array(int A[], int N, int target) 
{
    int nr_occurences = 0; 
    int i; 

    for(i = 1; i < N; ++i)  
        if(A[i] == target) 
            nr_occurences += 1; 
            
    return (nr_occurences); 
} 

