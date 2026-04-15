#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 

/* Symbolic Constants */ 
#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

#define HLIST_DATA_NOT_FOUND 2 
#define VLIST_DATA_NOT_FOUND HLIST_DATA_NOT_FOUND 

#define G_VERTEX_EXISTS 3 
#define G_EDGE_EXISTS   4 
#define G_INVALID_VERTEX    5 
#define G_INVALID_EDGE      6 

#define V_LIST_EMPTY    7 
#define V_QUEUE_EMPTY   V_LIST_EMPTY 

typedef struct graph graph_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef enum color color_t; 
typedef int status_t; 
typedef int vertex_t; 
typedef int bool; 

typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrqueue_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef vnodeptrlist_t vnodeptr_prio_queue_t; 

/* Internal Layout */ 
// enumerations 
enum color { WHITE=0, GREY, BLACK }; 

/* A node in horizontal list */ 
struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* prev; 
    struct hnode* next; 
}; 

/* A node in vertical list */ 
struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t color; 
    double d; 
    struct vnode* pred_node; 
    
    struct vnode* prev; 
    struct vnode* next; 
}; 

/* Graph */ 
struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

/* A node for vertical node's queue */ 
struct vnodeptr_node  
{
    vnode_t* pv_node; 
    struct vnodeptr_node* next; 
    struct vnodeptr_node* prev; 
}; 

/* Graph Data Structure */ 
/* Interface */ 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g, const char* msg); 
int get_nr_vertices(graph_t* g); 
int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

status_t dfs(graph_t* g); 
status_t bfs(graph_t* g, vertex_t v); 
status_t dijkstra(graph_t* g, vertex_t s); 

/* Helpers */ 
void reset(graph_t* g); 
void dfs_visit(graph_t* g, vnode_t* pv_node); 

void initialize_single_source(graph_t* g, vnode_t* pv_s); 
void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v); 
void print_shortest_path(graph_t* g, vnode_t* pv_node); 
void print_all_shortest_paths(graph_t* g);  

/* Graph Auxilliary Data Structures */ 
/* Vertical List */ 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v_new); 
status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex); 
status_t v_destroy_list(vlist_t** ppv_list); 
// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* p_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search); 
vnode_t* v_get_node(vertex_t v_new); 

/* Horizontal List */ 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double d); 
status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex); 
status_t h_destroy_list(hlist_t** pph_list); 
// helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* p_delete_node); 
hnode_t* h_search_node(hlist_t* ph_List, vertex_t s_vertex); 
hnode_t* h_get_node(vertex_t v_new, double w); 

/* Queue */ 
vnodeptrqueue_t* vnptr_create_queue(void); 
status_t vnptr_enqueue(vnodeptrqueue_t* p_queue, vnode_t* new_vnodeptr); 
status_t vnptr_dequeue(vnodeptrqueue_t* p_queue, vnode_t** pp_new_vnodeptr); 
bool vnptr_is_queue_empty(vnodeptrqueue_t* p_queue); 
status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_queue);  

/* Stack */ 
vnodeptrstack_t* vnptr_create_stack(); 
status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack); 

/* Priority Queue */ 
vnodeptr_prio_queue_t* vnptr_create_prio_queue(void); 
status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_prio_queue, vnode_t* new_vnptr); 
status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr);   
bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* vnptr_prio_enqueue); 
status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t** pp_vnptr_prio_queue); 

/* vnodeptr List */ 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr_beg);
status_t vnptr_remove_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr_end); 
status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_delete_node); 
vnodeptrnode_t* vnptr_get_node(vnode_t* p_new_vnptr); 

// general purpose auxialliary functions 
void* xcalloc(size_t nr_items, size_t size_per_item); 

#endif // _GRAPH_H 

// ====== 2 ========== 
#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h>
#include <stdlib.h> 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

