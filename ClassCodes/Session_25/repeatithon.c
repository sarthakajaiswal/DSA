// 1 
#include <stdio.h> 
#include <stdlib.h> 

#define SUCCESS     1 
#define TRUE        1 

// node layout definition 
struct bst_node
{
    int data; 
    struct node* left; 
    struct node* right; 
    struct node* parent; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

// interface function declarations 
struct bst* create_bst(void); 
int insert(struct bst* p_bst, int new_data); 
void inorder_tranversal(struct bst* p_bst); 
int destroy_bst(struct bst** pp_bst); 

// helper routines 
void preorder(struct bst_node* node); 
void destroy(struct bst_node* node); 

// 2 
#include <stdio.h> 
#include <stdlib.h> 

// symbolic constants 
#define SUCCESS     1 
#define TRUE        1 

// node layout definition 
struct bst_node 
{
    int data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
};  

struct bst
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

// interface function declarations 
struct bst* create_bst(void); 
int insert(struct bst* p_bst, int new_data); 
void inorder_traversal(struct bst* p_bst); 
int destroy_bst(struct bst** pp_bst); 

// helper functions 
void inorder(struct bst_node* node); 
void destroy(struct bst_node* node); 

// 3 
#include <stdio.h> 
#include <stdlib.h> 

// symbolic constannts 
#define SUCCESS     1 
#define SUCCESS     1 

// node layout definition
struct bst_node 
{
    int data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

// interface function declarations 
struct bst* create_list(void); 
int insert_bst(struct bst* p_bst, int new_data); 
void inorder_traversal(struct bst* p_bst); 
int destroy_bst(struct bst** pp_bst); 

// helper functions 
void inorder(struct bst_node* node); 
void destroy(struct bst_node* node); 

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 
    
    // code 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_new_node->data = new_data; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 
    p_new_node->parent = NULL; 


    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    } 

    // insert into non-empty binary search tree 
    struct bst_node* run = p_bst->p_root_node; 
    while(TRUE) 
    {           
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = p_new_node; 
                run->left->parent = run; 
                break; 
            } 
            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = p_new_node; 
                run->right->parent = run; 
                break; 
            } 
            run = run->right; 
        }
    } 

    p_bst->number_of_elements += 1; 
    return (SUCCESS); 
} 

// insert into non-empty binary search tree 
int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    // code 
    // allocate and initialize new node 
    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 
    p_new_node->parent = NULL; 

    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    }

    struct bst_node* run = p_bst->p_root_node; 

    return (SUCCESS); 
} 


