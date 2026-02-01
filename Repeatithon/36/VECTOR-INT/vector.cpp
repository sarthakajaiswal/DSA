#include "vector.hpp" 
#include <iostream> 
#include <cstdlib> 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    is(this->p_array != 0) 
    {
        free(this->p_array); 
        this->p_array = 0; 
    }  
} 

vector::push_back(int new_data) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1)*sizeof(int)); 
    if(0 == p_array) 
    {
        std::cerr << "vector:push_back(): out of memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 
    this->nr_elements = this->nr_elements + 1; 
    this->p_array[this->nr_elements-1] = new_data; 
}

int vector::get_value_at_index(size_t index) 
{
    if(index >= this->nr_elements || index < 0) 
    {
        std::cout << "vector::get_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    return p_array[index]; 
} 

void vector::set_value_at_index(size_t index, int new_data) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cout << "vector::set_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    }

    p_array[index] = new_data; 
} 

void vector::size() 
{
    return this->nr_elements; 
} 

// ============================ 

#include "vector.hpp" 
#include <iostream> 
#include <cstdlib> 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    if(p_array) 
    {
        delete p_array; 
        p_array = 0; 
    } 
} 

void vector::push_back(int new_value) 
{
    p_array = (int*)realloc(this->p_array, (this->nr_elements+1 * sizeof(int))); 
    if(0 == p_array) 
    {
        std::cerr << "vector::push_back() > failed to allocate memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->nr_elements += 1; 
    this->p_array[this->nr_elements-1] = new_value; 
} 

void vector::set_value_at_index(size_t index, int new_value) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::set_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    p_array[index] = new_value; 
} 

int vector::get_value_at_index(size_t index) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::get_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    return p_array[index]; 
} 

int vector::size() 
{
    return this->nr_elements; 
} 

// ===================== 
#include "vector.hpp" 
#include <iostream> 
#include <cstdlib> 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    if(p_array) 
    {
        delete p_array; 
        p_array = 0; 
    } 
} 

void vector::push_back(int new_value) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1 * sizeof(int))); 
    if(0 == this->p_array) 
    {
        std::cerr << "vector::push_back() > failed to allocate memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->nr_elements += 1; 
    this->p_array[this->nr_elements-1] = new_value; 
} 

void vector::set_value_at_index(size_t index, int new_value) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::set_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->p_array[index] = new_value; 
} 

int vector::get_value_at_index(size_t index) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::get_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    return this->p_array[index]; 
} 

size_t size() 
{
    return this->nr_elements; 
} 

// =================== 
#include "vector.hpp" 
#include <iostream> 
#include <cstdlib> 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    if(p_array) 
    {
        delete p_array; 
        p_array = 0; 
    } 
} 

void vector::push_back(int new_value) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1) * sizeof(int)); 
    if(this->p_array == 0) 
    {
        std::cerr << "vector::push_back() > Failed to allocate memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->nr_elements += 1; 
    this->p_arra[this->nr_elements-1] = new_value; 
} 

void vector::set_value_at_index(size_t index, int new_data) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1) * sizeof(int)); 
    if(0 == this->p_array) 
    {
        std::cerr << "vector::set_value_at_index() > index out of bound " << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->p_array[index] = new_value; 
} 

int get_value_at_index(size_t index) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::get_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    return this->p_array[index]; 
} 

size_t size() 
{
    return this->nr_elements; 
} 


// =========== 
#include "vector.hpp" 
#include <iostream> 
#include <cstdio> 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    if(this->p_array) 
    {
        delete this->p_array; 
        this->p_array = 0; 
    } 
} 

void vector::push_back(int new_value) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1)*sizeof(int)); 
    if(0 == this->p_array) 
    {
        std::cerr << "vector::push_back() > failed to allocate memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->nr_elements += 1; 
    this->p_array[this->nr_elements-1] = new_value; 
} 

void vector::set_value_at_index(size_t index, int new_value) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::set_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    this->vector[index] = new_value; 
} 

int vector::get_value_at_index(size_t index) 
{
    if(index < 0 || index >= this->nr_elements) 
    {
        std::cerr << "vector::get_value_at_index() > index out of bound" << std::endl; 
        exit(EXIT_FAILURE); 
    } 

    return this->p_array[index];
} 

size_t size() 
{
    return this->nr_elements; 
} 