#define HLIST_DATA_NOT_FOUND    2 
#define VLIST_DATA_NOT_FOUND    HLIST_DATA_NOT_FOUND 

#define G_INVALID_VERTEX    3 
#define G_VERTEX_EXISTS     4 
#define G_INVALID_EDGE      5 
#define G_EDGE_EXISTS       6 

#define VLIST_EMPTY     7 
#define VQUEUE_EMPTY    VLIST_EMPTY 

/* typedefs */ 
typedef int vertex_t; 
typedef int status_t; 
typedef struct hnod ehnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

typedef struct vnodeptr_node vnptrnode_t; 
typedef vnptrnode_t vnptrlist_t; 
typedef vnptrlist_t vnptrqueue_t; 
typedef vnptrlist_t vnptrstack_t; 
typedef vnptrlist_t vnptr_prio_queue_t; 

/* Internal Layout */ 
struct hnode 
{
    vertex_t v; 
    vlist_t* pv_list; 
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

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_edges; 
    unsigned int nr_vertices; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv_node; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

// Graph Interface Functions 
graph_t* create_graph(void); 

status_t add_vertex(graph_t* g, vertex_t v_new); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double d);
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g, const char* msg); 
unsigned int get_nr_edges(graph_t* g); 
unsigned int get_nr_vertices(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

status_t dfs(graph_t* g); 
status_t bfs(graph_t* g, vertex_t v); 
status_t dijkstra(graph_t* g, vertex_t v); 

// Graph helpers 
status_t reset(graph_t* g); 
status_t dfs_visit(graph_t* g, vnode_t* pv_node); 

void initialize_single_source(graph_t* g, vnode_t* pv_s); 
void relax(graph_t* g, vnode_t* pv_v, vnode_t* pv_v); 
void print_shortest_path(graph_t* g, vnode_t* pv_node); 
void print_all_shortest_paths(graph_t* g); 

// Graph Auxilliary data structures 
// vertical list 
vlist_t* v_create_list(void); 
status_t v_insert_end(graph_t* g, vertex_t v_new); 
status_t v_remove_vertex(graph_t* g, vertex_t r_vertex); 
vnode_t* v_search_node(graph_t* g, vertex_t v_search); 
vnode_t* v_get_node(vertex_t v_new); 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search); 
vnode_t* v_get_node(vertex_t v_new); 

// horizontal list 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w); 
status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex); 
status_t h_destroy_list(hlist_t** pp_hlist); 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search); 
hnode_t* h_get_node(vertex_t v_new, double init_w); 

// bfs queue 
vnodeptr_queue_t* vnptr_create_queue(void); 
status_t vnptr_enqueue(vnodeptr_queue* p_queue, vnode_t* new_vnptr); 
status_t vnptr_dequeue(vnodeptr_queue* p_queue, vnode_t** p_new_vnptr); 
bool vnptr_is_queue_empty(vnodeptr_queue* p_queue); 
status_t vnptr_destroy_queue(vnodeptr_queue** pp_queue); 

// stack 
vnodeptrstack_t vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* pv_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* pv_stack, vnode_t** ppv_node); 
bool vnptr_is_stack_empty(vnodeptrstack_t* pv_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t* pp_stack); 

// priority queue 
vnodeptr_prio_queue_t* vnptr_create_prio_queue(void); 
status_t vnptr_insert_beg(vnodeptr_prio_queue_t* p_queue, vnode_t* pv_node); 
status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_queue, vnode_t** pp_vnode); 
bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue); 
status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t* pp_prio_queue); 

// list powering this all auxialliary data structures: list of vnode_t* 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_beg(vnodeptrlist_t* pv_list, vnode_t* new_vnodeptr); 
status_t vnptr_insert_end(vnodeptrlist_t* pv_list, vnode_t* new_vnodeptr); 
status_t vnptr_remove_beg(vnodeptrlist_t* pv_list, vnode_t** p_vnodeptr); 
status_t vnptr_remove_end(vnodeptrlist_t* pv_list, vnode_t** p_vnodeptr); 
status_t vnptr_is_list_empty(vnodeptrlist_t* pv_list); 
status_t vnptr_destroy_list(vnodeptrlist_t* pp_list); 

