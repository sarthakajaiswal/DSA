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

// ============================ AUXILLIARY FUNCTION DEFINITIONS ======================== 
