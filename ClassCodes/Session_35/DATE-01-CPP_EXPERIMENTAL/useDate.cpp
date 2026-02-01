/* 
    @GOAL:  To study idea behind 'class'
    @DATE:  31 January 2026 
*/ 

#include "Date.hpp" 

void testDate(); 

int main() 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* pDate = allocateDate(25, 1, 2026); 

    pDate->day = 18; // Eror setDay(pDate, 18) 
} 
