// 1 
#include <iostream>

class Date 
{
    public: 
        Date() 
        {
            std::cout << "---- Entered Date::Date() ----" << std::endl; 
            std::cout << "Date::Date() > Address of object to be initialized is = " << std::dec << this << std::endl; 
            std::cout << "---- Leaving Date::Date() ----" << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    std::cout << "---- Entered main() ----" << std::endl; 

    Date myDate1; 
    Date myDate2; 

    std::cout << "&myDate1 = " << std::dec << &myDate1 << std::endl; 
    std::cout << "&myDate2 = " << std::dec << &myDate2 << std::endl; 

    std::cout << "---- Leaving main() ----" << std::endl; 
} 

void test(void) 
{
    std::cout << "--- Entered test() ---" << std::endl; 
    Date X, Y, Z; 
    std::cout << "(&X, &Y, &Z) = " << "(" << &X << " " << &Y << " " << &Z << ")" << std::endl; 
    std::cout << "---- Leabing test() ----" << std::endl; 
} 

// ======================== 

#include <iostream> 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "Entered Date::Date() " << std::endl; 

            std::cout << "Address of obejct to be initialized = " << std::dec << this << std::endl; 

            std::cout << "Leaving Date::Date() " << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    std::cout << "Entered main()" << std::endl; 
    Date myDate1; 
    Date myDate2; 
    std::cout << "&myDate1 = " << &myDate1 << " &myDate2 = " << &myDate2 << std::endl; 
    std::cout << "Leaving main()" << std::endl; 
} 

void test(void) 
{
    std::cout << "Entered test()" << std::endl; 
    Date X, Y, Z; 
    std::cout << "&X = " << std::dec << &X << std::endl 
                << "&Y = " << std::dec << &Y << std::endl 
                << "&Z = " << std::dec << &Z << std::endl; 

    std::cout << "Leaving test() " << std::endl; 
} 

//============= 
#include <iostream> 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "Entered main()" << std::endl; 
            std::cout << "Address of object to be initialized = " << std::dec << this << std::endl; 
            std::cout << "Leaving main()" << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    std::cout << "Entered main()" << std::endl; 

    Date myDate1; 
    Date myDate2; 

    std::cout << "&myDate1 = " << &myDate1 << std::endl 
                << "&myDate2 = " << &myDate2 << std::endl; 

    test(); 

    std::cout << "Leaving main()" << std::endl; 
    return 0; 
} 

void test(void) 
{
    std::cout << "Entered test()" << std::endl; 
    Date X, Y, Z; 
    std::cout << "&X = " << std::dec << &X << std::endl 
                << "&Y = " << std::dec << &Y << std::endl 
                << "&Z = " << std::dec << &Z << std::endl; 
    std::cout << "Leaning test()" << std::endl; 
} 

// ============ 
#include <iostream> 

class Date
{
    public: 
        Date() 
        {
            std::cout << "Entered Date::Date()" << std::endl; 
            std::cout << "Address of object to be initialized = " << this << std::endl; 
            std::cout << "Leaving Date::Date() " << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    std::cout << "Entered main()" << std::endl; 
    
    Date myDate1, myDate2; 

    std::cout << "&myDate1 = " << &myDate1 << " &myDate2 = " << &myDate2 << std::endl; 

    std::cout << "Leaving main()" << std::endl; 
    return 0; 
} 

void test(void) 
{
    std::cout << "Entered test()" << std::endl; 
    Date X, Y, Z; 
    std::cout << "&X = " << &X << " &Y = " << &Y << " &Z = " << &Z << std::endl; 
    std::cout << "Leaving test()" << std::endl; 
} 

//================ 
#include <iostream> 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "Inside Date::Date()" << std::endl; 
            std::cout << "Address of object to be intialized = " << this << std::endl; 
            std::cout << "Leaving Date::Date()" << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    std::cout << "Entered main()" << std::endl; 
    Date myDate1; 
    Date myDate2; 
    std::cout << "&myDate1 = " << &myDate1 << " &myDate2 = " << &myDate2 << std::endl; 
    std::cout << "Leaving main()" << std::endl; 
} 

void test(void) 
{
    std::cout << "Entered test()" << std::endl; 
    Date X, Y, Z; 
    std::cout << "&X = " << &X << " &Y = " << &Y << " &Z = " << &Z << std::endl; 
    std::cout << "Leaving test()" << std::endl; 
} 

