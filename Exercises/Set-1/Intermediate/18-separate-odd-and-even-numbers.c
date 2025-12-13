/*
    PRACTISE SET 1 

    @Goal:      Write a program to rearrange an array so that all even numbers appear before all odd numbers. 
                The relative order within even or odd groups does not matter. Do this in-place. 
    @Date:      13 Dec 25 
    @Author:    Sarthak A. Jaiswal 
*/

#include <stdio.h> 

void separate_odd_and_even_numbers(int a[], int N); 
void print_array(int [], int N); 

int main(void) 
{
    void test_1(void); 
    void test_2(void); 
    void test_3(void); 
    void test_4(void); 
    void test_5(void); 
    void test_6(void); 
    void test_7(void); 

    puts("test_1():"); 
    test_1(); 
    puts("test_2():"); 
    test_2(); 
    puts("test_3():"); 
    test_3(); 
    puts("test_4():"); 
    test_4(); 
    puts("test_5():"); 
    test_5(); 
    puts("test_6():"); 
    test_6(); 
    puts("test_7():"); 
    test_7(); 

    return (0); 
} 

void test_1(void) // general case 
{
    int arr[] = {12, 7, 3, 8, 15, 4, 9, 2}; 
    int N = 8; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
} 

void test_2(void) // only two elements 1st-even 2nd-odd
{
    int arr[] = {12, 7}; 
    int N = 2; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
}

void test_3(void) // only two elements 1st-odd 2nd-even
{
    int arr[] = {7, 12}; 
    int N = 2; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
}

void test_4(void) // all even 
{
    int arr[] = {2, 4, 6, 8, 10}; 
    int N = 5; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
} 

void test_5(void) // all odd 
{
    int arr[] = {1, 3, 5, 7, 9, 11}; 
    int N = 6; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
} 

void test_6(void) // only 1 element 
{
    int arr[] = {3}; 
    int N = 1; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
} 

void test_7(void) // already separated 
{
    int arr[] = {12, 2, 4, 6, 4, 1, 3, 27, 15}; 
    int N = 9; 

    printf("Before separation: "); 
    print_array(arr, N); 
    separate_odd_and_even_numbers(arr, N); 
    printf("After separation: "); 
    print_array(arr, N); 
}

void separate_odd_and_even_numbers(int a[], int N) 
{
    int forward_counter, reverse_counter; 

    forward_counter = 0; 
    reverse_counter = N-1; 

    while(forward_counter < reverse_counter) 
    {
        while(a[forward_counter] % 2 == 0) 
        {
            forward_counter += 1; 
        } 
        while(a[reverse_counter] % 2 != 0) 
        {
            reverse_counter -= 1; 
        }

        if(forward_counter >= reverse_counter) 
            break; 

        int tmp; 
        tmp = a[forward_counter]; 
        a[forward_counter] = a[reverse_counter]; 
        a[reverse_counter] = tmp; 

        forward_counter += 1; 
        reverse_counter -= 1; 
    } 
} 

void print_array(int arr[], int N) 
{
    int i = 0; 

    // code 
    while(i < N) 
    {
        printf("%d ", arr[i]); 
        i = i + 1; 
    } 
    printf("\n"); 
} 
