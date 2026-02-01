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
            std::cout << "Inside Date::Date()" << std::endl; 
        } 
}; 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 

    return (0); 
} 

void test() 
{
    Date X, Y, Z; 
} 


