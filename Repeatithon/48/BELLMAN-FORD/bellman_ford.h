#ifndef _DIRECTED_GRAPH_H 
#define _DIRECTED_GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_VERTEX_EXISTS 4 
#define G_EDGE_EXISTS 5 
#define G_INCONSISTENT 6 
#define G_NEGATIVE_PATH_CYCLE 7 

#define LIST_EMPTY 8 
#define STACK_EMPTY LIST_EMPTY 

#define LIST_EMPTY 8 
#define STACK_EMPTY LIST_EMPTY 

#define LIST_EMPTY 8 
#define STACK_EMPTY LIST_EMPTY 

#define LIST_EMPTY 8 
#define STACK_EMPTY LIST_EMPTY 

#define LIST_EMPTY 8 
#define STACK_EMPTY LIST_EMPTY 

#define TRUE    1 
#define FALSE   0 
#define TRUE    1 
#define FALSE   0 
#define TRUE    1 
#define FALSE   0 
#define TRUE    1 
#define FALSE   0 
#define TRUE    1 
#define FALSE   0 

typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct edge_node edgenode_t; 
typedef edgenode_t edgelist_t; 
typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrnode_t vnodeptrstack_t; 
typedef struct graph graph_t; 

enum color 
{
    WHITE = 0, 
    GREY, 
    BLACK 
}; 

struct hnode {
    vertex_t v; 
    vnode_t* pv; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
};  

struct vnode
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv_node; 

    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

struct edge_node 
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* next; 
    struct edge_node* prev;  
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v_new); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list); 
void show_edge_list(edgelist_t* p_edge_list); 
status_t release_edge_list(edgelist_t** pp_list); 
status_t destroy_graph(graph_t** pp_g); 

status_t bellman_ford(graph_t* g, vertex_t s); 

// edge list management 
edgelist_t* e_create_list(void); 
status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w); 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end); 
edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

// vprt stack management routines 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_stack, vnode_t** pp_v); 
status_t vnptr_top_stack(vnodeptrstack_t* p_stack, vnode_t** pp_v); 
status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vptr_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack); 

// vnodeptr list management routines 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* pv); 
status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** ppv); 
status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** ppv); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t* pp_vnptr_list); 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_delete_node); 
vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr); 
vnodeptrnode_t* vnptr_get_node(vnodeptrnode_t* p_new_vnptr); 

// vertical list management 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_node(vertex_t v); 

// horizontal list management 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v, vnode_t* pv, double w); 
status_t h_destroy_list(hlist_t** pph_list); 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w); 

// auxilliary functions 
void* xmalloc(size_t size_in_bytes); 

#endif // _DIRECTED_GRAPH_H 

//////////////////////////// 

#ifndef _DIRECTED_GRAPH_H 
#define _DIRECTED_GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_VERTEX_EXISTS 4 
#define G_EDGE_EXISTS 5 
#define G_INCONSISTENT 6 
#define G_NEGATIVE_GRAPH_CYCLE 7 

typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t;  
typedef struct edgenode edgenode_t; 
typedef edgenode_t edgelist_t; 
typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef struct graph graph_t; 

enum color { WHITE = 0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    vnode_t* pv; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode_t* pred_node; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv_node; 

    struct vnodeptrnode* prev; 
    struct vnodeptrnode* next; 
}; 

struct edge_node 
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* prev; 
    struct edge_node* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

// Directed Graph 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
status_t get_edge_list(graph_t* g, edgelist_t** pp_list); 
void show_edge_list(edgelist_t* p_edge_list); 
status_t release_edge_list(edgelist_t** pp_list); 
status_t destroy_graph(graph_t** ppg); 

status_t bellman_ford(graph_t* g, vertex_t s); 

// edge list management functions 
edgelist_t* e_create_list(void); 
status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w); 
void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end); 
edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

// vptr stack management routines 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrnode_t* p_vnptr_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_T vnptr_destroy_stack(vnodeptrstackt_t** pp_vnptr_stack); 

// vnptr list management routines 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t* pp_vnptr_list); 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* delete_node); 
vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* search_vnptr); 
vnodeptrnode_t* vnptr_get_node(vnode_t* neW_vnptr); 

// vertical list management 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_v); 
status_t v_destroy_list(vlist_t** pp_list); 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* delete_node); 
vnode_t* v_get_node(vertex_t new_v); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 

// horizontal list 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v, vnode_t* pv, double w); 
status_t h_destroy_list(hlist_t** pph_list); 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t new_v, vnode_t* pv, double w); 

// general purpose auxialliary functions 
void* xmalloc(size_t size_in_bytes);  

#endif // _DIRECTED_GRAPH_H 

/////////////////////////////////////////////////////////////////////////////// 

#ifndef _DIRECTED_GRAPH_H 
#define _DIRECTED_GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_EDGE_EXISTS 4 
#define G_VERTEX_EXISTS 5  
#define G_INCONSISTENT 6 
#define G_NEGATIVE_PATH_CYCLE 7 

typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct edge_node edgenode_t; 
typedef edgenode_t edgelist_t; 
typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef struct graph graph_t; 

