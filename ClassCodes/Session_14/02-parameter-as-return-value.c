/* 
    @GOAL: To study parameterised return value concept 
    @DATE: 08 NOV 2025
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 

#define SUCCESS  1 

int test_function(int* p_return_value); 

int main(void) 
{
    // variable declarations 
    int status = -1; 
    int data = -1; 

    // code 
    printf("BEFORE call to test_function(): status = %d\n", status); 
    printf("BEFORE call to test_function(): data = %d\n", data); 

    status = test_function(&data); 

    printf("AFTER call to test_function(): status = %d\n", status); 
    printf("AFTER call to test_function(): data = %d\n", data); 

    return (0); 
} 

int test_function(int* p_return_value) 
{
    *p_return_value = 10; 
    return (SUCCESS); 
} 
