/*
    @GOAL:      learn standard IO in C++
    @DATE:      31 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <iostream> 
#include <cstdlib> 

int main(void) 
{
    std::cout << "Enter an integer: "; 
    int num; 
    std::cin >> num; 

    std::cout << "Enter a floating point number: "; 
    float f_num; 
    std::cin >> f_num; 

    std::cout << "Value(num): " << num << ", value(f_num): " << f_num << std::endl; 

    return EXIT_SUCCESS; 
} 


