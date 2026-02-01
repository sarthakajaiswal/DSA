/*
    @GOAL:      How bad code looks like.  
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <stdio.h>

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date myDate; 

int main(void) 
{
    myDate.day = 24; 
    myDate.month = 1; 
    myDate.year = 2026; 

    printf("%d/%d/%d\n", myDate.day, myDate.month, myDate.year); 

    return (0); 
} 

// Mixing of client and server side code 

// Date type implementation -> server side code 
// Creation of data type instances and using them -> client side code 
// In above example 
// line 4-9 -> server side code 
// line 11, line 15-17, line 19 -> client side 

// 2) Client is making use of server side knowledge 
//      Client is using data type Date with the knowledge of its internal layout 
//      Internal layout 
//          Knowledge of names of members 
//          Knowledge of types of members 
//      In this specific case that data instance has members name 
//      day, month and year and type int, int, int respectively 

