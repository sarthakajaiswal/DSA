/*
    @GOAL:      BST implementation 
    @DATE:      14 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

// ===================== HEADER FILES - START ========================== 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
// ===================== HEADER FILES - END ============================ 

// ===================== SYMBOLIC CONSTANTS - START ==================== 
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
// ===================== SYMBOLIC CONSTANTS - END ======================= 

// ====================== TYPEDEF'S START =============================== 
typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t; 
// ========================= TYPEDEF's END ============================== 

// ===================== INFORMATION STRUCTURE DEFINITIONS - START ====== 
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
    struct bst_node_t* root_node; 
    size_t nr_elements; 
}; 

// =================== INTERFACE FUNCTION DECLARATIONS - START ========== 
// create and destroy data structure instance 
bst_t* create_bst(void); 
status_t destroy_bst(bst_t** pp_bst); 

// insert new data into BST 
status_t insert_bst(bst_t* p_bst, data_t new_data); 

// search data into bst 
status_t search_bst(bst_t* p_bst, data_t search_data); 

// remove data from BST 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

// BST traversals - recursive 
void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst);
void postorder(bst_t* p_bst);

// inorder predecessor and successor 
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

// preorder predecessor and successor 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

// postorder predecessor and successor 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

// maximum and minimum 
status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

// BST traversals non-recursive 
void preorder_nrc(bst_t* p_bst); 
void inorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 
// ======================== INTERFACE FUNCTION DECLARATIONS - END ============================== 

// ======================= AUXILLIARY FUNCTIONS - START ======================================== 
void destroy_nodelevel(bst_node_t* root_node); 

void preorder_nodelevel(bst_node_t* root_node); 
void inorder_nodelevel(bst_node_t* root_node); 
void postorder_nodelevel(bst_node_t* root_node); 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* root_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* root_node); 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* root_node); 
bst_node_t* preorder_successor_nodelevel(bst_node_t* root_node); 

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* root_node); 
bst_node_t* postorder_successor_nodelevel(bst_node_t* root_node); 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node); 
bst_node_t* min_bst_nodelevel(bst_node_t* root_node); 
// ======================== AUXILLIARY FUNCTIONS - END ========================================= 

// ========================= GENERAL PURPOSE FUNCTION DECLARATIONS - START ========================== 
bst_node_t* get_bst_node(data_t new_data); 
void* xmalloc(size_t size); 
// ========================= GENERAL PURPOSE FUNCTION DECLARATIONS - END ============================ 

// ====================== CLIENT SIDE ========================================================== 
void test_bst_normal(void); 
void test_bst_extreme(void); 

int main(void) 
{
    test_bst_normal(); 

    #ifndef EXTREME_TESTING_ON 
    test_bst_extreme(); 
    #endif // EXTREME_TESTING_ON

    return (EXIT_SUCCESS); 
} 

void test_bst_normal(void) 
{
    bst_t* p_bst = NULL; 
    status_t status = SUCCESS; 
    data_t data[] = {100, 50, 150, 75, 125, 200, 65, 130}; 
    data_t nonexistent_data[] = {-200, 34, 68, 98, 0xaabb, 0xf0f0f0f0};  

    size_t index; 

    p_bst = create_bst(); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = insert_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("insert_bst() for [%d] is succesful\n", data[index]); 
    } 

    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = search_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("Search data [%d] is successfull\n", data[index]); 
    } 

    for(index = 0; index < sizeof(nonexistent_data)/sizeof(nonexistent_data[0]); ++index) 
    {
        status = search_bst(p_bst, nonexistent_data[index]); 
        assert(status == FALSE); 
        printf("search for [%d] is not succesfull\n", nonexistent_data[index]); 
    } 

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    puts("Binary search tree destroyed successfully\n"); 
    puts("Normal testing completed succesfully\n"); 
} 

void test_bst_extreme(void) 
{
    bst_t* p_bst = NULL; 
    data_t* p_data_array = NULL; 
    size_t N = 100; 
    status_t status; 
    data_t nonexistent_data[] = {-100, -200, 32768, 100000, 12345678}; 

    /* Allocate memory to hold N random integers */ 
    p_data_array = (data_t*)xmalloc(N * sizeof(data_t)); 

    /* set the seed of random number generator */ 
    srand(time(0)); 

    /* populate the array */ 
    for(size_t index = 0; index < N; ++index) 
    {
        p_data_array[index] = rand(); 
    } 

    // allocate the bst_instance 
    p_bst = create_bst(); 

    for(size_t index = 0; index < N; ++index) 
    {
        status = insert_bst(p_bst, p_data_array[index]); 
        assert(status == SUCCESS); 
        printf("insert_bst(): succcessfull for [%d]\n", p_data_array[index]); 
    } 

    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    for(size_t index = 0; index < N; ++index) 
    {
        status = search_bst(p_bst, p_data_array[index]); 
        assert(status == SUCCESS); 
        printf("Search for [%d] is successfull\n", p_data_array[index]); 
    } 

    for(size_t index = 0; index < sizeof(nonexistent_data)/sizeof(nonexistent_data[0]); ++index) 
    {
        status = search_bst(p_bst, nonexistent_data[index]); 
        assert(status == FALSE); 
        printf("Search for [%d] is not succesfull\n", nonexistent_data[index]); 
    } 

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    free(p_data_array); 
    p_data_array = NULL; 

    puts("Binary Search tree destroyed Successfully\n"); 
    puts("Extreme testing completed succesfully. Returning"); 
} 
// ============================== CLIENT SIDE - END ============================================ 

