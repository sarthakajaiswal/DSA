#pragma once 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 
#define QUEUE_EMPTY         -5 

typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 
typedef struct queue_node queue_node_t; 

enum color {WHITE = 0, GREY, BLACK}; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    color_t color; 
    vnode_t* v_next; 
    vnode_t* v_prev; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    unsigned long nr_edges; 
    unsigned long nr_vertices; 
}; 

struct queue_node 
{
    vnode_t* pv_node; 
    struct queue_node* q_prev; 
    struct queue_node* q_next; 
}; 

/* Graph interface routines */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void dfs(graph_t* g); 
void bfs(graph_t* g, vertex_t v); 

void show_graph(graph_t* g, const char* msg); 

status_t destroy_graph(graph_t** pp_g); 

/* Geaph helper routines */ 
void reset(graph_t* g); 
void dfs_visit(graph_t* g, vnode_t* pv); 

/* Queue management routines */ 
queue_node_t* create_queue(void); 
status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node); 
status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node); 
int is_queue_empty(queue_node_t* p_queue); 
status_t destroy_queue(queue_node_t* p_queue); 

void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end); 
void q_generic_delete(queue_node_t* p_delete_node); 
queue_node_t* q_get_node(vnode_t* pv_node); 

/* Vertical List management */ 
/* Vertical list interface functions */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* Vertical list helper functions */
void v_generic_insert(vnode_t* p_beg, vnode_t* p_mid, vnode_t* p_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_get_list_node(vertex_t new_vertex); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 

/* Horizontal list management */ 
/* Horizontal list interface functions */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* Horizontal list helper functions */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* General purpose helper routines */ 
void* xmalloc(size_t nr_bytes); 

// // =============================================================================== 
// #pragma once 

// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h> 

// #define TRUE    1 
// #define FALSE   0 
// #define SUCCESS 1 

// #define G_VERTEX_EXISTS     -1 
// #define G_INVALID_VERTEX    -2 
// #define G_EDGE_EXISTS       -3 
// #define G_INVALID_EDGE      -4 

// typedef int vertex_t; 
// typedef int status_t; 
// typedef enum color color_t; 
// typedef struct hnode hnode_t; 
// typedef hnode_t hlist_t; 
// typedef struct vnode vnode_t; 
// typedef vnode_t vlist_t; 
// typedef struct graph graph_t; 

// enum color { WHITE = 0, GREY, BLACK }; 

// struct hnode 
// {
//     vertex_t v; 
//     struct hnode* h_prev; 
//     struct hnode* h_next; 
// }; 

// struct vnode 
// {
//     vertex_t v; 
//     hlist_t* ph_head_node; 
//     color_t color; 
//     struct vnode* v_prev; 
//     struct vnode* v_next; 
// }; 

// struct graph 
// {
//     vlist_t* pv_head_node; 
//     unsigned long nr_edges; 
//     unsigned long nr_vertices; 
// }; 

// struct queue_node 
// {
//     vnode_t* pv_node; 
//     struct queue_node* q_next; 
//     struct queue_node* q_prev; 
// }; 

// /* Graph interface funtions */ 
// // creation 
// graph_t* create_graph(void); 

// // addition and removal 
// status_t add_vertex(graph_t* g, vertex_t new_vertex); 
// status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
// status_t add_edge(graph_t* g, vertex_t start_vertex, vertex_t end_vertex); 
// status_t remove_edge(graph_t* g, vertex_t start_vertex, vertex_t end_vertex); 

// // traversal 
// void dfs(graph_t* g); 
// void bfs(graph_t* g, vertex_t v_start); 

// // show 
// void show_graph(graph_t* g, const char* msg); 

// // deletion 
// status_t destroy_graph(graph_t** pp_g); 

// /* Graph helper functions */ 
// void reset(graph_t* g); 
// void dfs_visit(graph_t* g, vnode_t* v); 

// /* Queue management functions */ 
// /* Queue interface functions */ 
// queue_node_t* create_queue(void); 
// status_t enqueue(queue_node_t* p_queue, vnode_t* new_pv_node); 
// status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node); 
// status_t is_queue_empty(queue_node_t* p_queue); 

// /* Queue helper functions */ 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end); 
// void q_generic_delete(queue_node_t* p_delete_node); 
// queue_node_t* q_get_node(vnode_t* new_pv_node); 

// /* Vertical list management functions */ 
// /* Vertical list interface functions */ 
// vlist_t* v_create_list(void); 
// status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// /* Vertical list helper functions */ 
// void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
// void v_generic_delete(vnode_t* pv_delete_node); 
// vnode_t* v_get_list_node(vertex_t new_vertex); 
// vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 

// /* Horizontal list management functions */ 
// /* Horizontal list interface functions */ 
// hlist_t* h_create_list(void); 
// status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

// /* Horizontal list helper functions */ 
// void h_generic_insert(hnode_t* ph_node, hnode_t* ph_mid, hnode_t* ph_end); 
// void h_generic_delete(hnode_t* ph_delete_node); 
// hnode_t* h_get_list_node(vertex_t new_vertex); 
// hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 

// /* Genral purpose helper functions */ 
// void* xmalloc(size_t nr_bytes); 

// // =============================================================================== 
// #pragma once 

// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h> 

// #define SUCCESS 1 
// #define TRUE    1 
// #define FALSE   0 

// #define G_VERTEX_EXISTS     -1 
// #define G_INVALID_VERTEX    -2 
// #define G_EDGE_EXISTS       -3 
// #define G_INVALID_EDGE      -4 
// #define QUEUE_EMPTY         -5 

// enum color { WHITE = 0, GREY, BLACK }; 

// typedef int     vertex_t; 
// typedef int     status_t; 
// typedef enum color      color_t; 
// typedef struct hnode    hnode_t; 
// typedef hnode_t         hlist_t; 
// typedef struct vnode    vnode_t;
// typedef vnode_t         vlist_t; 
// typedef struct graph    graph_t; 

// // node layout definitions 
// struct hnode 
// {
//     vertex_t v; 
//     struct hnode* ph_prev; 
//     struct hnode* ph_next; 
// }; 

// struct vnode 
// {
//     vertex_t v; 
//     hlist_t* ph_head_node; 
//     color_t color; 
//     struct vnode* v_next; 
//     struct vnode* v_prev; 
// }; 

// struct graph 
// {
//     vlist_t* pv_head_node; 
//     unsigned long nr_vertices; 
//     unsigned long nr_edges; 
// }; 

// /* Graph interface funtions */ 
// // creation 
// graph_t* create_graph(void); 

// // insertion and removal 
// status_t add_vertex(graph_t* g, vertex_t new_vertex); 
// status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
// status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
// status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// // traversal 
// void bfs(graph_t* g, vertex_t v_start); 
// void dfs(graph_t* g); 

// // show 
// void show_graph(graph_t* g, const char* msg); 

// // deletion 
// status_t destroy_graph(graph_t** pp_g); 

// /* Graph helper routines */ 
// void reset(graph_t* g); 
// void dfs_visit(graph_t* g, vnode_t* v); 

// /* Queue management*/ 
// /* Queue interface functions */ 
// queue_node_t* create_queue(void); 
// status_t enqueue(queue_node_t* p_queue, vnode_t* new_pv_node); 
// status_t dequeue(queue_node_t* p_queue, vnode_t** pp_v_node); 
// status_t is_queue_empty(queue_node_t* p_queue); 

// /* Queue helper functions */ 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end); 
// void q_generic_delete(queue_node_t* p_delete_node); 
// queue_node_t* q_get_node(vnode_t* new_pv_node); 

// /* Vertical List Management */ 
// /* Vertical list interface functions */ 
// vlist_t* v_create_list(void); 
// status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// /* Vertical list helper functions */ 
// void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
// void v_generic_delete(vnode_t* pv_delete_node); 
// vnode_t* v_get_list_node(vertex_t new_vertex); 
// vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 

// /* Horizontal list management */ 
// /* Horizontal list interface functions */ 
// hlist_t* h_create_list(void); 
// status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

// /* Horizontal list helper functions */ 
// void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
// void h_generic_delete(hnode_t* ph_delete_node); 
// hnode_t* h_get_list_node(vertex_t new_vertex); 
// hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 

// /* General purpose helper functions */ 
// void* xmalloc(size_t nr_bytes); 

// // =============================================================================== 
// #pragma once 

// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h> 

// #define TRUE    1 
// #define FALSE   0 
// #define SUCCESS 1 

// #define G_VERTEX_EXISTS     -1 
// #define G_INVALID_VERTEX    -2 
// #define G_EDGE_EXISTS       -3 
// #define G_INVALID_EDGE      -4  
// #define QUEUE_EMPTY         -5 

// typedef int status_t; 
// typedef int vertex_t; 
// typedef enum color      color_t; 
// typedef struct hnode    hnode_t; 
// typedef hnode_t         hlist_t; 
// typedef struct vnode    vnode_t; 
// typedef vnode_t         vlist_t; 
// typedef struct graph    graph_t; 

// enum color { WHITE = 0, GREY, BLACK }; 

// // node layout definitions 
// struct hnode 
// {
//     vertex_t v; 
//     struct hnode* h_next; 
//     struct hnode* h_prev; 
// }; 

// struct vnode 
// {
//     vertex_t v; 
//     hlist_t* ph_head_node; 
//     color_t color; 
//     struct vnode* v_prev; 
//     struct vnode* v_next; 
// }; 

// struct graph 
// {
//     vlist_t* pv_head_node; 
//     unsigned long nr_vertices; 
//     unsigned long nr_edges; 
// }; 

// /* Graph interface functions */ 
// // creation 
// graph_t* create_graph(void); 

// // addition and removal 
// status_t add_vertex(graph_t* g, vertex_t new_vertex); 
// status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
// status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
// status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// // traversals 
// void dfs(graph_t* g); 
// void bfs(graph_t* g, vertex_t v_start); 

// // show 
// void show_graph(graph_t* g, const char* msg); 

// // destroy 
// status_t destroy_graph(graph_t** pp_g); 

// /* Graph helper functions */ 
// void reset(graph_t* g); 
// void dfs_visit(graph_t* g, vnode_t* pv_start); 

// /* Queue management */ 
// // queue interface functions 
// queue_node_t* create_queue(void); 
// status_t enqueue(queue_node_t* p_queue, vnode_t* new_pv_node); 
// status_t dequeue(queue_node_t* p_queue, vnode_t** pp_v_node); 
// status_t is_queue_empty(queue_node_t* p_queue); 

// // queue helper functions 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end); 
// void q_generic_delete(queue_node_t* p_delete_node); 
// queue_node_t* q_get_node(vnode_t* new_pv_node); 

// /* Vertical list management */ 
// // vertical list interface functions 
// vlist_t* v_create_list(void); 
// status_t v_insert_end(vlist_t* p_list, vertex_t new_vertex); 

// // vertical list helper functions 
// void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
// void v_generic_delete(vnode_t* pv_delete_node); 
// vnode_t* v_get_list_node(vertex_t new_vertex); 
// vnode_t* v_search_node(vlist_t* pv_list, vertex_t new_vertex); 

// /* Horizontal list management */ 
// // horizontal list interface functions 
// hlist_t* h_create_list(void); 
// status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

// // horizontal list helper functions 
// void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
// void h_generic_delete(hnode_t* ph_delete_node); 
// hnode_t* h_get_list_node(vertex_t new_vertex); 
// hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 

// /* General purpose helper functions */ 
// void* xmalloc(size_t size_in_bytes); 

// // =============================================================================== 
// #pragma once 

// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h> 

// #define TRUE    1 
// #define FALSE   0 
// #define SUCCESS 1 

// #define G_INVALID_VERTEX    -1 
// #define G_VERTEX_EXISTS     -2 
// #define G_INVALID_EDGE      -3 
// #define G_EDGE_EXISTS       -4 

// typedef int vertex_t; 
// typedef int status_t; 
// typedef enum color color_t; 
// typedef struct hnode hnode_t; 
// typedef hnode_t hlist_t; 
// typedef struct vnode vnode_t; 
// typedef vnode_t vlist_t; 
// typedef struct graph graph_t; 
// typedef struct queue_node queue_node_t; 

// enum color {WHITE = 0, GREY, BLACK}; 

// struct hnode 
// {
//     vertex_t v; 
//     struct hnode* h_prev; 
//     struct hnode* h_next; 
// }; 

// struct vnode 
// {
//     vertex_t v; 
//     hlist_t* ph_head_node; 
//     color_t color; 
//     struct vnode* v_next; 
//     struct vnode* v_prev; 
// }; 

// struct graph 
// {
//     vlist_t* pv_head_node; 
//     unsigned long nr_vertices; 
//     unsigned long nr_edges; 
// }; 

// /* Graph interface functions */ 
// // creation 
// graph_t* create_graph(void); 

// // addition and deletion 
// status_t add_vertex(graph_t* g, vertex_t new_vertex); 
// status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
// status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
// status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// // traversal 
// void dfs(graph_t* g); 
// void bfs(graph_t* g, vertex_t v); 

// // show 
// void show_graph(graph_t* g, const char* msg); 

// // destructions 
// status_t destroy_graph(graph_t** pp_g); 

// /* Graph helper routines */ 

// /* Queue management functions */ 
// /* Queue interface functions */ 
// queue_node_t* create_queue(void); 
// status_t enqueue(queue_node_t* p_queue, vnode_t* new_pv_node); 
// status_t dequeue(queue_node_t* p_queue, vnode_t** pp_node); 
// int is_queue_empty(queue_node_t* p_queue); 
// status_t destroy_queue(queue_node_t* p_queue); 

// /* Queue helper functions */ 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end); 
// void q_generic_delete(queue_node_t* p_delete_node); 
// queue_node_t* q_get_node(vnode_t* pv_node); 

// /* Vertical list management functions */ 
// /* Vertical list interface functions */ 
// vlist_t* v_create_list(void); 
// status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// /* Vertical list helper functions */ 
// void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
// void v_generic_delete(vnode_t* pv_delete_node); 
// vnode_t* v_get_list_node(vertex_t new_vertex); 
// vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 

// /* Horizontal list management functions */ 
// /* Horizontal list interface functions */ 
// hlist_t* h_create_list(void); 
// status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

// /* Horizontal list helper functions */ 
// void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
// void h_generic_delete(hnode_t* ph_delete_node); 
// hnode_t* h_get_list_node(vertex_t new_vertex); 
// hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 

// /* General purpose Graph helper routines */ 
// void* xmalloc(size_t nr_bytes); 
