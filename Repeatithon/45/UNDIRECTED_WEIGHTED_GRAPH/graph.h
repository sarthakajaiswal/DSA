#ifndef GRAPH_H 
#define GRAPH_H 

#include <stdio.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 

typedef int vertex_t; 
typedef int status_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hnode_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vnode_t* pv_head_node; 
    unsigned long nr_vertices; 
    unsigned long nr_edges; 
}; 

/* Graph interface functions */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper routines -> Vertical list management -> Vertical list interface */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// graph helper routines -> Vertical list managenemtn -> vertical list helpers 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Graph helper routines : Horizontal list managenemnt -> interface functions */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double weight); 

/* Graph helper routines : Vertical list management -> helper functions */ 
void h_generic_insert(hnode_t* pv_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex, double w); 

/* Graph helper routines -> general purpose */ 
void* xmalloc(size_t nr_bytes); 

#endif // GRAPH_H 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 

#define SUCCESS     1 
#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

typedef int vertex_t;  
typedef int status_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hnode_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vnode_t* pv_head_node; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

/* Graph interface functions */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* h, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper functions */ 
/* Vertical list management */ 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// helpers 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w);

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex, double w); 

/* General purpose helpers */ 
void* xmalloc(size_t size_in_bytes); 

#endif // _GRAPH_H 

// 3 
#ifndef _GRAPH_H 
#define _GRAPH_H 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

typedef int vertex_t; 
typedef int status_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode h_prev; 
    struct hnode h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hnode_t* ph_head_node; 
    struct vnode* v_next; 
    struct vnode* v_prev; 
}; 

struct graph 
{
    vnode_t* pv_head_node; 
    unsigned long nr_vertices; 
    unsigned long nr_edges; 
}; 

/* Graph interface functions */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper functions */ 
/* Vertical list management */ 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// helpers 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w); 

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex, double w); 

/* General purpose helpers */ 
void* xmalloc(size_t size_in_bytes); 

#endif // _GRAPH_H 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdio.h> 

#define TRUE    1  
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hnode_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vnode_t* pv_head_node; 
    unsigned long nr_vertices; 
    unsigned long nr_edges; 
}; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    hlist_t* ph_head_node; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

/* Graph Interface Routines */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g);  

/* Graph Helper Functions */ 
/* Vertical List management */ 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// helpers 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w); 

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex, double w); 

/* General Purpose Helpers */ 
void* xmalloc(size_t nr_bytes); 

/* Graph interface functions */
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper functions */ 
/* Vertical list management */ 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

// helpers 
void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node);
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex);  
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w); 

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex, double w); 

/* General Purpose helper functions */ 
void* xmalloc(size_t nr_bytes); 

#endif // _GRAPH_H 
#endif // _GRAPH_H 

