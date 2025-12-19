/* 
    @GOAL: Session25 Repeatithon 
    @DATE: 20 DEC 2025 
*/

#include <stdio.h> 
// #include <stdio.h> 
// #include <stdio.h> 
// #include <stdio.h> 
// #include <stdio.h> 
#include <stdlib.h> 
// #include <stdlib.h> 
// #include <stdlib.h> 
// #include <stdlib.h> 
// #include <stdlib.h> 
#include <assert.h> 

// sumbolic constants 
#define SUCCESS     1 
#define TRUE        1 
// #define SUCCESS     1 
// #define TRUE        1 
// #define SUCCESS     1 
// #define TRUE        1 
// #define SUCCESS     1 
// #define TRUE        1 
// #define SUCCESS     1  
// #define TRUE        1 

// structure layout definition 
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

// // 2 
// struct bst_node 
// {
//     int data; 
//     struct node* parent; 
//     struct node* left; 
//     struct node* right; 
// }; 

// struct bst 
// {
//     struct bst_node* parent_node; 
//     size_t number_of_elements; 
// }; 

// // 3 
// struct bst_node 
// {
//     int data; 
//     struct bst_node* parent; 
//     struct bst_node* left; 
//     struct bst_node* right; 
// }; 

// struct bst 
// {
//     struct bst_node* p_root_node; 
//     size_t number_of_elements; 
// }; 

// // 3 
// struct bst_node 
// {
//     int data; 
//     struct bst_node* parent; 
//     struct bst_node* left; 
//     struct bst_node* right; 
// }; 

// struct bst 
// {
//     struct bst_node* p_root_node; 
//     size_t number_of_elements; 
// }; 

// // 5 
// struct bst_node 
// {
//     int data; 
//     struct bst_node* parent; 
//     struct bst_node* left; 
//     struct bst_node* right; 
// }; 

// struct node 
// {
//     struct bst_node* p_root_node; 
//     size_t number_of_elements; 
// }; 

// interface function declarations 
// allocate a new instance of binary search tree 
struct bst* create_bst(void); 

// insert a new data into bst 
int insert_bst(struct bst* p_bst, int new_data); 

// travel through all elements of given binary search tree 
// in 'inorder' traversal sequence 
void inorder_traversal(struct bst* p_bst); 

// destroy given instance of binary search tree 
int destroy_bst(struct bst** pp_bst); 

// Helper functions 
// helper function for inorder_traversal() 
void inorder(struct bst_node* p_node); 
// helper function for destroy_list() 
void destroy(struct bst_node* node); 

// client side 
int main(void) 
{
    struct bst* p_bst = NULL; 
    int status; 
    int data[] = {100, 50, 150, 25, 65, 125, 175, 70, 130, 200}; 
    int i; 

    p_bst = create_bst(); 
    for(i = 0; i < sizeof(data)/sizeof(data[0]); ++i) 
        insert_bst(p_bst, data[i]); 

    inorder_traversal(p_bst); 

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    return (0); 
} 

// interface function definitions 
struct bst* create_bst(void) 
{
    struct bst* p_bst = NULL; 

    p_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(p_bst == NULL) 
    {
        fprintf(stderr, "create_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_bst->p_root_node = NULL; 
    p_bst->number_of_elements = 0; 

    return (p_bst); 
} 

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if binary tree is empty 
    // if it is then insert new node at root position 
    // increase the number of elements by 1 and return 
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

void inorder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    printf("[END]\n"); 
}

// destroy the given instance of binary search tree 
int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    p_bst = *pp_bst; 
    destroy(p_bst->p_root_node); 
    *pp_bst = NULL; 
    return (SUCCESS); 
} 

// helper functions 
void inorder(struct bst_node* p_node) 
{
    if(p_node == NULL) 
        return; 

    inorder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right); 
} 

void destroy(struct bst_node* node) 
{
    if(node == NULL) 
        return; 
    
    if(node->left) 
        destroy(node->left); 
    if(node->right) 
        destroy(node->right); 

    free(node); 
    node = NULL; 
} 

// ==============================================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// symbolic constants 
#define SUCCESS     1 
#define TRUE        1 
#define SUCCESS     1 
#define TRUE        1 
#define SUCCESS     1 
#define TRUE        1 
#define SUCCESS     1 
#define TRUE        1 
#define SUCCESS     1 
#define TRUE        1 

// structure layout definition 
struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_parent_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    size_t number_of_elements; 
}; 

