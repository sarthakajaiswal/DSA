#ifndef GRAPH_H 
#define GRAPH_H 

#define SUCCESS     1 
#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

typedef int     vertex_t; 
typedef int     status_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
unsigned int get_nr_edges(graph_t* g); 
unsigned int get_nr_vertices(graph_t* g); 
status_t destroy_graph(graph_t* g); 

#endif 

#ifndef GRAPH_H 
#define GRAPH_H 

#define SUCCESS     1 
#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

typedef int vertex_t; 
typedef int status_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    struct vnode* v_next; 
    struct vnode* v_prev; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

#endif // GRAPH_H 

#ifndef GRAPH_H 
#define GRAPH_H 

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
    struct hnode h_prev; 
    struct hnode h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    struct vnode* v_next; 
    struct vnode* v_prev; 
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

#endif // GRAPH_H 

#ifndef GRAPH_H 
#define GRAPH_H 

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
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_list; 
    struct vnode* v_prev; 
    struct vnode* v_next;  
}; 

struct graph 
{
    vlist_t* pv_list; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
void show_graph(graph_t* g, const char* msg); 
unsigned int get_nr_edges(graph_t* g); 
unsigned int get_nr_vertices(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

#endif // GRAPH_H 

#ifndef GRAPH_H 
#define GRAPH_H 

#define SUCCESS 1 
#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 
#define G_INCONSISTENT      -5 

typedef int status_t; 
typedef int vertex_t; 
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
    hlist_t* ph_head_node;
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    unsigned int nr_vertices; 
    unsigned int nr_edges; 
}; 

graph_t* create_graph(void); 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t  v_end); 
void show_graph(graph_t* g, const char* msg); 
unsigned int get_nr_vertices(graph_t* g); 
unsigned int get_nr_edges(graph_t* g); 
status_t destroy_graph(graph_t** pp_g); 

#endif // GRAPH_H 

