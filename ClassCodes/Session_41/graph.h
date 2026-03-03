#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     2 
#define G_INVALID_VERTEX    3 
#define G_EDGE_EXIST        4 
#define G_INVALID_EDGE      5 

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
    struct hnode* h_prev; 
    struct hnode* h_next; 
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

/* Graph interface routines */ 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

/* graph helper routines: Vertical list management-> Vertical list interface */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* Graph helper routines -> Vertical list management-> Vertical list helper */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* p_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Graph helper routines-> Horizontal list management -> Horizontal list interface */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* Graph helper routines -> Horizontal list management => horizontal list helper */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* Graph helper routines -> general purpose */ 
void* xmalloc(size_t nr_bytes); 

#endif // _GRAPH_H 

