#include <iostream> 
#include <stdexcept> 

double my_sqrt(double x); 

int main() 
{
    double result; 

    try{ 
        result = my_sqrt(-1.0); 
    } 
    catch(const std::domain_error& e) 
    {
        std::cout << e.what(); 
    } 

    std::cout << "Application terminated successfully" << std::endl; 
    return 0; 
} 

double my_sqrt(double x) 
{
    std::cout << "---- Entered my_sqrt() ----" << std::endl; 
    if(x < 0.0) 
        throw std::domain_error("square root of negative number cannot be comuted"); 
    
    std::cout << "sqrt = %d\n" << x << std::endl; 
    std::cout << "---- Leaving my_sqrt() ----" << std::endl; 
    return 0.0; 
} 

