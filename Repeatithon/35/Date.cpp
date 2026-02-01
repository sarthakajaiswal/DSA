#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        } 

        int getDay() 
        {
            return this->day; 
        } 

        int getMonth() 
        {
            return this->month; 
        } 

        int getYear() 
        {
            return this->year; 
        } 

        void setDay(int new_day) 
        {
            this->day = new_day; 
        } 

        void setMonth(int new_month) 
        {
            this->month = new_month; 
        } 

        void setYear(int new_year) 
        {
            this->year = new_year; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

void test_date(); 

int main() 
{
    test_date(); 
    return 0; 
} 

void test_date() 
{
    Date myDate; 
    myDate.initialize(1, 1, 1970); 

    int day = myDate.getDay(); 
    int month = myDate.getMonth(); 
    int year = myDate.getYear(); 

    std::cout << day << "/" << month << "/" << year << std::endl; 

    myDate.setDay(2); 
    myDate.setMonth(3); 
    myDate.setYear(2000); 

    myDate.show(); 
} 

//=============== 

#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        } 

        int getDay() 
        {
            return this->day; 
        } 

        int getMonth() 
        {
            return this->month; 
        } 

        int getYear() 
        {
            return this->year; 
        } 

        void setDay(int new_day) 
        {
            this->day = new_day; 
        } 

        void setMonth(int new_month) 
        {
            this->month = new_month; 
        } 

        void setYear(int new_year) 
        {
            this->year = new_year; 
        } 

        void show() 
        {
            std::cout << day << "/" << month << "/" << year << std::endl; 
        } 
}; 

void test_date(); 

int main() 
{
    test_date(); 
    return 0; 
} 

void test_date() 
{
    Date today; 
    today.initialize(1, 1, 1970); 

    int day = today.getDay(); 
    int month = today.getMonth(); 
    int year = today.getYear(); 

    std::cout << day << "/" << month << "/" << year << std::endl; 

    today.setDay(1); 
    today.setMonth(2); 
    today.setYear(2026); 

    today.show(); 
} 

//============= 
#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_year; 
            this->year = init_year; 
        } 

        int getDay() 
        {
            return this->day; 
        } 

        int getMonth() 
        {
            return this->month; 
        } 

        int getYear() 
        {
            return this->year; 
        } 

        void setDay(int new_day) 
        {
            this->day = new_day; 
        } 

        void setMonth(int new_month) 
        {
            this->month = new_month; 
        } 

        void setYear(int new_year) 
        {
            this->year = new_year; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

void test_date(); 

int main() 
{
    test_date(); 
    return 0; 
} 

void test_date() 
{
    Date d; 
    d.initialize(1, 2, 2003); 

    int day = d.getDay(); 
    int month = d.getMonth(); 
    int year = d.getYear(); 

    std::cout << day << "/" << month << "/" << year << std::endl; 

    d.setDay(12); 
    d.setMonth(12); 
    d.setYear(2025); 

    d.show(); 
} 

//=========== 
#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        } 

        int getDay() 
        {
            return this->day; 
        } 

        int getMonth() 
        {
            return this->month; 
        } 

        int getYear() 
        {
            return this->year; 
        } 

        void setDay(int new_day) 
        {
            this->day = new_day; 
        } 

        void setMonth(int new_month) 
        {
            this->month = new_month; 
        } 

        void setYear(int new_year) 
        {
            this->year = new_year; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

void test_date(); 

int main() 
{
    test_date(); 
    return 0; 
} 

void test_date() 
{
    Date today; 
    today.initialize(1, 1, 1970); 

    int day = today.getDay(); 
    int month = today.getMonth(); 
    int year = today.getYear(); 

    std::cout << day << "/" << month << "/" << year << std::endl; 

    today.setDay(1); 
    today.setMonth(2); 
    today.setYear(2026); 

    today.show(); 
} 

// ============= 

#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        } 

        int getDay() 
        {
            return this->day; 
        } 

        int getMonth() 
        {
            return this->month; 
        } 

        int getYear() 
        {
            return this->year; 
        } 

        void setDay(int new_day) 
        {
            this->day = new_day; 
        } 

        void setMonth(int new_month) 
        {
            this->month = new_month; 
        } 

        void setYear(int new_year) 
        {
            this->day = new_year; 
        } 

        void show() 
        {
            std::cout << day << "/" << month << '/' << year << std::endl; 
        } 
}; 

void test_date(); 

int main() 
{
    test_date(); 
    return 0; 
} 

void test_date()
{
    Date d; 
    d.initialize(1, 1, 1970); 

    int day = d.getDay(); 
    int month = d.getMonth(); 
    int year = d.getYear(); 

    std::cout << day << "/" << month << "/" << year << std::endl; 

    d.setDay(12); 
    d.setMonth(12); 
    d.setYear(2012); 

    d.show(); 
} 

//=========== 
