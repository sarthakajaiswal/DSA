/* 
    @GOAL: to study interface of linked list 
    @DATE: 11 Oct 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

/* Header files */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

/* Symbolic constants */
#define SUCCESS     1 
#define TRUE        1 
#define FALSE       0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY  3 

/* Node layout definition */
struct node 
{
    int data; 
    struct node* next; 
}; 

/* Interface function declarations */
/* List creation functions */
struct node* create_list(void); 

/* Data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 

/* get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* Miscalleneous functions */
int find(struct node* p_list, int f_data); 
int get_list_length(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 
int is_list_empty(struct node* p_list); 

/* List destruction functions */
int destroy_list(struct node* p_list); 

/* Client of linked list */
int main(void) 
{
    struct node* p_list = NULL; 

    return (0); 
} 

/* Server of linked list */