void vnptr_generic_insert(vnodeptr_node* beg, vnodeptr_node* mid, vnodeptr_node* end); 
void vnptr_generic_delete(vnodeptr_node* pvnptr_delete_node); 
vnode_t* vnptr_get_node(nodeptr_node* new_vnptr); 

// general purpose functions 
void* xcalloc(size_t nr_items, size_t size_per_item); 

#endif // _GRAPH_H 

// 3
#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h>
#include <stdlib.h> 

#define SUCCESS 1
#define FALSE   0 
#define TRUE    1

#define HLIST_DATA_NOT_FOUND    1 
#define VLIST_DATA_NOT_FOUND    HLIST_DATA_NOT_FOUND 

#define G_INVALID_VERTEX    3 
#define G_VERTEX_EXISTS     4 
#define G_INVALID_EDGE      5 
#define G_EDGE_EXISTS       6 
#define G_INCONSISTENT      7 

#define V_LIST_EMPTY     8 
#define V_QUEUE_EMPTY   V_LIST_EMPTY 

// typedefs 
typedef int vertex_t; 
typedef int status_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 
typedef enum color color_t; 
typedef int bool; 

typedef struct vnodeptr_node vnptrnode_t; 
typedef vnptrnode_t vnptrlist_t; 
typedef vnptrlist_t vnptrqueue_t; 
typedef vnptrlist_t vnptrstack_t; 
typedef vnptrlist_t vnptr_prio_queue_t; 

enum color { WHITE=0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t c; 
    
    double w; 
    vnode_t* u_pred; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices;  
    unsigned int nr_edges; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv_node; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
}; 

// Graph Interface Routines 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v_new); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t* g); 

status_t dfs(graph_t* g); 
status_t bfs(graph_t* g); 
status_t dijkstra(graph_t* g, vertex_t v); 

// graph helper functions 
void reset(graph_t* g); 
void dfs_visit(graph_t* g, vnode_t* pv); 

// auxilliaries for shortest path 
void initialize_single_source(graph_t* g, vnode_t* pv_s); 
void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v); 
void print_shortest_path(graph_t* g, vnode_t* pv_node); 
void print_all_shortest_paths(graph_t* g); 

/* Auxilliary Data Structures */ 
// 1] Vertical List Management 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v_new); 
status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex); 
status_t v_destroy_list(vlist_t** pp_vlist); 
// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_node(vnode_t v_new); 

// 2] Horizontal List Management 
// interface 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new); 
status_t h_remove_vertex(hlist_t* ph_list, vertex r_vertex); 
status_t h_destroy_list(hlist_t** pp_hlist); 
// helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_node(vertex_t v_new, double init_w); 

// 3] Queue Management 
// interface 
vnodeptrqueue_t* vnptr_create_queue(void); 
status_t vnptr_enqueue(vnodeptrqueue_t* p_queue, vnode_t* new_vnptr); 
status_t vnptr_dequeue(vnodeptrqueue_t* p_queue, vnode_t** p_new_vnptr); 
bool v_is_enqueue_empty(vnodeptrqueue_t* p_queue); 
status_t v_destroy_queue(vnodeptrqueue_t** pp_delete_queue); 

// 4] Stack Management 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_stack, vnode_t** p_new_vnptr); 
bool vnptr_is_stack_empty(vnodetrstack_t* p_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** pp_stack); 

// 5] Priority Queue Management 
vnodeptr_prio_queue_t* vnptr_create_prio_queue(void); 
status_t vnptr_prio_queue(vnodeptr_prio_queue_t* p_prio_queue, vnode_t* v_new_vnptr); 
status_t vnptr_prio_dequeue(vnodeptr_prio_queue_t* p_prio_queue); 
status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t** pp_prio_queue); 

