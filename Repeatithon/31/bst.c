/*  
    @GOAL:  BST repeatithon 
    @DATE:  14 January 2026 
    @Author: Sarthak A Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

enum status 
{
    SUCCESS = 1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = -1, 
    BST_DATA_NOT_FOUND = -2, 
    BST_NO_PREORDER_PREDEESSOR = -3, 
    BST_NO_PREORDER_SUCCESSOR = -4, 
    BST_NO_INORDER_PREDECESSOR = -5, 
    BST_NO_INORDER_SUCCESSOR = -6, 
    BST_NO_POSTORDER_PREDECESSOR = -7, 
    BST_NO_POSTORDER_SUCCESSOR = -8 
}; 

enum status 
{
    SUCCESS = 1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = -1, 
    BST_DATA_NOT_FOUND = -2, 
    BST_NO_PREORDER_PREDECESSOR = -3, 
    BST_NO_PREORDER_SUCCESSOR = -4, 
    BST_NO_INORDER_PREDECESSOR = -5, 
    BST_NO_INORDER_SUCCESSOR = -6, 
    BST_NO_POSTORDER_PREDECESSOR = -7, 
    BST_NO_POSTORDER_SUCCESSOR = -8 
}; 

enum status 
{
    SUCCESS =1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = -1, 
    BST_DATA_NOT_FOUND = -2, 
    BST_NO_PREORDER_PREDECESSOR = -3, 
    BST_NO_PREORDER_SUCCESSOR = -4, 
    BST_NO_INORDER_PREDECESSOR = -5, 
    BST_NO_INORDER_SUCCESSOR = -6, 
    BST_NO_POSTORDER_PREDECESSOR = -7, 
    BST_NO_POSTORDER_SUCCESSOR = -8 
}; 

enum status 
{
    SUCCESS = 1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = -1, 
    BST_DATA_NOT_FOUND = -2, 
    BST_NO_INORDER_PREDECESSOR = -3, 
    BST_NO_INORDER_SUCCESSOR = -4, 
    BST_NO_PREORDER_PREDECESSOR = -5, 
    BST_NO_PREORDER_SUCCESSOR = -6, 
    BST_NO_POSTORDER_PREDECESSOR = -7, 
    BST_NO_POSTORDER_SUCCESSOR = -8 
}; 

enum status 
{
    SUCCESS = 1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = -1, 
    BST_DATA_NOT_FOUND = -2, 
    BST_NO_PREORDER_PREDECESSOR = -3, 
    BST_NO_PREORDER_SUCCESSOR = -4, 
    BST_NO_INORDER_PREDECESSOR = -5, 
    BST_NO_INORDER_SUCCESSOR = -6, 
    BST_NO_POSTORDER_PREDECESSOR = -7, 
    BST_NO_POSTORDER_SUCCESSOR = -8 
}; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 

// ============= STRUCTURE LAYOUTS =================== 
struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
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
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

// ================ INTERFACE FUNCTION DECLARATIONS ============================= 
bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t search_bst(bst_t* p_bst, data_t search_data); 

void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t bst_min_data(bst_t* p_bst, data_t* p_min_data); 
status_t bst_max_data(bst_t* p_bst, data_t* p_max_data); 

void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t search_bst(bst_t* p_bst, data_t search_data); 

void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

void preorder_nrc(bst_t* p_bst);
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t search_bst(bst_t* p_bst, data_t search_data); 

void inorder(bst_t* p_bst); 
void preorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t preoder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preoder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t min_bst(bst_t* p_bst, data_t* p_min_data); 
status_t max_bst(bst_t* p_bst, data_t* p_max_data); 

void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t search_bst(bst_t* p_bst, data_t search_data); 

void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t search_bst(bst_t* p_bst, data_t search_data); 

void inorder(bst_t* p_bst); 
void preorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

// ==================== AUXILLIARY FUNCTIONS ============================================ 
void destroy_nodelevel(bst_node_t* root_node); 
bst_node_t* search_bst_nodelevel(bst_node_t* root_node, data_t search_data); 

void preoder_nodelevel(bst_node_t* root_node); 
void inorder_nodelevel(bst_node_t* root_node); 
void postorder_nodelevel(bst_node_t* root_node); 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node);

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* postorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node); 
bst_node_t* min_bst_nodelevel(bst_node_t* root_node); 

// =========================== INTERFACE FUNCTION DEFINITIONS ========================== 
bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

bst_t* create_bst(void) 
{
    // code 
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 
} 

bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = NULL; 
    p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    free(p_bst); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    run = p_bst->root_node; 
    while(TRUE) 
    {
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            } 
            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            } 
            run = run->right; 
        } 
    } 

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    run = p_bst->root_node; 
    while(TRUE) 
    {
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            } 
            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            } 
            run = run->right; 
        } 
    } 

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    run = p_bst->root_node; 
    while(TRUE) 
    {
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            } 

            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            } 
            run = run->right; 
        } 
    } 

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    run = p_bst->root_node; 
    while(TRUE) 
    {
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            } 

            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            } 

            run = run->right; 
        } 
    } 

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    run = p_bst->root_node; 
    while(TRUE) 
    {
        if(new_data <= run->data) 
        {
            if(run->left == NULL) 
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            } 

            run = run->left; 
        } 
        else 
        {
            if(run->right == NULL) 
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            } 

            run = run->right; 
        } 
    } 

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_bst_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_bst_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_bst_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_bst_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 
        
    p_pred_node = inorder_successor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL) 
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data;
    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 
    
    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 
        
    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_pred_node = NULL; 
    bst_node_t* p_existing_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL)
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(NULL == p_succ_node) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(NULL == p_succ_node) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t inorder_sucessor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_data = inorder_successor_nodelevel(p_existing_node); 
    if(NULL == p_succ_data) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(NULL == p_succ_node) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_succ_node = NULL;
    bst_node_t* p_existing_node = NULL; 

    p_existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(NULL == p_succ_node)     
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

// ===================== AUXILLIARY FUNCTIONS ================================
void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* p_root_node, data_t existing_data) 
{
    bst_node_t* run = NULL; 

    run = p_root_node; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break;  
        else if(existing_data < run->data) 
            run = run->left; 
        else 
            run = run->right; 
    } 

    return (run); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* p_root_node, data_t existing_data) 
{
    bst_node_t* run = NULL; 

    run = p_root_node; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
            break; 
        else if(existing_data < run->data) 
            run = run->left; 
        else 
            run = run->right; 
    } 

    return (run); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* p_root_node, data_t existing_data) 
{
    bst_node_t* p_run = NULL; 

    p_run = p_root_node; 
    while(p_run != NULL) 
    {
        if(existing_data == p_run->data) 
            break; 
        else if(existing_data < p_run->data) 
            p_run = p_run->left; 
        else 
            p_run = p_run->right; 
    } 

    return (p_run); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* p_root_node, data_t existing_data) 
{
    bst_node_t* run = NULL; 

    run = p_root_node; 
    while(run != NULL) 
    {
        if(existing_data == run->data) 
            break; 
        else if(existing_data < run->data) 
            run = run->left; 
        else 
            run = run->right; 
    } 

    return (run); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* p_root_node, data_t existing_data) 
{
    bst_node_t* run = NULL; 

    run = p_root_node; 
    while(run != NULL) 
    {
        if(existing_data == run->data) 
            break; 
        else if(existing_data < run->data) 
            run = run->left; 
        else 
            run = run->right; 
    } 

    return (run); 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
    } 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        preorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        preorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right);
        printf("[%d]->", root_node->data);  
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        peintf("[%d]->", root_node->data); 
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    } 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* p_existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = p_existing_node; 
    if(z->left != NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = y->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL;
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == NULL) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodelevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (min_bst_nodeevel(z->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL) 
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL) 
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL) 
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL) 
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL)  
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

// ============================= GENERAL PURPOSE FUNCTIONS - START ====================== 
bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    new_node->parent = NULL; 

    return (new_node); 
}

bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    new_node->parent = NULL; 

    return (new_node); 
} 

bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    new_node->parent = NULL; 

    return (new_node); 
} 

bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->parent = NULL; 
    new_node->left = NULL; 
    new_node->right = NULL; 

    return (new_node); 
} 

bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->parent = NULL; 
    new_node->left = NULL; 
    new_node->right = NULL; 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (ptr); 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    { 
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 
} 


