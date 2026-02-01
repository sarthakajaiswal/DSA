/* 
    @GOAL:  study concept of new operator 
    @DATE:  01 February 2026 
*/ 

// new operator of C++ programming language enables programmer to allocate
// dynamic object with automated call to cnstructor 

// Reason: new is a language operator and not a library function 
// Therefore, compiler must take the responsibility 
// to generate assembly code that is responsible for 
// 1) allocating space required for object 
// 2) calling constructor for that object 


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

            std::cout << "Date::Date()> object at address:" << this 
                        << " is initialized with " << init_day << "/" << init_month << "/" 
                        << init_year << "values" << std::endl; 
        } 

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        } 
}; 

int main(void) 
{
    Date* pDate = new Date(31, 1, 2026);
    /* 
        Assembly code generated for above statment looks like this 
        pushl   $12 
        call    malloc 

        #part 2 
        pushl   $2026 
        $pushl  $1 
        pushl   $31 
        pushl   %eax 
        call    Date::Date 
        movl    %eax, -4(%ebp) 
    */ 
    
    pDate->show(); // Date::Date(pDate) 

    delete pDate; 
    pDate = 0; 

    return EXIT_SUCCESS; 
} 