// ============= 
struct bst* create_bst(void); 
struct bst* create_bst(void); 
struct bst* create_bst(void); 
struct bst* create_bst(void); 
struct bst* create_bst(void); 

int insert_bst(struct bst* p_bst, int new_data); 
int insert_bst(struct bst* p_bst, int new_data); 
int insert_bst(struct bst* p_bst, int new_data); 
int insert_bst(struct bst* p_bst, int new_data); 
int insert_bst(struct bst* p_bst, int new_data); 

void inorder_traversal(struct bst* p_bst); 
void inorder_traversal(struct bst* p_bst); 
// inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inoder_traversal inorder_traversal inorder_traversal inorder_traversal 
// inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal 
// inorder travereal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inoder_traversal inorder_traversal inorder_traversal 
// inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal 
// inorder_traversal inorder_traversal inorder_traveral inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal inorder_traversal 
void inorder_traversal(struct bst* p_bst); 
void inorder_traversal(struct bst* p_bst); 
void inorder_traversal(struct bst* p_bst); 
void inorder_traversal(struct bst* p_bst); 
void inorder_traversal(struct bst* p_bst); 

void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 
void destroy_list(struct bst** pp_list); 

// helper functions 
void inorder(struct bst_node* p_node); 
void inorder(struct bst_node* p_node); 
void inorder(struct bst_node* p_node); 
void inorder(struct bst_node* p_node); 
void inorder(struct bst_node* p_node); 

void destroy(struct bst_node* p_node); 
void destroy(struct bst_node* p_node); 
void destroy(struct bst_node* p_node); 
void destroy(struct bst_node* p_node); 
void destroy(struct bst_node* p_node); 

// interface function definitions 
struct bst* create_bst(void) 
{
    struct bst* p_new_bst = NULL; 

    p_new_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(p_new_bst == NULL) 
    {
        fprintf(stderr, "create_bst():malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_bst->p_root_node = NULL; 
    p_new_bst->number_of_elements = 0; 

    return (p_new_bst); 
} 

struct bst* create_bst(void) 
{
    struct bst* p_new_bst = NULL; 

    p_new_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(NULL == p_new_bst) 
    {
        fprintf(stderr, "create_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_bst->p_root_node = NULL; 
    p_new_bst->number_of_elements = 0; 

    return (p_new_bst); 
} 

struct bst* create_bst(void) 
{
    struct bst* p_new_bst = NULL; 

    p_new_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(NULL == p_new_bst) 
    {
        fprintf(stderr, "create_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_bst->p_root_node = NULL; 
    p_new_bst->number_of_elements = 0; 

    return (p_new_bst); 
} 

struct bst* create_bst(void) 
{
    struct bst* p_new_bst = NULL; 

    p_new_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(NULL == p_new_bst) 
    {
        fprintf(stderr, "create_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_bst->p_root_node = NULL; 
    p_new_bst->number_of_elements = 0; 

    return (p_new_bst); 
} 

struct bst* create_bst(void) 
{
    struct bst* p_new_bst = NULL; 

    p_new_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(NULL == p_new_bst) 
    {
        fprintf(stderr, "create_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_bst->p_root_node = NULL; 
    p_new_bst->number_of_elements = 0; 

    return (p_new_bst); 
} 

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if bst is empty, if so insert new_node at root position and return 
    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    } 

    // insert into non-empty bst 
    struct bst_node* p_run = p_bst->p_root_node; 
    while(TRUE) 
    {
        if(p_new_node->data <= p_run->data) 
        {
            if(p_run->left == NULL) 
            {
                p_run->left = p_new_node; 
                p_run->left->parent = p_run; 
                break; 
            } 
            p_run = p_run->left; 
        }
        else 
        {
            if(p_run->right == NULL) 
            {
                p_run->right = p_new_node; 
                p_run->right->parent = p_run; 
                break; 
            } 
            p_run = p_run->right; 
        } 
    } 

    p_bst->number_of_elements += 1; 
    return (SUCCESS); 
} 

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if bst is empty, if so insert new node at root location and return 
    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    } 

    // insert into non-empty bst 
    struct bst_node* run = NULL; 
    while(TRUE) 
    {
        if(p_new_node->data <= run->data)
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

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if bst if empty, if so insert at root position and return  
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
        if(p_new_node->data <= run->data) 
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

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)alloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL; 
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if bst is empty, if so insert new_node at root position, and return 
    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    } 

    // insert into non-empty bst 
    struct bst_node* run = p_bst->p_root_node; 
    while(TRUE) 
    {
        if(p_new_node->data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = p_new_node; 
                run->left->parent = p_new_node; 
                break; 
            }
            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = p_new_node; 
                p_new_node->parent = run; 
                break; 
            } 
            run = run->right; 
        }
    } 

    p_bst->number_of_elements += 1; 
    return (SUCCESS); 
} 

int insert_bst(struct bst* p_bst, int new_data) 
{
    struct bst_node* p_new_node = NULL; 

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(NULL == p_new_node) 
    {
        fprintf(stderr, "insert_bst():malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p_new_node->data = new_data; 
    p_new_node->parent = NULL;
    p_new_node->left = NULL; 
    p_new_node->right = NULL; 

    // check if bst is empty insert at root position and return 
    if(p_bst->p_root_node == NULL) 
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->number_of_elements += 1; 
        return (SUCCESS); 
    }

    // insert into non-empty bst 
    struct bst_node* run = p_bst->p_root_node; 
    while(TRUE) 
    {
        if(p_new_node->data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = p_new_node; 
                p_new_node->parent = run->left; 
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

// traversal 
void inorder_traversal(struct bst* p_bst) 
{
    printf("{START}<->"); 
    inorder(p_bst->p_root_node); 
    printf("{END}\n"); 
} 

void inorder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    puts("[END]"); 
} 

void inorder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inoder(p_bst->p_root_node); 
    puts("[END]"); 
} 

void inorder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    puts("[END]"); 
} 

void inoder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    puts("[END]"); 
} 

void inorder_traversal(struct bst* p_bst) 
{ 
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    puts("[END]"); 
}

void inoder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inoder(p_bst->p_root_node); 
    puts("[END]"); 
} 

void inoder_traversal(struct bst* p_bst) 
{
    printf("[START]<->"); 
    inorder(p_bst->p_root_node); 
    puts("[END]"); 
} 

// destroy given instance of binary search tree 
int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    p_bst = NULL; 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    *pp_bst = NULL; 
    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    *pp_bst = NULL; 
    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    *pp_bst = NULL; 
    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 
    
    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

int destroy_bst(struct bst** pp_bst) 
{
    struct bst* p_bst = NULL; 

    p_bst = *pp_bst; 
    delete(p_bst->p_root_node); 
    free(p_bst); 

    *pp_bst = NULL; 
    return (SUCCESS); 
} 

// helper functions 
void inorder(struct bst_node* p_node) 
{
    // terminating condition 
    if(p_node == NULL) 
        return; 

    inoder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right); 
} 

void inorder(struct bst_node* p_node) 
{
    // terminating condition 
    if(p_node == NULL) 
        return; 
    
    inoder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right);
} 