// ============================= INTERFACE FUNCTIONS - START =================================== 
// create and destroy data structure instance 
bst_t* create_bst(void) 
{
    bst_t* new_bst = NULL; 

    new_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    new_bst->root_node = NULL; 
    new_bst->nr_elements = 0; 

    return (new_bst); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    *pp_bst = NULL; 

    return (SUCCESS); 
} 

// Insert new data into BST 
status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* new_node = NULL; 
    bst_node_t* run = NULL; 

    new_node = get_bst_node(new_data); 

    // case 1 empty BST 
    if(p_bst->root_node == NULL)    
    {
        p_bst->root_node = new_node; 
        p_bst->nr_elements = 1; 
        return (SUCCESS);  
    } 

    // case 2: Non empty BST 
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
status_t search_bst(bst_t* p_bst, data_t search_data) 
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

// remove data from bst 
status_t remove_bst(bst_t* p_bst, data_t r_data) 
{
    return (SUCCESS); 
} 

// BST traversals recursive 
void preorder(bst_t* p_bst) 
{
    printf("PREORDER: [START]->"); 
    preorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

void inorder(bst_t* p_bst) 
{
    printf("INORDER: [START]->"); 
    inorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

void postorder(bst_t* p_bst) 
{
    printf("POSTORDER: [START]->"); 
    postorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

// inorder predecessor and successor 
status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{

} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{

} 

// preorder predecessor and successor 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{

} 

status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{

} 

// postorder predecessor and successor 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{

} 

status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{

} 

// minimum and maximum 
status_t max_bst(bst_t* p_bst, data_t* p_max_data) 
{

} 

status_t min_bst(bst_t* p_bst, data_t* p_min_data) 
{

} 

// BST traversals non-recursive 
void inorder_nrc(bst_t* p_bst) 
{

} 

void preorder_nrc(bst_t* p_bst)  
{

} 

void postorder_nrc(bst_t* p_bst) 
{

} 
// ============================= INTERFACE FUNCTION DEFINITIONS - END ==================================== 

// ============================== AUXILLIARY FUNCTION DEFINITIONS - START ================================ 
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

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* postorder_successot_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* bst_max_nodelevel(bst_node_t* root_node) 
{

} 

bst_node_t* bst_min_nodelevel(bst_node_t* root_node) 
{
    
} 

// =============================== AUXILLIARY FUNCTION DEFINITIONS - END ================================= 

// ================================= GENERAL PURPOSE FUNCTION DEFINITIONS - START ========================= 
bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = xmalloc(new_data); 
    new_node->data = new_data; 
    new_node->parent = NULL; 
    new_node->left = NULL; 
    new_node->right = NULL; 

    return (new_node); 
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
// ================================== GENERAL PURPOSE FUNCTION DEFINITIONS - END ========================== 
