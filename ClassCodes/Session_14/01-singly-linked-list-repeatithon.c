// header files 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 
#include <stdio.h> 

// 2 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

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

/////////////////////////// 
// symbolic constants 
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
#define SUCCES 1 
#define TRUE 1 
#define ALSE 0 
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
}; 

// 3 
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

//////////////////////////////// 
// definition of create_list() 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_node->next = NULL; 
    p_new_node->data = 0; 
    
    return (p_new_node); 
}

// 1 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node )
    {
        printf("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_node->data = 0; 
    p_new_node->next = NULL; 

    return (p_new_node); 
} 

// 2 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_node->data = 0; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}

// 3 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(p_new_node == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_node->data = 0; 
    p_new_node->next = NULL; 

    return (p_new_node); 
} 

// 4 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_new_node->next = NULL; 
    p_new_node ->data = 0; 

    return (p_new_node); 
}

// 5 
struct node* create_list(void) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == p_new_node) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_node->data = 0; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}