// 6] List of vnode_t* powering auxilliary Data structures 
// interface 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_remove_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
bool vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list); 
// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_delete_node); 
vnodeptrnode_t* vnptr_get_node(vnode_t* vnptr_new); 

// general purpose helpers 
void* xcalloc(size_t nr_bytes, size_t size_per_item); 

#endif // _GRAPH_H 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

#define HLIST_DATA_NOT_FOUND    2 
#define VLIST_DATA_NOT_FOUND    HLIST_DATA_NOT_FOUND 

#define G_INVALID_VERTEX    3 
#define G_VERTEX_EXISTS     4 
#define G_INVALID_EDGE      5 
#define G_EDGE_EXISTS       6 

#define V_LIST_EMPTY    7 
#define V_QUEUE_EMPTY   V_LIST_EMPTY 

typedef int vertex_t; 
typedef int status_t; 
typedef int bool; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 
typedef enum color color_t; 

typedef vnodeptrnode vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrqueue_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef vnodeptrlist_t vnodeptr_prio_queue_t; 

enum color { WHITE=0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    double w; 
    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t c;

    double d; 
    vnode_t* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct graph
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

struct vnodeptr_node 
{
    vnode_t* pv_node; 
    struct vnodeptr_node* prev; 
    struct vnodeptr_node* next; 
} 

/* Graph Interface Functions */ 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v_new); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

status_t dfs(graph_t* g); 
status_t bfs(graph_t* g, vertex_t v); 
status_t dijkstra(graph_t* g, vertex_t s); 

// helpers 
void reset(graph_t* g); 
void dfs_visit(graph_t* g, vnode_t* pv_node); 

void initialize_single_source(graph_t* g, vnode_t* pv_s); 
void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v); 
void print_shortest_path(graph_t* g, vnode_t* pv_node); 
void print_all_shortest_paths(graph_t* g); 

/* Graph Auxilliary Data Structures  */ 
// 1] Vertical List Management 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v_new); 
status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex); 
status_t v_destroy_list(vlist_t** pp_vlist); 
// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t** p_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_node(vertex_t v_new); 

// 2] Horizontal List Management 
// interface
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new); 
status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex); 
status_t h_destroy_list(hlist_t** pph_list); 
// helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search); 
hnode_t* h_get_node(vertex_t v_new, double init_w); 

// 3] Queue Management 
vnodeptrqueue_t* vnptr_create_queue(void); 
status_t vnptr_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr); 
status_t vnptr_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr); 
bool vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue); 
status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue); 

// 4] Stack Management 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr); 
bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack); 
status_t vnptr_destroy_stack(vnptrstack_t* pp_vnptr_stack); 

// 5] Priority Queue Management 
vnodeptrqueue_t* vnptr_create_prio_list(void); 
status_t vnptr_prio_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr); 
status_t vnptr_prio_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr_queue); 
bool vnptr_is_prio_queue_empty(vnodeptrqueue_t* p_vnptr_prio_queue); 
status_t vnptr_destroy_prio_queue(vnodeptrqueue_t** pp_vnptr_prio_queue); 

// 6] vnodeptr List Management
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_remove_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
bool vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t* pp_vnptr_list); 
// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_vnptr_delete_node); 
vnodeptrnode_t* vnptr_get_node(vnodeptrnode_t* new_vnptr); 

/* General Purpose Helpers */ 
void* xcalloc(size_t nr_elements, size_t size_per_element); 

#endif // _GRAPH_H 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#define SUCCESS 1 
#define TRUE    1 
#define FALSE   0 

#define HLIST_DATA_NOT_FOUND    2 
#define VLIST_DATA_NOT_FOUND    HLIST_DATA_NOT_FOUND 

#define G_INVALID_VERTEX    3 
#define G_VERTEX_EXISTS     4 
#define G_INVALID_EDGE      5 
#define G_EDGE_EXISTS       6 

