// ============= LIST CLIENT ============== 
#include <iostream> 
#include "list.hpp" 

void test_single_list_functions(); 
void test_interlist_functions(); 

int main() 
{
    test_single_list_functions(); 
    test_interlist_functions(); 

    return 0; 
} 

void test_single_list_functions() 
{
    list* L = new list; 
    int data; 
    int start_data, end_data; 

    // try to invoke invalid operations on list 
    if(L->empty()) 
    {
        std::cout << "List is empty" << std::endl; 
    } 
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    } 

    std::cout << "L->size() = " << L->size() << std::endl; 

    try 
    {
        L->get_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_start():" << e.what() << std::endl; 
    } 

    try 
    {
        L->get_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "pop_start():" << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_end(&end_data); 
    } 
    catch 
    {
        std::cerr << "pop_end() : " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_start(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_end(): " << e.what() << std::endl; 
    } 

    for(data = 10; data <= 50; data += 10) 
        L->insert_end(data); 

    L->show("List L after insert data at end:"); 

    for(data = 60; data <= 100; data += 10) 
        L->insert_start(data); 

    L->show("List L after insert data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    try 
    {
        L->insert_before(-100, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after: insert_after(), insert_before():"); 

    L->get_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after get_start():"); 

    L->get_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after get_end():"); 

    L->pop_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after pop_start():"); 

    L->pop_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after pop_end():"); 

    L->remove_start(); 
    L->show("after remove_start():"); 

    L->remove_end(); 
    L->show("after remove_end():"); 

    try 
    {
        L->remove_data(-10); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->remove_data(10); 
    L->show("after remove_data(10):"); 

    if(!L->empty()) 
        std::cout << "List is not empty (expected)" << std::endl; 
    else 
        std::cerr << "List is empty (unexpected error)" << std::endl; 

    std::cout << "L->size(): " << L->size() << std::endl; 

    list* reversed_list = L->get_reversed_list(); 
    L->show("L:"); 
    reversed_list->show("reversed version of L:"); 

    L->show("before L->reverse():"); 
    L->reverse(); 
    L->show("after L->reverse():"); 

    delete L; 
    delete reversed_list; 
} 

void test_interlist_functions() 
{
    list* L1 = new list; 
    list* L2 = new list; 

    for(int data = 0; data <= 50; data = data + 10) 
        L1->insert_end(data); 

    for(int data = 5; data < 75; data = data + 10); 
        L2->insert_end(data); 

    list* concatenated_list = L1->concat(l2); 
    list* merged_list = L1->nerge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatenated_list->show("concatenated list:"); 
    merged_list=>show("merged list:"); 

    /* Showing concatenatd list using iterator */ 
    for(list::iterator iter = concatenated_list->begin(); iter != concatenated_list->end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    L1->append(L2); 
    L1->show("After L1->append(L2):"); 
    L2 = 0; 

    delete L1; 
    L1 = 0; 

    delete concatenated_list; 
    concatenated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
} 

#include <stdio.h> 
#include "list.hpp" 

void test_single_list_functions(); 
void test_interlist_functions(); 

int main(void) 
{
    test_single_list_functions(); 
    test_interlist_functions(); 

    return 0; 
} 

void test_single_list_functions() 
{
    list* L = new list(); 
    int data; 
    int start_data, end_data; 

    // try to invoke invalid operations on empty list 
    if(L->empty()) 
    {
        std::cout << "List is empty" << std::endl; 
    } 
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    } 

    std::cout << "L->size() = " << L->size() << std::endl; 

    try 
    {
        L->get_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->get_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_start(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "pop_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_start() 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_end(): " << e.what() << std::endl; 
    } 

    for(data = 10; data <= 50; data += 1) 
        L->insert_end(data); 

    L->show("list L after inserting data at end:"); 

    for(data = 60; data <= 100; data += 10) 
        L->insert_start(data); 

    L->show("List L after inserting data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    try 
    {
        L->insert_before(-300, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after: insert_after(), insert_before(): "); 

    L->get_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after get_start():"); 

    L->get_end(&end_data); 
    std::cout << "end_data = " << end_data << std::endl; 
    L->show("after get_end():"); 

    L->pop_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after pop_start():"); 

    L->pop_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after pop_end():"); 

    L->remove_start(); 
    L->show("after remove_start():"); 

    L->remove_end(); 
    L->show("after remove_end():"); 

    try 
    {
        L->remove_data(-10); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->remove_data(10); 
    L->show("after remove_data(10):"); 

    if(!L->empty()) 
        std::cout << "List is not empty (expected)" << std::endl; 
    else 
        std::cout << "List is empty (unexpected error)" << std::endl; 

    std::cout << "L->size() = " << L->size() << std::endl; 

    list* reversed_list = L->get_reversed_list(); 

    reversed_list->show("reversed version of L"); 

    L->show("before reverse_list()"); 
    L->reverse_list(); 
    L->show("after reverse_list():"); 

    delete L; 
    delete reversed_list; 
} 

void test_interlist_functions() 
{
    list* L1 = new list; 
    list* L2 = new list; 

    for(int data = 0; data <= 50; data += 10) 
        L1->insert_end(data); 

    for(int data = 5; data <= 75; data += 10) 
        L2->insert_end(data); 
    
    list* concatenated_list = L1->concat(L2); 
    list* merged_list = L1->merge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatenated_list->show("concatenated list:");
    merged_list->show("merged list: "); 

    /* Showing concatenated list using iterator */ 
    for(list::iterator iter = concatenated_list->begin(); iter != concatenated_list->end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    L1->append(L2); 
    L1->show("After L1->append(L2):"); 
    L2 = 0; 

    delete L1; 
    L1 = 0; 

    delete concatenated_list; 
    concatenated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
} 

#include <stdio.h> 
#include "list.hpp" 

void test_single_list_functions(); 
void test_interlist_functions(); 

int main() 
{
    test_single_list_functions(); 
    test_interlist_functions(); 

    return 0; 
} 

void test_single_list_functions() 
{
    list* L = new list(); 
    int data; 
    int start_data, end_data; 

    // try to invoke invalid functions on empty list 
    if(L->empty()) 
    {
        std::cout << "List is empty" << std::endl; 
    } 
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    } 

    std::cout << "L->size() = " << L->size() << std::endl; 

    try 
    {
        L->get_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->get_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_start(&start_data); 
    } 
    catch(const list_empty& e)  
    {
        std::cerr << "pop_start():" << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "pop_end():" << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_start(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_end(): " << e.what() << std::endl; 
    } 

    for(data = 10; data <= 50; data += 10) 
        L->insert_end(data); 

    L->show("after inserting data at end:"); 

    for(data = 60; data <= 100; data += 10) 
        L->insert_start(data); 

    L->show("after inserting data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    try 
    {
        L->insert_before(-300, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cout << e.what() << std::endl; 
    } 

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after: insert_after() and insert_before(): "); 

    L->get_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after get_start():"); 

    L->get_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after get_end():"); 

    L->pop_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after pop_start():"); 

    L->pop_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after pop_end():"); 

    L->remove_start(); 
    L->show("after remove_start():"); 

    L->remove_end(); 
    L->show("after remove_end():"); 

    try 
    {
        L->remove_data(-10); 
    } 
    catch(const list_data_not_found& e)  
    { 
        std::cerr << e.what() << std::endl; 
    } 

    L->remove_data(10); 
    L->show("after remove_data(10):"); 

    if(!L->empty()) 
        std::cout << "List is not empty (expected)" << std::endl; 
    else 
        std::cout << "List is empty (unexpected error) " << std::endl; 

    std::cout << "L->size(): " << L->size() << std::endl; 

    list* reversed_list = get_reversed_list(); 
    L->show("L:"); 
    reversed_list->show("reversed list:"); 

    L->show("Before reverse_list():"); 
    L->reverse(); 
    L->show("After reverse_list():"); 

    delete L; 
    delete reverse_list; 
} 

void test_interlist_functions() 
{
    list* L1 = new list; 
    list* L2 = new list; 

    for(int data = 10; data <= 50; data += 10) 
        L->insert_end(data); 

    for(int data = 5; data <= 75; data += 10) 
        L->insert_end(data); 

    list* concatenated_list = L1->concat(L2); 
    list* merged_list = L1->merge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatenated_list->show("concatenated list:"); 
    merged_list->show("merged list:"); 

    /* Showing concatenated list using iterator */ 
    for(list::iterator iter = concatenated_list->begin(); iter != concatenated_list->end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    L1->append(L2); 
    L1->show("after L1->append(L2) :"); 
    L2 = 0; 

    delete L1; 
    L1 = 0; 

    delete concatenated_list; 
    concatenated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
} 

#include <stdio.h> 
#include "list.hpp"

void test_single_list_functions(); 
void test_interlist_functions(); 

int main() 
{
    test_single_list_functions(); 
    test_interlist_functions(); 
    return 0; 
} 

void test_single_list_functions() 
{
    list* L = new list(); 
    int data; 
    int start_data, end_data; 

    // try to invoke invalid functions on empty list 
    if(L->empty()) 
    {
        std::cout << "List is empty" << std::endl; 
    } 
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    } 

    std::cout << "L->size() = " << L->size() << std::endl; 

    try 
    {
        L->get_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_start(): "<< e.what() << std::endl; 
    } 

    try 
    {
        L->get_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end():" << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_start(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_end():" << e.what() << std::endl; 
    } 

    for(data = 10; data <= 50; data += 10) 
        L->insert_end(data); 

    L->show("after inserting data at end:"); 

    for(data = 60; data <= 100; data += 10) 
        L->insert_start(data); 

    L->show("after inserting data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    } 
    catch 
    {
        std::cerr << e.what() << std::endl; 
    } 

    try 
    {
        L->insert_before(-300, 200); 
    } 
    catch 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after insert_after() and insert_before(): "); 

    L->get_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after get_start():"); 

    L->get_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after get_end():"); 

    L->pop_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after pop_start():"); 

    L->pop_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after pop_end():"); 

    L->remove_start(); 
    L->show("after remove_start():"); 

    L->remove_end(); 
    L->show("after remove_end():"); 

    try 
    {
        L->remove_data(-10); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->remove_data(10); 
    L->show("after remove_data():"); 

    if(!L->empty()) 
        std::cout << "list is not empty (expected) " << std::endl; 
    else 
        std::cerr << "List is empty (unexpected error)" << std::endl; 

    std::cout << "L->size() = " << L->size() << std::endl; 

    list* reversed_list = get_reversed_list(); 
    L->show("L:"); 
    reversed_list->show("reversed_list:"); 

    L->show("before reverse():"); 
    L->reverse(); 
    L->show("after reverse():"); 

    delete L; 
    delete reversed_list; 
} 

void test_interlist_functions() 
{
    list* L1 = new list; 
    list* L2 = new list; 

    for(int data = 10; data <= 50; data += 10) 
        L1->insert_end(data); 

    for(int data = 5; data <= 75; data += 10) 
        L2->insert_end(data); 

    list* concatenated_list = L1->concat(L2); 
    list* merged_list = L1->merge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatenated_list->show("concatenated list:"); 
    merged_list->show("merged list:"); 

    /* Showing concatenated list using iterator */ 
    for(list::iterator iter = concatenated_list->begin(); iter != concatenated_list->end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    L1->append(L2); 
    L1->show("after L1->append(L2):"); 
    L2 = 0; 

    delete L1; 
    L1 = 0; 

    delete concatenated_list; 
    concatenated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
} 

#include <iostream> 
#include "list.hpp" 

void test_single_list_functions(); 
void test_interlist_functions(); 

int main() 
{
    test_single_list_functions(); 
    test_interlist_functions(); 
    return 0; 
} 

void test_single_list_functions() 
{
    list* L = new list(); 
    int data; 
    int start_data, end_data; 

    // try to invoke invalid operations of empty list 
    if(L->empty()) 
    {
        std::cout << "List is empty" << std::endl; 
    } 
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    } 

    std::cout << "L->size() = " << L->size() << std::endl; 

    try 
    {
        L->get_start(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->get_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "get_end():" << e.what() << std:endl; 
    } 

    try 
    {
        L->pop_start(&start_data); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "pop_start(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->pop_end(&end_data); 
    } 
    catch(const list_empty& e) 
    {
        std:cerr << "pop_end(): " << e.what() << std::endl; 
    } 

    try 
    {
        L->remove_start() 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_start():" << e.what() << std::endl; 
    }

    try 
    {
        L->remove_end(); 
    } 
    catch(const list_empty& e) 
    {
        std::cerr << "remove_end(): " << e.what() << std::endl; 
    } 

    for(data = 10; data <= 50; data += 10) 
        L->insert_end(data); 

    L->show("after inserting data at end:"); 

    for(data = 60; data <= 100; data += 10) 
        L->insert_start(data); 

    L->show("after inserting data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cout << e.what() << std::endl; 
    } 

    try 
    {
        L->insert_before(-300, 200); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after: insert_start() and insert_end():"); 

    L->get_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after get_start():"); 

    L->get_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after get_end(): " ); 

    L->pop_start(&start_data); 
    std::cout << "start data = " << start_data << std::endl; 
    L->show("after pop_start(): "); 

    L->pop_end(&end_data); 
    std::cout << "end data = " << end_data << std::endl; 
    L->show("after pop_end()"); 

    L->remove_start(); 
    L->show("after remove_start():"); 

    L->remove_end(); 
    L->show("after remove_end():"); 
    
    try 
    {
        L->remove_data(-10); 
    } 
    catch(const list_data_not_found& e) 
    {
        std::cerr << e.what() << std::endl; 
    } 

    L->remove_data(10); 
    L->show("after remove_data(10):"); 

    if(!L->empty()) 
        std::cout << "List is not empty (expected)" << std::endl; 
    else 
        std::cout << "List is empty (unexpected error)" << std::endl; 

    std::cout << "L->size() = " << L->size() << std::endl; 

    list* reversed_list = get_reversed_list(); 
    L->show("L:"); 
    reversed_list->show("reversed version of L:"); 

    L->show("before reverse():"); 
    L->reverse(); 
    L->show("after reverse():"); 

    delete L; 
    delete reversed_list; 
} 

void test_interlist_functions() 
{   
    list* L1 = new list; 
    list* l2 = new list; 

    for(int data = 10; data <= 50; data += 10) 
        L1->insert_end(data); 

    for(int data = 5; data <= 75; data += 10) 
        L2->insert_end(data); 

    list* concatenated_list = L1->concat(L2); 
    list* merged_list = L1->merge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatenated_list->show("concatenated list:"); 
    merged_list->show("merged list:"); 

    /* Showing concatenated list with iterator */ 
    for(
        list::iterator iter = concatenated_list->begin(); 
        iter != concatenated_list->end(); 
        ++iter 
    ) 
        std::cout << "*iter = " << *iter << std::endl; 

    L1->append(L2); 
    L1->show("After L1->append(L2):"); 
    L2 = 0; 

    delete L1; 
    L1 = 0; 

    delete concatenated_list; 
    concatenated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
} 

// ============= LIST HEADER ============== 
// exceptions 
#ifndef LIST_EXCEPTIONS_HPP 
#define LIST_EXCEPTIONS_HPP 

#endif // LIST_EXCEPTIONS_HPP 

#ifndef LIST_EXCEPTIONS_HPP 
#define LIST_EXCEPTIONS_HPP 

#endif // LIST_EXCEPTIONS_HPP 

#ifndef LIST_EXCEPTIONS_HPP 
#define LIST_EXCEPTIONS_HPP 

#endif // LIST_EXCEPTIONS_HPP 

#ifndef LIST_EXCEPTIONS_HPP 
#define LIST_EXCEPTIONS_HPP 

#endif // LIST_EXCEPTIONS_HPP 

#ifndef LIST_EXCEPTIONS_HPP 
#define LIST_EXCEPTIONS_HPP 

#endif // LIST_EXCEPTIONS_HPP 

#include <stdexcept> 
#include <stdexcept> 
#include <stdexcept> 
#include <stdexcept> 
#include <stdexcept> 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
}; 

class list_empty : public std::runtime_error 
{
    public: 
        list_empty(const char* msg); 
} 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

class list_data_not_found : public std::runtime_error 
{
    public: 
        list_data_not_found(const char* msg); 
}; 

#include "list_exceptions.hpp" 
#include "list_exceptions.hpp" 
#include "list_exceptions.hpp" 
#include "list_exceptions.hpp" 
#include "list_Exceptions.hpp" 

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg) 
{

} 

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg) 
{

} 

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg) 
{

} 

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg) 
{

} 

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg) 
{

} 

list_empty::list_empty(const char* msg) : std::runtime_error(msg) 
{

} 

list_empty::list_empty(const char* msg) : std::runtime_error(msg) 
{

} 

list_empty::list_empty(const char* msg) : std::runtime_error(msg) 
{

} 

list_empty::list_empty(const char* msg) : std::runtime_error(msg) 
{

} 

list_empty::list_empty(const char* msg) : std::runtime_error(msg) 
{

} 

#ifndef LIST_HPP 
#define LIST_HPP 

#endif // LIST_HPP 

#ifndef LIST_HPP 
#define LIST_HPP 
#endif // LIST_HPP 

#ifndef LIST_HPP 
#define LIST_HPP 

#endif // LIST_HPP 

#ifndef LIST_HPP 
#define LIST_HPP 

#endif // LIST_HPP 

#ifndef LIST_HPP 
#define LIST_HPP 

#endif // LIST_HPP 

#include "list_exceptions.hpp" 
#include <iostream> 
#include "list_exceptions.hpp" 
#include <iostream> 
#include "list_exceptions.hpp" 
#include <iostream> 
#include "list_exceptions.hpp" 
#include <iostream> 
#include "list_exceptions.hpp" 
#include <iostream> 

class node 
{
    friend class list; 

    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data); 
}; 

class node 
{
    friend class list; 

    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data); 
}; 

class node 
{
    friend class list; 

    private: 
        int data;
        node* prev; 
        node* next; 
        node(int _data); 
}; 

class node 
{
    friend class list; 

    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data); 
};  

class node 
{
    friend class list; 

    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data); 
}; 

class list 
{
    private: 
        node* head_node; 

        static void generic_insert(node* p_beg, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(int search_data) const; 

    public: 
        list(); 
        ~list(); 

        void insert_start(int new_data); 
        void insert_end(int new_data); 
        void insert_after(int existing_data, int new_data); 
        void insert_before(int existing_data, int new_data); 

        void get_start(int* p_start_data); 
        void get_end(int* p_end_data); 

        void pop_start(int* p_start_data); 
        void pop_end(int* p_end_data); 

        void remove_start(); 
        void remove_end(); 
        void remove_data(int r_data); 

        std::size size() const; 
        bool empty() const; 
        void show(const char* msg); 

        list* concat(list* other) const; 
        void append(list* other); 
        list* merge(list* other) const; 

        static list* to_list(int* p_array, std::size_t N); 
        void to_array(int** pp_array, std::size_t* pN) const; 

        list* get_reversed_list() const; 
        void reverse(); 

        class iterator 
        {
            private: 
                node* p_node; 

            public: 
                iterator(node* _p_node = 0); 
                iterator operator++(); 
                iterator operator--(); 
                iterator operator++(int); 
                iterator operator--(int); 
                int operator*() const; 
                bool operator==(const iterator& other) const; 
                bool operator!=(const iterator& other) const; 
        }; 

        iterator begin(); 
        iterator end(); 
}; 

class list 
{
    private: 
        node* head_node; 

        static void generic_insert(node* p_start, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(int search_data) const; 

    public: 
        list(); 
        ~list(); 

        void insert_start(int new_data); 
        void insert_end(int new_data); 
        void insert_before(int existing_data, int new_data); 
        void insert_after(int existing_data, int new_data); 

        void get_start(int* p_start_data); 
        void get_end(int* p_end_data); 

        void pop_start(int* p_start_data); 
        void pop_end(int* p_end_data); 

        void remove_start(); 
        void remove_end(); 
        void remove_data(int r_data); 

        std::size_t size() const; 
        bool empty() const; 
        void show(const char* msg) const; 

        list* concat(list* other) const; 
        list* merge(list* other) const; 
        void append(list* other); 

        static list* to_list(int* p_array, std::size_t N); 
        void to_array(int** pp_array, int* pN) const; 

        list* get_reversed_list() const; 
        void reverse(); 

        class iterator 
        {
            private: 
                node* p_node; 

            public: 
                iterator(node* _p_node = 0); 
                iterator operator++(); 
                iterator operator--(); 
                iterator operator++(int); 
                iterator operator--(int); 
                int operator*() const; 
                bool operator==(const iterator& other) const; 
                bool operator!=(const iterator& other) const; 
        }; 

        iterator begin(); 
        iterator end(); 
}; 

class list 
{
    private: 
        node* head_node; 

        static void generic_insert(node* p_start, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(int search_data); 

    public: 
        list(); 
        ~list(); 

        void insert_start(int new_data); 
        void insert_end(int new_data); 
        void insert_before(int existing_data, int new_data); 
        void insert_after(int existing_data, int new_data); 

        void get_start(int* p_start_data); 
        void get_end(int* p_end_data); 

        void pop_start(int* p_start_data); 
        void pop_end(int* p_end_data); 

        void remove_start(); 
        void remove_end(); 
        void remove_data(int r_data); 

        std::size size() const; 
        bool empty() const; 
        void show(const char* msg) const; 

        list* concat(list* other) const; 
        void append(list* other); 
        list* merge(list* other) const; 

        static list* to_list(int* p_array, int N); 
        void to_array(int** pp_array, int* pN) const; 

        list* get_reversed_list() const; 
        void reverse(); 

        class iterator 
        {
            private: 
                node* p_node; 

            public: 
                iterator(node* _p_node=0); 
                iterator operator++(); 
                iterator operator--(); 
                iterator operator++(const); 
                iterator operator--(const); 
                int operator*() const; 
                bool operator==(const iterator& other) const; 
                bool operator!=(const iterator& other) const; 
        }; 

        iterator begin(); 
        iterator end(); 
}; 

class list 
{
    private: 
        node* head_node; 

        static void generic_insert(node* p_start, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(int s_data) const; 

    public: 
        list(); 
        ~list(); 

        void insert_start(int new_data); 
        void insert_end(int new_data); 
        void insert_after(int existing_data, int new_data); 
        void insert_before(int existing_data, int new_data); 

        void get_start(int* p_start_data); 
        void get_end(int* p_end_data); 

        void pop_start(int* p_start_data); 
        void pop_end(int* p_end_data); 

        void remove_start(); 
        void remove_end(); 
        void remove_data(int r_data); 

        std::size size() const; 
        bool empty() const; 
        void show(const char* msg) const; 

        list* merge(list* other) const; 
        void append(list* other);
        list* concat(list* other) const; 

        static list* to_list(int* p_array, int N); 
        void to_array(int** pp_array, int* pN); 

        list* get_reversed_list() const; 
        void reverse(); 

        class iterator 
        {
            private: 
                node* p_node; 

            public: 
                iterator(node* _p_node=0);
                iterator operator++(); 
                iterator operator--(); 
                iterator operator++(int); 
                iterator operator--(int); 
                int operator*() const; 
                bool operator==(const iterator& other) const; 
                bool operator!=(const iterator& other) const; 
        }; 

        iterator begin(); 
        iterator end(); 
}; 

class list 
{
    private: 
        node* head_node; 

    public: 
        list(); 
        ~list(); 

        void insert_start(int new_data); 
        void insert_end(int new_data); 
        void insert_before(int existing_data, int new_data); 
        void insert_after(int existing_data, int new_data); 

        void get_start(int* p_start_data); 
        void get_end(int* p_end_data); 

        void pop_start(int* p_start_data); 
        void pop_end(int* p_end_data); 

        void remove_start(); 
        void remove_end(); 
        void remove_data(); 

        std::size size() const; 
        bool empty() const; 
        void show(const char* msg) const; 

        list* merge(list* other) const; 
        list* concat(list* other) const; 
        void append(list* other); 

        static list* to_list(int* p_array, int N); 
        void to_array(int** pp_array, int* pN) const; 

        list* get_reversed_list() const; 
        void reverse(); 

        class iterator 
        {
            private: 
                node* p_node; 

            public: 
                iterator(node* _p_node=0); 
                iterator operator++(); 
                iterator operator--(); 
                iterator operator++(int); 
                iterator operator--(int); 
                int operator*() const; 
                bool operator==(iterator& other) const; 
                bool operator!=(iterator& other) const; 
        }; 

        iterator begin(); 
        iterator end(); 
}; 

// ============= LIST SERVER ============== 
#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

list::list() 
{
    head_node = new node(0); 
    head_node->prev = new_node; 
    head_node->next = new_node; 
} 

list::~list()
{
    node* run = 0; 
    node* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next) 
    {
        run_next = run->next; 
        delete run;  
    } 

    delete head_node; 
    head_node = 0; 
} 

void insert_start(int new_data) 
{
    generic_insert(head_node, new node(new_data), head_node->next); 
}

void insert_end(int new_data) 
{
    generic_insert(head_node->prev, new node(new_data), head_node); 
} 

void insert_before(int existing_data, int new_data) 
{
    node* existing_node = search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("list::insert_after():invalid existing data"); 

    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void insert_after(int existing_data, int new_data) 
{
    node* existing_node = this->search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("list::insert_after(): invalid existing data"); 
    
    generic_insert(existing_node, new node(new_data), existing_node->next); 
} 

void get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list::get_start(): list is empty"); 

    *p_start_data = head_node->next->data; 
} 

void get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list::get_end(): list is empty"); 

    *p_end_data = head_node->prev->data; 
} 

void pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list::pop_start():list is empty"); 

    *p_start_data = head_node->next->data; 
    generic_delete(head_node->next); 
} 

void pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list::pop_end(): list is empty"); 
    
    *p_end_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
} 

void remove_start() 
{
    if(empty()) 
        throw list_empty("list::remove_start(): list is empty"); 
    generic_delete(head_node->next); 
} 

void remove_end() 
{
    if(empty()) 
        throw list_empty("list::remove_end(): list is empty"); 
    generic_delete(head_node->prev); 
} 

void remove_data(int r_data) 
{
    node* remove_node = search_node(r_data); 
    if(0 == remove_node) 
        throw list_data_not_found("list::remove_data(): invalid remove data"); 

    generic_delete(remove_node); 
} 

std::size_t size() const 
{
    std::size_t len = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        len += 1; 

    return len; 
} 

bool empty() const 
{
    return head_node->prev==head_node && head_node->next==head_node; 
} 

void show(const char* msg) const 
{
    if(msg) 
        std::cout << msg << std::endl; 

    std::cout << "[START]<->"; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        std::cout << "[" << run->data << "]<->"; 

    std::cout << "[END]" << std::endl; 
} 

list* concat(list* other) const 
{
    list* concated_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        concated_list->insert_end(run->data); 

    for(node* run = other->head_node->next; run != other->head_node; run = run->next) 
        concated_list->insert_end(run->data); 

    return (concated_list); 
} 

list* merge(list* other) const 
{
    list* merged_list = 0; 
    node* run1 = 0; 
    node* run2 = 0; 
    int data; 

    merged_list = new list(); 
    run1 = head_node->next; 
    run2 = other->head_node->next; 
    while(true) 
    {
        if(run1 == head_node) 
        {
            while(run2 != other->head_node) 
            {
                merged_list->insert_end(run1->data); 
                run1 = run1->next; 
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

        if(run1->data < run2->data) 
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

    return merged_list; 
} 

void append(list* other) 
{
    if(!other->empty()) 
    {
        head_node->prev->next = other->head_node->next; 
        other->head_node->next->prev = head_node->prev; 
        
        head_node->prev = other->head_node->prev; 
        other->head_node->prev->next = head_node; 
    } 

    delete other; 
} 

list* to_list(int* p_array, std::size_t N) 
{
    list* list_from_array = new list; 

    for(std::size_t i = 0; i < N; ++i) 
        list_from_array->insert_end(p_array[i]; 

    return list_from_array; 
} 

void to_array(int** pp_array, std::size_t* pN) const 
{
    int* p_array = 0; 
    std::size_t N = 0; 
    std::size_t list_length = 0; 

    list_length = size(); 
    if(list_length == 0) 
    {
        *pp_array = 0; 
        *pN = 0; 
        return; 
    } 

    p_array = new int[list_length]; 
    N = list_length; 

    ssize_t i = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        p_array[i++] = run->data; 

    *pp_array = p_array; 
    *pN = N; 
} 

list* get_reversed_list() const 
{
    list* reversed_list = 0; 

    reversed_list = new list; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        reversed_list->insert_start(run->data); 

    return reversed_list; 
} 

void reverse() 
{
    node* original_first = 0; 
    node* run_next = 0; 

    if(head_node->next == head_node || head_node->next->next == head_node) 
        return; 

    original_first = head_node->next; 
    for(node* run = head_node->next->next; run != head_node; run = run_next) 
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

list::iterator list::begin() 
{
    return list::iterator(head_node->next); 
} 

list::iterator list::end() 
{
    return list::iterator(head_node->prev); 
}

// iterator member functions 
list::iterator list::iterator::iterator(node* _p_node) : p_node(_p_node) 
{

} 

list::iterator list::iterator::operator++() 
{
    p_node = p_node->next; 
    return *this; 
} 

list::iterator list::iterator::opeator--() 
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

int list::iterator::operator==(const iterator& other) const 
{
    return p_node == other.p_node; 
} 

int list::iterator::operator!=(const iterator& other) const 
{
    return p_node != other.p_node; 
} 

// private member functions 
void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{
    p_mid->prev = p_start; 
    p_mid->next = p_end; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
} 

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
    p_delete_node = 0; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run != head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 

#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

node::node(int new_data) : data(new_data), prev(0), next(0) 
{

} 

list::list() 
{
    head_node = new node(0); 
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::~list() 
{
    node* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next) 
    {
        run_next = run->next; 
        delete run; 
    } 

    delete head_node; 
    head_node = 0; 
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
    
    existing_node = search_node(existing_data); 
    if(0 == existing_data) 
        throw list_data_not_found("list::insert_after(): list data not found"); 

    generic_insert(existing_node, new node(new_data), existing_node->next); 
} 

void list::insert_before(int existing_data, int new_data) 
{
    node* existing_node = 0; 

    existing_node = search_node(existing_data); 
    if(0 == existing_data) 
        throw list_data_not_found("list::insert_before():list data not found"); 

    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void list::get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list::get_start(): list is empty"); 
    
    *p_start_data = head_node->next->data; 
} 

void list::get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_end_data = head_node->prev->data; 
} 

void list::pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_start_data = head_node->next->data; 
    generic_delete(head_node->next); 
} 

void list::pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_end_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
} 

void list::remove_start() 
{
    if(empty()) 
        throw list_empty("list empty"); 
    generic_delete(head_node->next); 
} 

void list::remove_end() 
{
    if(empty()) 
        throw list_empty("list empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_data(int r_data) 
{ 
    node* remove_node = 0; 

    remove_node = search_node(r_data); 
    if(0 == remove_node) 
        throw list_data_not_found("invalid remove data"); 

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
    return head_node->next==head_node && head_node->prev==head_node; 
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

    for(node* run = other->head_node->next; run != other->head_node; run = run->next) 
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

    delete other; 
} 

list* merge(list* other) 
{
    list* merged_list = new list; 
    node* run1 = head_node->next; 
    node* run2 = other->head_node->next; 
    int data; 

    while(true) 
    {
        if(run1 == 0) 
        {
            while(run2 != 0) 
            {
                merged_list->insert_end(run2->data); 
                run2 = run2->next; 
            } 
            break; 
        } 

        if(run2 == 0) 
        {
            while(run1 != 0) 
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

    return merged_list; 
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
    std:size_t N = size(); 
    *pN = N; 

    if(N == 0)
    {
        *pp_array = 0; 
        return; 
    } 

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
    if(! (head_node->next==head_node || head_node->next->next==head_node)) 
    {
        node* original_first = head_node->next; 

        node* run_next = 0; 
        for(node* run = original_first->next; run != head_node; run = run->next) 
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

// iterator member functions 
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

list::iterator list::iterator::iterator++(int) 
{
    iterator iter(p_node); 
    p_node = p_node->next; 
    return iter; 
} 

list::iterator list::iterator::iterator--(int) 
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

// private member function 
void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{
    p_mid->prev = p_start; 
    p_mid->next = p_end; 
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

#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

#include <iostream> 

#include "list_exceptions.hpp" 
#include "list.hpp" 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

node::node(int _data) : data(_data), prev(0), next(0) 
{

} 

list::list() 
{
    head_node = new node(0); 
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::list() 
{
    head_node = new node(); 
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::list() 
{
    head_node = new node(); 
    head_node->next = head_node; 
    head_node->prev = head_node; 
} 

list::list() 
{
    head_node = new node(); 
    head_node->next = head_node; 
    head_node->prev = head_node; 
} 

list::list() 
{
    head_node = new node(); 
    head_node->next = head_node; 
    head_node->prev = head_node; 
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

void list::insert_start(int new_data) 
{
    generic_insert(head_node, new node(new_data), head_node->next); 
} 

void list::insert_start(int new_data) 
{
    generic_insert(head_node, new node(new_data), head_node->next); 
} 

void list::insert_end(int new_data) 
{
    generic_insert(head_node->prev, new node(new_data), head_node); 
} 

void list::insert_end(int new_data) 
{
    generic_insert(head_node->prev, new node(new_data), head_node); 
} 

void list::insert_end(int new_data) 
{
    generic_insert(head_node->prev, new node(new_data), head_node); 
} 

void list::insert_after(int existing_data, int new_data) 
{
    node* existing_node = this->search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 

    generic_insert(existing_node, new node(new_data), existing_node->next); 
}   

void list::insert_after(int existing_data, int new_data) 
{
    node* existing_node = this->search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 

    generic_insert(existing_node, new node(new_data), existing_node->next); 
} 

void list::insert_after(int existing_data, int new_data) 
{
    node* existing_node = this->search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 

    generic_insert(existing_data, new node(new_data), existing_data->next); 
} 

void list::insert_before(int existing_data, int new_data) 
{
    node* existing_node = search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 
    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void list::insert_before(int existing_data, int new_data) 
{
    node* existing_node = search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 
    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void list::insert_before(int existing_data, int new_data) 
{
    node* existing_node = search_node(existing_data); 
    if(existing_node == 0) 
        throw list_data_not_found("invalid existing data"); 
    generic_insert(existing_node->prev, new node(new_data), existing_node); 
} 

void list::get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("empty list"); 
    *p_start_data = head_node->next->data;  
} 

void list::get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_start_data = head_node->data; 
}

void list::get_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_start_data = head_node->data; 
} 

void list::get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_end_data = head_node->prev->data; 
} 

void list::get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_end_data = head_node->prev->data; 
} 

void list::get_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    *p_end_data = head_node->prev->data;  
} 

void list::pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::pop_start(int* p_start_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::pop_end(int* p_end_data) 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_start() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::remove_start() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::remove_start() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->next); 
} 

void list::remove_end() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_end() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_end() 
{
    if(empty()) 
        throw list_empty("list is empty"); 
    generic_delete(head_node->prev); 
} 

void list::remove_data(int r_data) 
{
    node* r_node = search_node(r_data); 
    if(r_node == 0) 
        throw list_data_not_found("invalid remove data"); 
    generic_delete(r_node); 
} 

void list::remove_data(int r_data) 
{
    node* r_node = search_node(r_data); 
    if(r_node == 0) 
        throw list_data_not_found("invalid remove data"); 
    generic_delete(r_node); 
} 

void list::remove_data(int r_data) 
{
    node* r_node == search_node(r_data); 
    if(r_node == 0) 
        throw list_data_not_found("invalid remove data"); 
    generic_delete(r_node); 
} 

std::size_t list::size() const 
{
    std::size_t N = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        ++N; 

    return N; 
} 

std::size_t list::size() const 
{
    std::size_t N = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        ++N; 

    return N; 
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
    return head_node->next==head_node && head_node->prev==head_node; 
} 

bool list::empty() const 
{
    return head_node->next==head_node && head_node->prev==head_node; 
} 

bool list::empty() const 
{
    return head_node->prev==head_node && head_node->next==head_node; 
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
    list* cncatenated_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 

    for(node* run = other->head_node->next; run != other->head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 

    return (concatenated_list); 
} 

list* list::concat(list* other) const 
{
    list* concatenated_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 

    for(node* run = other->head_node->next; run != other->head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 

    return (concatenated_list); 
} 

list* list::concat(list* other) const 
{
    list* concatenated_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 
    
    for(node* run = other->head_node->next; run != other->head_node; run = run->next) 
        concatenated_list->insert_end(run->data); 

    return (concatenated_list); 
} 

void append(list* other) 
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

void append(list* other) 
{
    if(!other->empty()) 
    {
        head_node->prev->next = other->head_node->next; 
        other->head_node->next->prev = head_node->prev; 

        head_node->prev = other->head_node->prev; 
        other->head_node->prev->next = head_node; 
    } 

    delete other; 
} 

void append(list* other) 
{
    if(!other->empty()) 
    {
        head_node->prev->next = other->head_node->next; 
        other->head_node->next->prev = head_node->prev; 

        head_node->prev = other->head_node->prev; 
        other->head_node->prev->next = head_node; 
    } 

    delete other; 
} 

list* merge(list* other) const 
{
    list* merged_list = 0; 
    node* run1 = 0; 
    node* run2 = 0; 
    int data; 

    merged_list = new list; 
    run1 = head_node->next;
    run2 = other->head_node->next; 

    while(true) 
    {
        if(run1 == head_node) 
        {
            while(run != other->head_nde) 
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

    return merged_list; 
} 

list* merge(list* other) const 
{
    list* merged_list = 0; 
    node* run1 = 0; 
    node* run2 = 0; 
    int data; 

    merged_list = new list; 
    run1 = head_node->next; 
    run2 = other->head_node->next; 

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
            while(run1 = head_node) 
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

    return merged_list; 
} 

list* merge(list* other) const 
{
    list* merged_list = 0; 
    node* run1 = 0; 
    node* run2 = 0; 
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

    return merged_list; 
} 

list* list::to_list(int* p_array, std::size_t N) 
{
    list* list_from_array = new list; 

    for(std::size_t i = 0; i < N; ++i) 
        list_from_array->insert_end(p_array[i]); 

    return list_from_array; 
} 

list* list::to_list(int* p_array, std::size_t N) 
{
    list* list_from_array = new list; 

    for(std::size_t i = 0; i < N; ++i) 
        list_from_array->insert_end(p_array[i]); 

    return list_from_array; 
} 

list* list::to_list(int* p_array, std::size_t N) 
{
    list* list_from_array = new list; 

    for(std::size_t i = 0; i < N; ++i) 
        list_from_array->insert_end(p_array[i]); 

    return list_from_empty; 
} 

void to_array(int** pp_array, std::size_t* pN) 
{
    std::size_t N = size(); 
    *pN = N; 

    if(N == 0) 
    {
        *pp_array = 0; 
        return; 
    } 

    int* p_array = new int[N]; 

    std::size_t i = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        p_array[i++] = run->data; 

    *pp_array = p_array; 
} 

void to_array(int** pp_array, std::size_t* pN) 
{
    std::size_t N = size(); 
    *pN = N; 

    if(N == 0) 
    {
        *pp_array = 0; 
        return; 
    } 

    int* p_array = new int[N]; 

    std::size_t i = 0; 
    for(node* run = head_node->next; run != head_node; run = run->next) 
        p_array[i++] = run->data; 

    *pp_array = p_array; 
} 

void to_array(int** pp_array, std::size_t* pN) 
{
    std::size_t N = size(); 
    *pN = N; 

    if(N == 0) 
    {
        *pp_array = 0; 
        return; 
    } 

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
        reversed_list->inert_start(run->data); 

    return reversed_list; 
} 

list* list::get_reversed_list() const 
{
    list* reversed_list = new list; 

    for(node* run = head_node->next; run != head_node; run = run->next) 
        reversed_list->insert_start(run->data); 

    return reversed_list; 
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
    if(! (head_node->next==head_node || head_node->next->next==head_node)) 
    {
        node* original_first = 0; 
        node* run_next = 0; 

        original_first = head_node->next; 
        for(node* run = head_node->next->next; run != head_node; run = run_next) 
        {
            run_next = run->next; 

            run->next = head_node->next; 
            run->prev = head_node; 
            head_node->next->prev = head_node; 
            head_node->next = run; 
        } 

        original_first->next = head_node; 
        head_node->prev = original_first; 
    } 
} 

void list::reverse() 
{
    if(! (head_node->next==head_node || head_node->next->next==head_node)) 
    {
        node* original_first = 0; 
        node* run_next = 0; 

        original_first = head_node->next; 
        for(node* run = head_node->next->next; run != head_node; run = run_next) 
        {
            run_next = run->next; 

            run->next = head_node->next; 
            run->prev = head_node; 
            head_node->next->prev = head_node; 
            head_Node->next = run; 
        } 

        original_first->next = head_node; 
        head_node->prev = original_first; 
    } 
} 

void list::reverse() 
{
    if(! (head_node->next==head_node || head_node->next->next==head_node)) 
    {
        node* original_first = 0; 
        node* run_next = 0; 

        original_first = head_node->next; 
        for(node* run = head_node->next->next; run != head_node; run = run->next) 
        {
            run_next = run->next; 

            run->next = head_node->next; 
            run->prev = head_node; 
            head_node->next->prev = head_node; 
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

list::iteraor list::begin() 
{
    return list::iteraor(head_node->next); 
} 

list::iterator list::begin() 
{
    return list::iterator(head_node->next); 
} 

list::iterator list::end() 
{
    return list::iterator(head_node); 
} 

list::iterator list::end() 
{
    return list::iterator(head_node); 
} 

list::iterator list::end() 
{
    return list::iterator(head_node); 
} 

// iterator member functions 
list::iterator::iterator(node* _p_node) : p_node(_p_node) 
{

} 

list::iterator::iterator(node* _p_node) : p_node(_p_node) 
{

} 

list::iterator::iterator(node* _p_node) : p_node(_p_node) 
{

} 

list::iteraor list::iterator::operator++() 
{
    p_node = p_node->next; 
    return *this; 
} 

list::iteraor list::iterator::operator++() 
{
    p_node = p_node->next; 
    return *this; 
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

list::iterator list::iterator::operator--() 
{
    p_node = p_node->prev; 
    return *this; 
} 

list::iterator list::iterator::operator--() 
{
    p_node = p_node->prev; 
    return *this; 
} 

list::iterator list::iterator::operator++(int) 
{
    list::iterator iter(p_node); 
    p_node = p_node->next; 
    return iter; 
} 

list::iterator list::iterator::operator++(int) 
{
    list::iterator iter(p_node); 
    p_node = p_node->next; 
    return iter; 
} 

list::iterator list::iterator::operator++(int) 
{
    list::iterator iter(p_node); 
    p_node = p_node->next; 
    return iter; 
} 

list::iterator list::iterator::operator--(int) 
{
    list::iterator iter(p_node); 
    p_node = p_node->prev; 
    return iter; 
} 

list::iterator list::iterator::operator--(int) 
{
    list::iterator iter(p_node); 
    p_node = p_node->prev; 
    return iter; 
} 

list::iterator list::iterator::operator--(int) 
{ 
    list::iterator iter(p_node); 
    p_node = p_node->prev; 
    return iter; 
} 

int list::iterator::operator*() const 
{
    return p_node->data; 
} 

int list::iterator::operator*() const 
{
    return p_node->data; 
} 

int list::iterator::operator*() const 
{
    return p_node->data; 
} 

bool list::iterator::operator==(const iterator& other) const 
{
    return p_node == other.p_node; 
} 

bool list::iterator::operator==(const iterator& other) const 
{
    return p_node == other.p_node; 
} 

bool list::iterator::operator==(const iterator& other) const 
{
    return p_node == other.p_node; 
} 

bool list::iterator::operator!=(const iterator& other) const 
{
    return p_node != other.p_node; 
} 

bool list::iterator::operator!=(const iterator& other) const 
{
    return p_node != other.p_node; 
} 

bool list::iterator::operator!=(const iterator& other) const 
{
    return p_node != other.p_node; 
} 

// private member functions 
void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{
    p_mid->prev = p_start; 
    p_mid->next = p_end; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
} 

void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{
    p_mid->prev = p_start; 
    p_mid->next = p_end; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
} 

void list::generic_insert(node* p_start, node* p_mid, node* p_end) 
{
    p_mid->prev = p_start; 
    p_mid->next = p_end; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
} 

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
} 

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
} 

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delte_node; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run != head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run != head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run != head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 

node* list::search_node(int search_data) 
{
    for(node* run = head_node->next; run = head_node; run = run->next) 
        if(run->data == search_data) 
            return run; 
    return 0; 
} 


