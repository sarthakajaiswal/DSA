/*
    PRACTISE SET 1 

    @Goal:      Write a program that finds and prints all pairs of elements in an array whose 
                sum equals a given target value. Each pair should be printed once. 
    @Date:      12 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void print_pairs_with_given_sum(int* arr, int N, int required_sum);
void print_array(int arr[], int N);  

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 

    printf("test_1():"); 
    test_1(); 
    printf("test_2():"); 
    test_2(); 
    printf("test_3():"); 
    test_3(); 

    return (0); 
} 

void test_1(void) // normal case 
{
    int arr[] = {2, 4, 3, 5, 7, 8, 1}; 
    int N = 7; 
    int required_sum = 9; 

    print_pairs_with_given_sum(arr, N, required_sum); 
} 

void test_2(void) // only 1 element 
{
    int arr[] = {2}; 
    int N = 1; 
    int required_sum = 9; 

    print_pairs_with_given_sum(arr, N, required_sum); 
} 

void test_3(void) // all elements same as required sum 
{
    int arr[] = {7, 7, 7, 7, 7}; 
    int N = 5; 
    int required_sum = 7; 

    print_pairs_with_given_sum(arr, N, required_sum); 
} 

void print_pairs_with_given_sum(int* arr, int N, int required_sum) 
{
    int i, j; 
    int nr_pairs = 0; 

    // code 
    for(i = 0; i < N; ++i) 
    {
        for(j = i + 1; j < N; ++j) 
        {
            if(arr[i] + arr[j] == required_sum) 
            {
                nr_pairs += 1; 
                printf("(%d, %d), ", arr[i], arr[j]); 
            } 
        } 
    } 
    if(nr_pairs == 0) 
        printf("No pairs found\n"); 
    else 
        printf("\b\b\n"); // to erase the 'comma' of last pair 
} 

void print_array(int a[], int N) 
{
    int i = 0; 

    // code 
    while(i < N) 
    {
        printf("%d ", a[i]); 
        i = i + 1; 
    } 
    printf("\n"); 
} 
