#include "Date.hpp" 

void testDate(); 

int main(void) 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* pDate = allocateDateInstance(25, 1, 2026); 
    pDate->day = 18; // error 
} 

#include "Date.hpp" 

void testDate(); 

int main(void) 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* p = allocateDateInstance(1, 1, 1970); 
    p->day = 10; // error 
} 

#include "Date.hpp" 

void testDate(); 

int main() 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* today = allocateDateInstance(1, 1, 1970); 
    today->day = 10; //error 
} 

#include "Date.hpp" 

void testDate(); 

int main(void) 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* d = allocateDateInstance(1, 1, 1970); 
    d->day = 0; // error 
} 

#include "Date.hpp" 

void testDate(); 

int main() 
{
    testDate(); 
    return 0; 
} 

void testDate() 
{
    Date* d = allocateDateInstance(1, 1, 1970); 
    d->day = 10; // error 
} 
