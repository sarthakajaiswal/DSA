#ifndef DATE_HPP 
#define DATE_HPP 

class vector
{
    private: 
        int* p_array; 
        size_t nr_elements; 

    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_value); 

        int get_value_at_index(size_t index); 
        void set_value_at_index(size_t index, int new_value); 

        size_t size(); 
}; 

#endif // DATE_HPP 

