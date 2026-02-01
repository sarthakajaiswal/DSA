#include "vector.hpp" 

vector::vector() 
{
    this->p_array = 0; 
    this->nr_elements = 0; 
} 

vector::~vector() 
{
    if(p_array) 
    {
        free(p_array); 
        p_array = 0; 
    } 
} 

void vector::push_back(int new_data) 
{
    this->p_array = (int*)realloc(this->p_array, (this->nr_elements+1) * sizeof(int)); 
    if(0 == this->p_array) 
    {
        std::cerr << "vector::push_back() > Error in allocating memory" << std::endl; 
        exit(EXIT_FAILURE); 
    } 
    this->nr_elements += 1; 

    this->p_array[this->nr_elements - 1] = new_data; 
} 

int vector::get_value_at_index(size_t index) 
{
    if(index > this->nr_elements || index < 0) 
    {
        std::cerr << "vector::get_value_at_Index(): index out of range" << std::endl; 
        exit(EXIT_FAILURE); 
    }
    return this->p_array[index]; 
} 

void vector::set_value_at_index(size_t index, int value) 
{
    if(index > this->nr_elements || index < 0) 
    {
        std::cerr << "vector::set_value_at_index(): index out of range" << std::endl; 
        exit(EXIT_FAILURE); 
    } 
    this->p_array[index] = value; 
} 

size_t vector::size() 
{
    return this->nr_elements; 
} 

