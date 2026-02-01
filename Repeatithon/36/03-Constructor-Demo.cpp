#include <iostream> 
#include <cstdlib> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year) 
        {
            this->day = init_day;
            this->month = init_month; 
            this->year = init_year; 

            std::cout << "Date::Date()> object at address: " << this 
                    << " is initialized with " << init_day << "/" << init_month << "/" << init_year 
                    << "values" << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main() 
{
    Date myDate(31, 1, 2026); 
    std::cout << "main():address of myDate: " << &myDate << std::endl; 
    myDate.show(); 
    
    return EXIT_SUCCESS; 
} 

// ====== 2 ================== 
#include <iostream> 
#include <cstdlib> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 

            std::cout << "Date::Date() > object at address " << this 
                        << " is initialized with " << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date myDate(31, 1, 2026); 

    std::cout << "main(): address of myDate = " << &myDate << std::endl; 
    myDate.show(); 

    return EXIT_SUCCESS; 
} 

// =========== 3 ============= 
#include <iostream> 
#include <cstdio> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month;
            this->year = init_year; 

            std::cout << "Date::Date() > Object at address : " << this 
                        << " is iniialized to " << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 

        void show() 
        {
            std::cout << day << "/" << month << "/" << year << std::endl; 
        } 
}; 

int main(void) 
{
    Date myDate(31, 1, 2026); 
    std::cout << "&myDate = " << &myDate << std::endl; 
    myDate.show(); 

    return EXIT_FAILURE; 
} 

// ======== 4 =========== 
#include <iostream> 
#include <cstdlib> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 

            std::cout << "Date::Date() > object at address: " << this 
                        << "is initialized with " << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date myDate(31, 1, 2026); 

    std::cout << "main(): address of myDate = " << &myDate << std::endl; 
    myDate.show(); 

    return EXIT_FAILURE; 
} 

// ====== 5 =========== 
#include <iostream> 
#include <cstdlib> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year)  
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 

            std::cout << "Date::Date() > object at address " << this << " is initialized to " 
                        << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date myDate(31, 1, 2026); 
    
    std::cout << "main() > address of myDate = " << &myDate << std::endl; 
    myDate.show(); 

    return EXIT_SUCCESS; 
} 

