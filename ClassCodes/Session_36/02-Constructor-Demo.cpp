/* 
    @GOAL:  study concept of constructor
    @DATE:  01 February 2026 
*/ 

#include <iostream> 
#include <cstdio> 

class Date 
{
    public: 
        Date() 
        {
            std::cout   << "---- Entered Date()::Date() ----" << std::endl; 
            std::cout   << "Date::Date():Address of object to be initialized: " 
                        << std::dec << this << std::endl; 
            std::cout   << "---- Leavind Date::Date() ----" << std::endl; 
        }   
}; 

void test(void); 

int main(void) 
{
    std::cout <<    "---- Entered main() ----" << std::endl; 
    Date myDate1; 
    Date myDate2; 

    std::cout <<    "&myDate1: " << std::dec << &myDate1 << std::endl; 
    std::cout <<    "&myDate2: " << std::dec << &myDate2 << std::endl; 

    test(); 

    std::cout <<    "---- Leavind main() ----" << std::endl; 
    return (0); 
} 

void test() 
{
    std::cout <<    "---- Entered test() ----" << std::endl; 

    Date X, Y, Z; 
    std::cout   << "&myDate2: " << std::dec << &X << std::endl 
                << "&myDate2: " << std::dec << &Y << std::endl 
                << "&myDate2: " << std::dec << &Z << std::endl; 

    std::cout <<    "---- Leaving test() ----" << std::endl; 
} 


