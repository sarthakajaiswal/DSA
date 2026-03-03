#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

enum status 
{
    SUCCESS = 1, 
    TRUE = 1, 
    FALSE = 0, 
    BST_EMPTY = 2, 
    BST_DATA_NOT_FOUND = 3, 
}; 

typedef int data_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst bst_t; 
typedef enum status status_t; 

struct bst 
{
    bst_node_t* root_node; 
    size_t nr_nodes; 
}; 

struct bst_node 
{
    data_t data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

bst_t* create_bst(void) 
{
    return ((bst_t*)xcalloc(1, sizeof(bst_t))); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* root_node); 

status_t remove_data(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* remove_node = NULL; 

    remove_node = search_bst_nodelevel(p_bst->root_node, r_data); 
    if(remove_node == NULL) 
    {
        fprintf(stderr, "remove data not found\n"); 
        return (BST_DATA_NOT_FOUND); 
    } 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = NULL; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 
    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->left; 
        else 
            remove_node->parent->right = remove_node->left; 

        remove_node->left->parent = remove_node->parent; 
    } 
    else 
    {
        bst_node_t* replace_node = NULL; 

        replace_node = get_min_nodelevel(remove_node->right); 

        if(replace_node != remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            replace_node->right->parent = replace_node->parent; 
        } 

        replace_node->left = remove_node->left; 
        replace_node->left->parent = remove_node; 

        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->right) 
            remove_node->parent->right = replace_node; 
        else 
            remove_node->parent->left = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 
    
    p_bst->nr_nodes -= 1; 
    return (SUCCESS); 
} 

status_t remove_data(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* remove_node = NULL; 

    remove_node = search_bst_nodelevel(r_data); 
    if(NULL == remove_node) 
        return (BST_DATA_NOT_FOUND); 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 
    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->left; 
        else 
            remove_node->parent->right = remove_node->right; 

        remove_node->left->parent = remove_node->parent; 
    } 
    else 
    {
        bst_node_t* replace_node = NULL; 

        replace_node = min_bst_nodelevel(remove_node->right); 
        
        if(replace_node != remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            remove_node->right->parent = replace_node; 
        }  

        replace_node->left = remove_node->left; 
        remove_node->left->parent = replace_node; 

        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = replace_node; 
        else 
            remove_node->parent->right = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 
    
    p_bst->nr_nodes -= 1; 
    return (SUCCESS); 
} 

status_t remove_data(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* remove_node = NULL; 

    remove_node = search_bst_nodelevel(p_bst, r_data); 
    if(NULL == remove_node) 
        return (BST_DATA_NOT_FOUND); 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL)
            p_bst->root_node = remove_node->right; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 

    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->left; 
        else 
            remove_node->parent->right = remove_node->left; 

        remove_node->left->parent = remove_node->parent; 
    } 

    else 
    {
        bst_node_t* replace_node = NULL; 

        replace_node = min_bst_nodelevel(remove_node->right); 

        if(replace_node == remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            remove_node->right->parent = replace_node; 
        } 

        replace_node->left = remove_node->left; 
        remove_node->left->parent = replace_node; 

        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = replace_node; 
        else 
            remove_node->parent->right = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 

    p_bst->nr_nodes -= 1; 
    return (SUCCESS); 
} 

status_t remove_data(bst_t* p_bst, data_t r_data) 
{
    // variable declarations 
    bst_node_t* remove_node = NULL; 

    // code 
    remove_node = bst_search_nodelevel(p_bst->root_node, r_data); 
    if(NULL == remove_node) 
        return (BST_DATA_NOT_FOUND); 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->right; 
        if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 

    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->left; 
        else 
            remove_node->parent->right = remove_node->left; 

        remove_node->left->parent = remove_node->parent; 
    } 

    else 
    {
        bst_node_t* replace_node = NULL; 
        replace_node = min_bst_nodelevel(remove_node->right); 

        if(replace_node != remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            remove_node->right->parent = replace_node; 
        } 

        replace_node->left = remove_node->left; 
        remove_node->left->parent = replace_node; 

        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = replace_node; 
        else 
            remove_node->parent->right = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 

    p_bst->nr_nodes -= 1; 
    return (SUCCESS); 
} 

status_t remove_data(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* remove_node = NULL; 

    remove_node = bst_search_nodelevel(p_bst->root_node); 
    if(NULL == remove_node) 
        return (BST_DATA_NOT_FOUND); 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->right; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 
    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->left; 
        else 
            remove_node->parent->right = remove_node->right; 

        remove_node->left->parent = remove_node->parent; 
    } 
    else 
    {
        bst_node_t* replace_node = NULL; 

        replace_node = bst_min_nodelevel(remove_node->right); 
    
        if(replace_node != remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            remove_node->right->parent = replace_node; 
        } 

        replace_node->left = remove_node->left; 
        replace_node->left->parent = replace_node; 

        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = replace_node; 
        else 
            remove_node->parent->right = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 

    p_bst->nr_nodes -= 1; 
    return (SUCCESS); 
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
    if(y != NULL && x == y->left) 
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
    if(z->left == NULL) 
        return (max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    if(y != NULL && x == y->parent) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    if(existing_node->left != NULL) 
        return (bst_max_nodelevel(existing_node)); 

    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 

    x = existing_node; 
    y = x->parent; 
    while(y != NULL && x == y->left) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    if(existing_node->left != NULL) 
        return (max_bst_nodelevel(existing_node->left)); 

    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 

    x = existing_node; 
    y = x->parent; 
    while(y != NULL && x == y->left) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    if(existing_node->left != NULL) 
        return (max_bst_nodelevel(existing_node->left)); 

    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 

    x = existing_node; 
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
    if(existing_node->left != NULL) 
        return (max_bst_nodelevel(existing_node->left)); 

    // find tree whose right subtree's min is existing node  
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 

    x = existing_node; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
}

