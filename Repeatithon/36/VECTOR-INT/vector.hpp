#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        int get_value_at_index(size_t index); 
        void set_value_at_index(size_t index, int new_value); 

        size_t size(); 
}; 

#endif // VECTOR_HPP 

//============ 
#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector
{
    private: 
        int* p_array; 
        size_t nr_elements; 

    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        int get_value_at_index(size_t index); 
        void set_value_at_index(size_t index, int value); 
        size_t size(); 
}; 

#endif // DATE_HPP 

// =========== 
#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    private: 
        int* p_array; 
        size_t nr_elements;
        
    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        int get_value_at_index(size_t index); 
        void set_value_at_index(size_t index, int value); 
        size_t size(); 
}; 

#endif // VECTOR_HPP 


// =============== 
#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    private: 
        int* p_array; 
        size_t nr_elements; 

    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        void set_value_at_index(size_t index, int new_data); 
        int get_value_at_index(size_t index); 
        size_t size(); 
}; 

#endif // VECTOR_HPP 

// =============== 
#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    private: 
        int* p_array; 
        size_t nr_elements; 

    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        void set_value_at_index(size_t index, int new_data); 
        int get_value_at_index(size_t index); 
        size_t size(); 
}; 

#endif // VECTOR_HPP 

// ========== 
#ifndef VECTOR_HPP 
#define VECTOR_HPP 

class vector 
{
    private: 
        int* p_array; 
        size_t size; 

    public: 
        vector(); 
        ~vector(); 

        void push_back(int new_data); 

        void set_value_at_index(size_t index, int new_data); 
        int get_value_at_index(size_t index); 
        size_t size(); 
}; 

#endif // VECTOR_HPP 

