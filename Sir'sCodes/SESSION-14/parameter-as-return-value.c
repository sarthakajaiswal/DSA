#include <stdio.h> 

#define SUCCESS 1 

int test_function(int* p_return_value); 

int main(void)
{
    int status = -1; 
    int data = -1; 

    printf("BEFORE CALL to test_function():status%d\n", status); 
    printf("BEFORE CALL to test_function():data=%d\n", data); 
    status = test_function(&data); 

    printf("AFTER CALL to test_function():status = %d\n", status); 
    printf("AFTER CALL TO test_function():data = %d\n", data); 

    return (0); 
}

int test_function(int* p_return_value)
{
    *p_return_value = 10; 
    return (SUCCESS); 
}