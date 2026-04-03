#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

// =============== CLASS NODE ================ 
node::node(int _data) : data(_data), prev(0), next(0) 
{
}
// =============== CLASS NODE END ============ 

// ============== CLASS LIST ================= 
list::list() 
{
    head_node = new node(0); 
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::~list() 
{
    node* run_next = 0; 

    for(node* run = head_node->next; run != head_node; run = run_next) 
    {
        run_next = run->next; 
        delete run; 
    } 

    delete head_node; 
} 

void list::insert_start(int new_data) 
{
    generic_insert(head_node, new node(new_data), head_node->next); 
} 

void list::insert_end(int new_data) 
{
    generic_insert(head_node->prev, new node(new_data), head_node); 
} 

void list::insert_after(int existing_data, int new_data) 
{
    node* existing_node = 0; 
    
    existing_node = this->search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("list::insert_after():invalid existing data"); 

    generic_insert(existing_node, new node(new_data), existing_node->next); 
} 

void list::insert_before(int existing_data, int new_data) 
{
    node* existing_node = search_node(existing_data); 
    if(existing_data == 0) 
        throw list_data_not_found("list::inert_before(): invalid existing data"); 
    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void list::get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list::get_start():empty list"); 
    *p_start_data = head_node->next->data; 
} 

void list::get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list::get_end():empty list"); 
    *p_end_data = head_node->prev->data; 
} 

void list::pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list::pop_start(): list empty"); 
    *p_start_data = head_node->next->data; 
    generic_delete(head_node->next); 
} 

void list::pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list::pop_end(): list empty"); 
    *p_end_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
} 

void list::remove_start() 
{
    if(empty()) 
        throw list_empty("list::remove_start():list empty"); 
    generic_delete(head_node->next); 
} 

void list::remove_end() 
{
    if(empty()) 
        throw list_empty("list::remove_end():list empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_data(int r_data) 
{
    node* remove_node = 0; 

    remove_node = search_node(r_data); 
    if(remove_node == 0) 
        throw list_data_not_found("list::remove_data(): list data not found"); 
    
    generic_delete(remove_node); 
} 

std::size_t list::size() const 
{
    std::size_t N = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        ++N; 

    return N; 
} 

bool list::empty() const 
{
    return head_node->next == head_node && head_node->prev == head_node; 
} 

void list::show(const char* msg) const 
{
    if(msg) 
        std::cout << msg << std::endl; 

    std::cout << "[START]<->"; 
    for(node* run = head_node->next; run != head_node; run = run->next)  
        std::cout << "[" << run->data << "]<->"; 
    std::cout << "[END]" << std::endl; 
} 

list* list::concat(list* other) const 
{
    list* concatenated_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 
    for(node* run = other->head_node->next; run != other->head_node->next; run = run->next) 
        concatenated_list->insert_end(run->data); 

    return concatenated_list; 
} 

void list::append(list* other) 
{
    if(!other->empty()) 
    {
        head_node->prev->next = other->head_node->next; 
        other->head_node->next->prev = head_node->prev; 

        head_node->prev = other->head_node->prev; 
        other->head_node->prev->next = head_node; 
    } 

    other->head_node->next = other->head_node; 
    delete other; 
} 

list* list::merge(list* other) const 
{
    list* merged_list = new list; 

    node* run1 = head_node->next; 
    node* run2 = other->head_node->next; 

    int data; 

    while(true) 
    {
        if(run1 == head_node) 
        {
            while(run2 != other->head_node) 
            {
                merged_list->insert_end(run2->data); 
                run2 = run2->next; 
            } 
            break; 
        } 

        if(run2 == other->head_node) 
        {
            while(run1 != head_node) 
            {
                merged_list->insert_end(run1->data); 
                run1 = run1->next; 
            } 
            break; 
        } 

        if(run1->data <= run2->data) 
        {
            data = run1->data; 
            run1 = run1->next; 
        } 
        else 
        {
            data = run2->data; 
            run2 = run2->next; 
        } 
        merged_list->insert_end(data); 
    } 

    return (merged_list); 
} 

list* list::to_list(int* p_array, std::size_t N) 
{
    list* list_from_array = new list; 

    for(std::size_t i = 0; i < N; ++i) 
        list_from_array->insert_end(p_array[i]); 

    return list_from_array; 
} 

void list::to_array(int** pp_array, std::size_t* pN) const 
{
    std::size_t N = size(); 
    *pN = N; 

    int* p_array = new int[N]; 

    std::size_t i = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        p_array[i++] = run->data; 

    *pp_array = p_array; 
} 

list* list::get_reversed_list() const 
{
    list* reversed_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        reversed_list->insert_start(run->data); 

    return reversed_list; 
} 

void list::reverse() 
{
    if(! (head_node->next == head_node || head_node->next->next == head_node)) 
    {
        node* original_first = head_node->next; 

        node* run_next = 0; 
        for(node* run = original_first->next; run != head_node; run = run_next) 
        {
            run_next = run->next; 

            run->next = head_node->next; 
            run->prev = head_node; 
            head_node->next->prev = run; 
            head_node->next = run; 
        } 

        original_first->next = head_node; 
        head_node->prev = original_first; 
    } 
} 

list::iterator list::begin() 
{
    return list::iterator(head_node->next); 
} 

list::iterator list::end() 
{
    return list::iterator(head_node); 
} 

// Iterator member functions 
list::iterator::iterator(node* _p_node) : p_node(_p_node) 
{
}

list::iterator list::iterator::operator++() 
{
    p_node = p_node->next; 
    return *this; 
} 

list::iterator list::iterator::operator--() 
{
    p_node = p_node->prev; 
    return *this; 
} 

list::iterator list::iterator::operator++(int) 
{
    iterator iter(p_node); 
    p_node = p_node->next; 
    return iter; 
} 

list::iterator list::iterator::operator--(int) 
{
    iterator iter(p_node); 
    p_node = p_node->prev; 
    return iter; 
} 

int list::iterator::operator*() const 
{
    return p_node->data; 
} 

bool list::iterator::operator==(const iterator& other) const 
{
    return p_node == other.p_node; 
} 

bool list::iterator::operator!=(const iterator& other) const 
{
    return p_node != other.p_node; 
} 

// private member functions 
void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{ 
    p_mid->next = p_end; 
    p_mid->prev = p_start; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
} 

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run != head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 

// ============== CLASS LIST END ============= 
