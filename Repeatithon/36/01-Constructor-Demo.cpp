#include <iostream> 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "In Date::Date()" << std::endl; 
        } 
};

void test(void); 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 

    return (0);
} 

void test(void) 
{
    Date X, Y, Z; 
} 

//====================== 

#include <iostream> 

class Date 
{
    public: 
        void show() 
        {
            std::cout << "In Date::Date()" << std::endl; 
        } 
};  

void test(void); 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 
    return (0); 
} 

void test(void)  
{
    Date X, Y, Z; 
} 

// ======================== 
#include <iostream> 

class Date 
{
    public: 
        void show() 
        {
            std::cout << "In Date::Date()" << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 
    return 0; 
} 

void test(void) 
{
    Date X, Y, Z; 
} 

//====================== 
#include <iostream> 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "In Date::Date()" << std::endl; 
        } 
}; 

void test(void); 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 
    return 0; 
} 

void test(void) 
{
    Date X, Y, Z; 
} 

//================= 
#include <iostream> 

class Date 
{
    public: 
        void show() 
        {
            std::cout << "In Date::Date()" << std::endl; 
        } 
};  

void test(void); 

int main(void) 
{
    Date myDate1; 
    Date myDate2; 

    test(); 
    return 0; 
} 

void test(void) 
{
    Date X, Y, Z; 
} 
