/*
    @GOAL:      BST implementation 
    @DATE:      14 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

// ==================== HEADER FILES START ==================================== 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
// ==================== HEADER FILES END ====================================== 

// ==================== SYMBOLIC CONSTANTS START ============================== 
enum status 
{
    SUCCESS                         = 1, 
    TRUE                            = 1, 
    FALSE                           = 0, 
    BST_EMPTY                       = -1, 
    BST_NO_INORDER_PREDECESSOR      = -2, 
    BST_NO_INORDER_SUCCESSOR        = -3, 
    BST_NO_PREORDER_PREDECESSOR     = -4, 
    BST_NO_PREORDER_SUCCESSOR       = -5, 
    BST_NO_POSTORDER_PREDECESSOR    = -6, 
    BST_NO_POSTORDER_SUCCESSOR      = -7 
}; 
// ==================== SYMBOLIC CONSTANTS END ================================ 

// ====================== TYPEDEFS START ====================================== 
typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 
// ======================== TYPEDEFS END ====================================== 

// ================== INFORMATION STRUCTURE DEFINITIONS - START ===============
// definition of node of bst 
struct bst_node 
{
    data_t data; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

// definition of instance of bst 
struct bst 
{
    bst_node_t* root_node; 
    size_t nr_elements; 
}; 

// ============== INFORMATION STRUCTURE DEFINITIONS - END ===================== 

// ================= INTERFACE FUNCTIONS - START ============================== 
// create and destroy data structure instance 
bst_t* create_bst(void); 
status_t destroy_list(bst_t** pp_bst); 

// insert new data into bst 
status_t insert_bst(bst_t* p_bst, int new_data); 

// search data in bst 
status_t search_bst(bst_t* p_bst, data_t search_data); 

// remove data from bst 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

// BST traversals - recursive 
void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

// inorder predecessor and successor 
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_scuccessor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

// pre-order predecessor and successor 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t exiting_data, data_t* p_succ_data); 

// post-order predecessor and successor 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

// minimum and maximum 
status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

// BST traversals recursive 
void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

// =================== INTERFACE FUNCTIONS - END ============================== 

// ==================== AUXILLIARY FUNCTIONS - START ========================== 
void destroy_nodelevel(bst_node_t* root_node); 

void preorder_nodelevel(bst_node_t* root_node); 
void postorder_nodelevel(bst_node_t* root_node); 
void inorder_nodelevel(bst_node_t* root_node); 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* postorder_successor_nodelevel(bst_node_t* existing_node); 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node); 
bst_node_t* min_bst_nodelevel(bst_node_t* root_node); 

// ==================== AUXILLIARY FUNCTIONS - END ============================ 

// ==================== GENERAL PURPOSE FUNCTIONS - START ===================== 
bst_node_t* get_bst_node(data_t new_data); 
void* xmalloc(size_t size); 
// ==================== GENERAL PURPOSE FUNCTIONS - END ======================= 

// ==================== CLIENT SIDE - START =================================== 
int main(void) 
{
    return (EXIT_SUCCESS); 
} 
// ==================== CLIENT SIDE - END ===================================== 

// =============== INTERFACE FUNCTION DEFINITIONS - START =====================
bst_t* create_bst(void) 
{
    bst_t* new_bst = NULL; 

    new_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    new_bst->root_node = NULL; 
    new_bst->nr_elements = 0; 

    return (new_bst); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{} 

// insert new data into bst 
status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    if(p_bst->root_node == NULL) 
    {
        /* CASE I: Empty BST */ 
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    } 

    /* CASE II: Non-empty BST */ 
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

// search data in BST 
status_t search_bts(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = p_bst->root_node; 
    while(run != NULL) 
    {
        if(run->data == search_data) 
            return (TRUE); 
        else if(search_data < run->data) 
            run = run->left; 
        else 
            run = run->right; 
    } 

    return (FALSE); 
} 

// =============== INTERFACE FUNCTIONS DEFINITIONS - END ====================== 

// ================== AUXILLIARY FUNCTIONS DEFINITIONS - START ================ 
// =============== AUXILLIARY FUNCTIONS DEFINITIONS - END ===================== 

// ================= GENERAL FUNCTIONS DEFINITIONS - START ==================== 
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

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        fprintf(stderr, "malloc():fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (ptr); 
} 
// ================= GENERAL FUNCTIONS DEFINITIONS - END ====================== 

