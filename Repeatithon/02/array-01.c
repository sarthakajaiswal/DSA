// 1 
#include <stdio.h> 

int arr[8]; 

int main(void) 
{
    // variable declarations 
    int i; 

    // code 
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i + 1) * 100; 
        i = i + 1; 
    } 

    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 2 
#include <stdio.h> 

int arr[8]; 

int main(void) 
{
    // variable declarations 
    int i; 

    // code 
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i+1); 
        i = i + 1; 
    } 

    // print the array 
    i = 0; 
    while(i < 8) 
    {
        fprintf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 3 
#include <stdio.h> 

int arr[8]; 

int main(void) 
{
    // variable declarations 
    int i; 

    // code 
    //fill the array 
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i + 1) * 100; 
        i = i + 1; 
    } 

    // show the array 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 
} 

// 4
#include <stdio.h> 

int arr[8]; 

int main(void) 
{
    // variable declarations 
    int i; 

    // code 
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i + 1) * 100; 
        i = i + 1; 
    }

    // display the array 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 

// 5 
#include <stdio.h> 

int arr[8]; 

int main(void) 
{
    // variable declarations 
    int i; 

    // code 
    // fill the array 
    i = 0; 
    while(i < 8) 
    {
        arr[i] = (i + 1) * 100; 
        i = i + 1; 
    } 

    // show the array 
    i = 0; 
    while(i < 8) 
    {
        printf("arr[%d] = %d\n", i, arr[i]); 
        i = i + 1; 
    } 

    return (0); 
} 
