/* Header files */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

/* Symbolic constants */
#define SUCCESS             0 
#define TRUE                1 
#define FALSE               0 
#define LIST_DATA_NOT_FOUND 1 
#define LIST_EMPTY          2 

/*  Node layout definition  */
struct node 
{
    int data; 
    struct node* next; 
}; 

/* Interface functions declarations */
/* List creation function */
struct node* create_list(void); 

/* Data addition functions */
int insert_start(struct node* p_list, int new_data); 
int insert_end(struct node* p_list, int new_data); 
int insert_after(struct node* p_list, int existing_data, int new_data); 
int insert_before(struct node* p_list, int existing_data, int new_data); 

/* Get functions */
int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

/* Pop Functions */
int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

/* Remove functions */
int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

/* Miscallaneous functions */
int find(struct node* p_list, int f_data); 
int get_list_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
void show_list(struct node* p_list, const char* msg); 

/* List destruction function */
int destroy_list(struct node* p_list); 

/* Client of linked list */
int main(void)
{
    struct node* p_list = NULL; 
    
    return (0); 
}

/* Server of linked list */