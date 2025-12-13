/*
    PRACTISE SET 1 

    @Goal:      Write a program that removes duplicate elements from an array, keeping only the first occurence of 
                each element. Use only the original array (no additional array for storage). Return the new 
                effective length.  
    @Date:      12 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void remove_duplicates(int* arr, int size, int* p_effective_size); 
void print_array(int arr[], int N); 

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

void test_1(void) 
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5}; 
    int N = 8; 
    int effectiveSize = 0; 

    remove_duplicates(arr, N, &effectiveSize); 

    printf("Before remove_duplicates(): "); 
    print_array(arr, N); 
    printf("\n"); 

    printf("After remove duplicates(): "); 
    print_array(arr, effectiveSize); 
    printf("new length = %d\n", effectiveSize);
    printf("\n"); 
} 

void test_2(void) 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int N = 7; 
    int effectiveSize = 0; 

    remove_duplicates(arr, N, &effectiveSize); 

    printf("Before remove_duplicates(): "); 
    print_array(arr, N); 
    printf("\n"); 

    printf("After remove duplicates(): "); 
    print_array(arr, effectiveSize); 
    printf("new length = %d\n", effectiveSize); 
    printf("\n"); 
} 

void test_3(void) 
{
    int arr[] = {2, 2, 2, 2, 2, 2, 2, 2}; 
    int N = 8; 
    int effectiveSize = 0; 

    remove_duplicates(arr, N, &effectiveSize); 

    printf("Before remove_duplicates(): "); 
    print_array(arr, N); 
    printf("\n"); 

    printf("After remove duplicates(): "); 
    print_array(arr, effectiveSize); 
    printf("new length = %d\n", effectiveSize);
    printf("\n"); 
}

void test_4(void) 
{
    int arr[] = {2}; 
    int N = 1; 
    int effectiveSize = 0; 

    remove_duplicates(arr, N, &effectiveSize); 

    printf("Before remove_duplicates(): "); 
    print_array(arr, N); 
    printf("\n"); 

    printf("After remove duplicates(): "); 
    print_array(arr, effectiveSize); 
    printf("new length = %d\n", effectiveSize);
    printf("\n"); 
}

void remove_duplicates(int* arr, int N, int* p_effective_size) 
{
    int i; 
    int effective_size = 1; 

    for(i = 1; i < N; ++i) 
    {
        if(arr[i] != arr[i-1]) 
        {
            effective_size += 1; 
            arr[effective_size - 1] = arr[i]; 
        }
    } 

    *p_effective_size = effective_size; 
} 

void print_array(int arr[], int N) 
{
    int i = 0; 
    while(i < N) 
    {
        printf("%d ", arr[i]); 
        i = i + 1; 
    }
}
