#ifndef _LIST_HPP 
#define _LIST_HPP 

#include <iostream> 
#include <stdexcept> 

namespace cpa 
{
    namespace dsa 
    {
        class list_data_not_found : public std::runtime_error 
        {
            public: 
                list_data_not_found(const char* msg) : std::runtime_error(msg) 
                {} 
        }; 

        class list_empty : public std::runtime_error 
        {
            public: 
                list_empty(const char* msg) : std::runtime_error(msg) 
                {} 
        }; 

        class snode 
        {
            friend class sll; 
            friend class scll; 

            private: 
                int data; 
                snode* next;

                snode(int _data = 0); 
        }; 

        class dnode 
        {
            friend class dll; 
            friend class dcll; 

            private: 
                int data; 
                dnode* prev; 
                dnode* next; 

                dnode(int _data = 0); 
        }; 

        class sll 
        {
            private: 
                snode* head_node; 

            public: 
                sll() : head_node(new snode) 
                {} 

                ~sll() 
                {} 

                void insert_start(int new_data); 
                void insert_end(int new_data); 
                void insert_after(int e_data, int new_data); 
                void insert_before(int e_data, int new_data); 

                void get_start(int* p_data); 
                void get_end(int* p_data); 
                void pop_start(int* p_data); 
                void pop_end(int* p_data); 

                void remove_start(); 
                void remove_end(); 
                void remove_data(int r_data); 

                bool find(int f_data) const; 
                std::size_t len() const; 

                friend std::ostream& operator<<(std::istream& os, const sll& sll_object); 
        }; 

        class dcll 
        {
            private: 
                dnode* head_node; 

                static void generc_insert(dnode*, dnode*, dnode*); 
                static void generic_delete(dnode*); 
                dnode* search_node(int s_data); 

            public: 
                dcll() : head_node(new dnode) 
                {} 

                ~dcll() 
                {
                    // destroy list 
                } 

                void insert_start(int new_data); 
                void insert_end(int new_data); 
                void insert_before(int e_data, int new_data); 
                void insert_after(int e_data, int new_data); 

                void get_start(int* p_data); 
                void get_end(int* p_data); 
                void pop_start(int* p_data); 
                void pop_end(int* p_data); 

                void remove_start(); 
                void remove_end(); 
                void remove_data(int r_data); 

                bool find(int f_data) const; 
                std::size_t len() const; 

                friend std::ostream& operator<<(std::ostream& os, const dcll& dcll_object); 
        }; 
    } 
}; 

#endif /* _LIST_HPP */ 

