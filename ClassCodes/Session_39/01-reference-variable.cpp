#include <iostream> 

void swap(int &ref_num1, int &ref_num2); 

int main(void) 
{
    int num = 100; 
    int &x = num; 

    std::cout << "x: " << x << std::endl; 
    x = 200; 
    std::cout << "num: " << num << std::endl; 

    int a = 10, b = 20; 
    
    std::cout << "Before swap: a=" << a << " b=" << b << std::endl; 
    swap(a, b); 
    std::cout << "After swap: a=" << a << " b=" << b << std::endl; 

    return (0); 
} 

void swap(int &ref1, int &ref2) 
{
    int tmp; 

    tmp = ref1; 
    ref1 = ref2; 
    ref2 = tmp; 
} 
