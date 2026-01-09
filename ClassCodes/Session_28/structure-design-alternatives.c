/*
    @GOAL: study of design alternatives for struct bst
    @DATE: 08 Jan 2026 
    @Author: Sarthak A Jaiswal 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

typedef struct node node_t; 
typedef struct node list_t; 

struct node* create_list(void); 

/////////////////////////////////////////// 

struct bst_node 
{
    int data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

struct bst_node* my_tree = NULL; 

struct bst 
{
    struct bst_node* root_node; 
    int number_of_elements; 
}; 

struct bst* my_tree = malloc(sizeof(struct bst)); 

// to access the root node 
my_tree->root_node; 

// ==================== 

struct dlist_node 
{
    int data; 
    struct list_node* prev; 
    struct list_node* next; 
}; 

struct doubly_circular_linked_list 
{
    struct dlist_node* head_node; 
    size_t number_of_elements; 
}; 

typedef struct dlist_node dlist_node_t; 
typedef struct doubly_circular_linked_list dcll_t; 

dcll_t* create_list(void) 
{
    dcll_t* p_list = NULL; 

    p_list = (dcll_t*)malloc(sizeof(dcll_t)); 
    if(NULL == p_list) 
    {
        // error checking 
    } 

    p_list->head_node = (dlist_node_t*)get_node(0); 
    p_list->head_node->prev = p_list->head_node; 
    p_list->head_node->next = p_list->head_node;  

    p_list->number_of_elements = 0; 

    return (p_list); 
} 

