#include "Date.hpp"

int main() 
{
    Date myDate(31, 1, 2024); 

    myDate.show(); 
    myDate.setMonth(4); 
    myDate.show(); 

    int year = myDate.getYear(); 
    std::cout << "year = " << year << std::endl; 

    return EXIT_SUCCESS; 
} 


