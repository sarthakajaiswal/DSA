#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
    private: 
        int day; 
        int month; 
        int year;  
}; 

Date* allocateDateInstance(int day, int month, int year); 
void releaseDateInstance(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void showDate(Date* pDate); 

#endif // DATE_HPP 

#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 
}; 

Date* allocateDateInstance(int day, int month, int year); 
void releaseDate(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void showDate(Date* pDate); 

#endif // DATE_HPP 

#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
    int day; 
    int month; 
    int year; 
}; 

Date* allocateDateInstance(int init_day, int init_month, int init_year); 
void releaseDate(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void showDate(Date* pDate); 

#endif // DATE_HPP 

#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
    int day; 
    int month; 
    int year; 
}; 

Date* allocateDateInstance(int init_day, int init_month, int init_year); 
void releaseDateInstance(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void showDate(Date* pDate); 

#endif // DATE_HPP 


#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 
}; 

Date* allocateDateInstance(int init_day, int init_month, int init_year); 
void releaseDateInstance(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_day); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void showDate(Date* pDate); 

#endif // DATE_HPP 

#ifndef DATE_HPP 
#define DATE_HPP 

class Date 
{
private: 
    int day; 
    int month; 
    int year; 
}; 

Date* allocateDateInstance(int init_day, int init_month, int init_year); 
void releaseDateInstance(Date* pDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int new_date); 
void setMonth(Date* pDate, int new_month); 
void setYear(Date* pDate, int new_year); 

void show(Date* pDate); 

#endif // DATE_HPP 