#define VNPTRLIST_EMPTY    7 
#define VNPTRQUEUE_EMPTY   VNPTRLIST_EMPTY 

// typedef 
typedef int status_t; 
typedef int vertex_t; 
typedef int bool; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 
typedef enum color color_t; 

typedef struct vnodeptr_node vnodeptrnode_t; 
typedef vnodeptrnode_t vnodeptrlist_t; 
typedef vnodeptrlist_t vnodeptrstack_t; 
typedef vnodeptrlist_t vnodeptrqueue_t; 
typedef vnodeptrlist_t vnodeptr_prio_queue_t; 

enum color { WHITE=0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    struct hnode* prev; 
    struct hnode* next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    color_t c; 
    double w; 
    vnode_t* pred_vertex; 

    struct vnode* prev; 
    struct vnode* next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_edges; 
    unsigned int nr_vertices; 
}; 

struct vnodeptrnode 
{
    vnode_t* pv_node; 
    struct vnodeptrnode* prev; 
    struct vnodeptrnode* next; 
}; 

/* Graph Management Functions */ 
// Interface 
graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void print_graph(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

status_t dfs(graph_t* g); 
status_t bfs(graph_t* g, vertex_t v); 
status_t dijsktra(graph_t* g, vertex_t s); 

// helpers 
void reset(graph_t* g); 
void dfs_visit(graph_t* g, vnode_t* pv_node); 

void initialize_single_source(graph_t* g, vnode_t* pv_s); 
void relax(graph_t* vnode_t* pv_u, vnode_t* pv_s); 
void print_shortest_path(graph_t* g, vnode_t* pv_node); 
void print_all_shortest_paths(graph_t* g); 

/* Graph Auxilliary Data Structure */ 
// 1] Vertical List Management 
// interface 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v_new); 
status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex); 
status_t v_destroy_list(vlist_t** pp_list); 
// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_node(vertex_t v_new); 

// 2] Horizontal List Management 
// interface
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v_new); 
status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex); 
status_t h_destroy_list(hlist_t** pp_h_list); 
// helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
hnode_t* h_get_node(vertex_t v_new, double w); 

// 3] Queue Mangement 
vnodeptrqueue_t* vnptr_create_queue(void); 
status_t vnptr_enqueue(vnodeptrqueue_t* p_queue, vnode_t* new_vnptr); 
status_t vnptr_dequeue(vnodeptrqueue_t* p_queue, vnode_t* p_vnptr); 
bool vnptr_is_queue_empty(vnodeptrqueue_t* p_queue); 
status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_queue); 

// 4] Stack Management 
vnodeptrstack_t* vnptr_create_stack(void); 
status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr); 
status_t vnptr_pop_stack(vnodeptrstack_t* p_stack, vnode_t* p_vnptr); 
bool vnptr_is_stack_empty(vnodeptrstack_t* p_stack); 
status_t vnptr_destroy_stack(vnodeptrstack_t** p_pstack); 

// 5] Priority Queue Management 
vnodeptr_prio_queue_t* vnptr_create_prio_queue(void); 
status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_queue, vnode_t* new_vnptr); 
status_t vnptr_prio_dequeue(vnodeptr_prio_queue_t* p_queue, vnode_t** p_vnptr); 
bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue); 
status_t vnptr_destroy_queue(vnodeptr_prio_queue_t** pp_prio_queue); 

// 6] vnptr List Managenent 
// interface 
vnodeptrlist_t* vnptr_create_list(void); 
status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr); 
status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
status_t vnptr_remove_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr); 
bool vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list); 
status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list); 
// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end); 
void vnptr_generic_delete(vnodeptrnode_t* p_vnptr_delete_node); 
vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr); 

/* General Purpose Helpers */ 
void* xcalloc(size_t nr_items, size_t size_per_item); 

#endif // _GRAPH_H 

