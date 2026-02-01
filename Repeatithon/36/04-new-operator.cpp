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

            std::cout << "Date::Date() : object at address: " << this 
                    << " is initialized with " << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main() 
{
    Date* pDate = new Date(31, 1, 2026); 

    pDate->show(); 

    delete pDate; 
    pDate = 0; 

    return EXIT_SUCCESS; 
} 

// ======= 2 ====== 
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
                    << " is initialized to " << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date* pDate = new Date(31, 1, 2026); 
    pDate->show(); 
    delete pDate; 
    pDate = 0; 

    return EXIT_SUCCESS; 
} 

// ======= 3 ====== 
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

            std::cout << "Date::Date() > object at address " << this << " is initialized by " 
                    << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date* pDate = new Date(31, 1, 2026); 
    pDate->show(); 
    delete pDate; 
    pDate = 0; 
    return EXIT_SUCCESS; 
} 

// ======= 4 ======
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

            std::cout << "Date::Date() > Object at address " << this << " is initialized to " 
                        << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show()
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void)
{
    Date* pDate = new Date(31, 1, 2026); 
    pDate->show(); 
    delete pDate; 
    pDate = 0; 
    return EXIT_SUCCESS;     
} 

// ======= 5 ======
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

            std::cout << "Date::Date() > object at adress " << this << " is initialized to " 
                    << init_day << "/" << init_month << "/" << init_year << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date* pDate = new Date(31, 1, 2026); 

    pDate->show(); 
    pDate = 0; 

    return EXIT_SUCCESS; 
} 
