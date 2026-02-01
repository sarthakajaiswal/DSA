#ifndef VECTOR_HPP 
#define VECTOR_HPP 

#include <iostream> 

class vector 
{
    private: 
        int* p_array; 
        size_t nr_elements; 

    public: 
        vector();   // constructor 
        ~vector();  // destructor 

        void push_back(int new_data); 
        
        int get_value_at_index(size_t index); 
        void set_value_at_index(size_t index, int value); 

        size_t size(); 
}; 

#endif // VECTOR_HPP 

