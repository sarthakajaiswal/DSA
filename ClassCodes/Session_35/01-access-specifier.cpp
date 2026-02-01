/* 
    @GOAL:      To study access specifiers of class 
*/ 

#include <iostream> 

class Date 
{
private: 
    int day; 
    int month; 
    int year; 

public: 
    int x; 
    int y; 
    int z; 
}; 

void test(void); 

int main() 
{
    test(); 
    return (0); 
} 

void test() 
{
    Date myDate; 

    myDate.day = 1; 
    myDate.month = 1; 
    myDate.year = 1970; 

    myDate.x = 100; 
    myDate.y = 200; 
    myDate.z = 300; 
} 

/*
class XYZ 
{} 

void test() 
{
    XYZ p; 
} 
*/ 