void inorder(struct bst_node* p_node) 
{
    // terminating condition 
    if(p_node == NULL) 
        return; 

    inorder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right); 
} 

void inoder(struct bst_node* p_node) 
{
    // terminating condition 
    if(p_node == NULL) 
        return; 

    inorder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right); 
} 

void inorder(struct bst_node* p_node) 
{
    // terminating condition 
    if(p_node == NULL) 
        return; 

    inorder(p_node->left); 
    printf("[%d]<->", p_node->data); 
    inorder(p_node->right); 
} 

void destroy(struct bst_node* node) 
{
    if(node == NULL) 
        return; 

    if(node->left != NULL) 
        destroy(node->left); 
    if(node->right != NULL) 
        destroy(node->right); 
    
    free(node); 
    node = NULL; 
} 

void destroy(struct bst_node* node) 
{
    if(node == NULL) 
        return; 

    if(node->left != NULL) 
        delete(node->left); 
    if(node->right != NULL) 
        delete(node->right); 
    
    free(node); 
    node = NULL; 
} 

void destroy(struct bst_node* p_node) 
{
    if(p_node == NULL) 
        return; 

    if(p_node->left != NULL) 
        delete(p_node->left); 
    if(p_node->right != NULL) 
        delete(p_node->right); 

    free(p_node); 
    p_node = NULL; 
} 

void destroy(struct bst_node* p_node) 
{
    if(p_node == NULL) 
        return; 

    if(p_node->left != NULL) 
        delete(p_node->left); 
    if(p_node->right != NULL) 
        delete(p_node->right); 

    free(p_node); 
    p_node = NULL; 
} 

void destroy(struct bst_node* p_node) 
{
    if(p_node == NULL) 
        return; 

    if(p_node->left != NULL) 
        destroy(p_node->left); 
    if(p_node->right != NULL) 
        destroy(p_node->right); 

    free(p_node); 
    p_node = NULL; 
} 