enum color { WHITE = 0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    vnode_t* pv; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct vnodeptr_node  
{
    vnode_t* pv; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

struct edge_node 
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* prev; 
    struct edge_node* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

/* Directed Graph Interface Functions */ 
graph_t* create_graph(void); 
status_t insert_vertex(graph_t* g, vertex_t new_v); 
status_t insert_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
status_t get_edge_list(graph_t* g, edgelist_t** pp_list); 
void show_edge_list(edgelist_t* p_edge_list); 
status_t release_edge_list(edgelist_t** pp_list); 
status_t destroy_graph(graph_t** pp_g); 

status_t bellman_ford(graph_t* g, vertex_t s); 

// edge list management routines 
edgelist_t* e_create_list(void); 
status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w); 
void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end); 
edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

// vnodeptr stack management routines 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_stack_push(vnodeptrstack_t* p_vnptr_stack, vnode_t** ppv); 
status_t vnptr_stack_pop(vnodeptrstack_t* p_vnptr_stak, vnodde_t** ppv); ]
status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack); 

// vnptr list management routines 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* pv); 
status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list); 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_delete_node); 
vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr); 
vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr); 

// vlist management functions 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_node(vertex_t v); 

// horizontal list management 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v, vnode_t* pv_list, double w); 
status_t h_destroy_list(hlist_t** ph_list); 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w); 

// general purpose auxilliary 
void* xmalloc(size_t size_in_bytes); 

#endif // _DIRECTED_GRAPH_H 

//////////////////////////////////////////////////////// 

#ifndef _DIRECTED_GRAPH_H 
#define _DIRECTED_GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_VERTEX_EXISTS 4 
#define G_EDGE_EXISTS 5 
#define G_INCONSISTENT 6 
#define G_NEGATIVE_PATH_CYCLE 7 

typedef int vertex_t; 
typedef int status_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct edge_node edgenode_t; 
typedef edgenode_t edgelist_t; 
typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef enum color color_t;  
typedef struct graph graph_t; 

enum color { WHITE = 0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    vlist_t* pv; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

struct edge_node 
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* prev; 
    struct edge_node* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_edges; 
    unsigned int nr_vertices; 
}; 

/* Graph Interface Routines */ 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v_new); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
edgelist_t* create_edge_list(edgelist_t* p_edge_list); 
status_t show_edge_list(edgelist_t* p_edge_list); 
status_t release_edge_list(edgelist_t** pp_list); 
status_t destroy_graph(graph_t** ppg); 

status_t bellman_ford(graph_t* g, vertex_t s); 

/* Graph Auxilliary Data Structures */  
edgelist_t* e_create_list(void); 
status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w); 
void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end); 
edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

// vnode ptr stack management routines 
vptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack); 

// vnodeptr list management functions 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list); 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* delete_node); 
vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* search_vnptr); 
vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr); 

// vlist management functions 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v_new); 
status_t v_destroy_list(vlist_t* pp_vlist); 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* delete_node); 
vnode_t* v_search_node(vnode_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_node(vertex_t v_new); 

// hlist management functions 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new); 
status_t h_destroy_list(hlist_t** pp_hlist); 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w); 

// auxilliary functions 
void* xmalloc(size_t size_in_bytes); 

#endif // _DIRECTED_GRAPH_H 

#ifndef _DIRECTED_GRAPH_H 
#define _DIRECTED_GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 
#define G_INVALID_VERTEX 2 
#define G_INVALID_EDGE 3 
#define G_VERTEX_EXISTS 4 
#define G_EDGE_EXISTS 5 
#define G_INCONSISTENT 6 
#define G_NEGATIVE_PATH_CYCLE 7 

typedef int vertex_t; 
typedef int status_t; 
typedef enum color color_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct edge_node edgenode_t; 
typedef edgenode_t edgelist_t; 
typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef struct graph graph_t; 

enum color { WHITE = 0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    vnode_t* pv; 
    double w; 

    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

struct edge_node 
{
    vnode_t* pv_start; 
    vnode_t* pv_end; 
    double w; 

    struct edge_node* prev; 
    struct edge_node* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

/* Directed Graph -> Interface Routines */ 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
status_t get_edge_list(graph_t* g, edgelist_t** pp_list); 
void show_edge_list(edgelist_t* p_edgelist); 
status_t release_edge_list(edgelist_t** pp_edgelist); 
status_t destroy_graph(graph_t** pp_g); 

status_t bellman_ford(graph_t* g, vertex_t s); 

/* Directed Graph -> Helper Routines */ 
// edge list management functions 
// interface 
edgelist_t* e_create_list(void); 
status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w);
// helpers 
void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end); 
edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w); 

/* Directed Graph -> Auxilliary Data Structures */ 
// vnodeptr stack 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack); 

// vnodeptr list 
// interface 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr)
status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list); 
// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* delete_node); 
vnodeptrnode_t* vnptr_search_node(vnptrnodelist_t* p_vnptr_list, vnode_t* s_vnptr); 
vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr); 

// vertical list 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 
// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_node(vertex_t v); 

// horizontal list 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w); 
status_t h_destroy_list(hlist_t** pp_hlist); 
// helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t v_new, vnode_t* pv, double w); 

/* General Purpose Helpers */ 
void* xmalloc(size_t size_in_bytes); 

#endif // _DIRECTED_GRAPH_H 
