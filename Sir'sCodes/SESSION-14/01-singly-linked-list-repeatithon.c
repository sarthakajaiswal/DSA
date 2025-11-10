// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 3 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <assert.h> 

// 4 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

// 5 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

///////////////////////////////////
// Symbolic constants 
// 1 
#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

// 2 
#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

// 3 
#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

// 4 
#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

// 5 
#define SUCCESS 1 
#define TRUE 1 
#define FALSE 0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY 3 

// 1 
struct node 
{
    int data; 
    struct node* next; 
}; 

// 2 
struct node 
{
    int data; 
    struct node* next; 
}

//3 
struct node 
{
    int data; 
    struct node* next; 
}; 

// 4 
struct node 
{
    int data; 
    struct node* next; 
}; 

// 5 
struct node 
{
    int data; 
    struct node* next; 
}; 
///////////////////////////////////////////////////

// Definition of create_list() 

struct node* create_list(void)
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
}

// 1 
struct node* create_list(void) 
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
}

// 2 
struct node* create_list(void)
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
}

// 3 
struct node* create_list(void)
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    return (p_new_list); 
}

// 4 
struct node* create_list(void)
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list)
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE);
    }

    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list); 
}

// 5 
struct node* create_list(void)
{
    struct node* p_new_list = NULL; 

    p_new_list = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_list) 
    {
        puts("out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_list->data = 0; 
    p_new_list->next = NULL; 

    return (p_new_list);
}


