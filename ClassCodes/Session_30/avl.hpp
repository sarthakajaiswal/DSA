/*
    @GOAL:      header file for AVL tree using templates in CPP  
    @DATE:      14 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <iostream> 

namespace cpa 
{
    namespace dsa 
    {
        template <typename KeyType, typename ValueType> 
        class avl_node 
        {
            template <typename KeyType, typename ValueType> 
            friend class cpa_map<KeyType, ValueType> 

            private: 
                KeyType const& keyObject; 
                ValueType& valueObject; 
                avl_node* left; 
                avl_node* right; 
                avl_node* parent; 
                avl_node(KeyType const& _keyObject, ValueType& _valueObject) : keyObject(keyObject), 
                                                                        valueObject(_valueObject), 
                                                                        left(nullptr), 
                                                                        right(nullptr), 
                                                                        parent(nullptr) 
                {

                } 
        }; 

        template <typename KeyType, typename ValueType> 
        class cpa_map 
        {
            private: 
                avl_node<KeyType, ValueType>* root_node; 
                size_t numberOfElements; 

                void left_rotate(avl_node<KeyType, ValueType>* z); 
                void right_rotate(avl_node<KeyType, ValueType>* z); 

            public: 
                cpa_map() 
                {

                } 

                ~cpa_map() 
                {

                } 

                void insert(KeyType const& key, ValueType& value) 
                {

                } 

                ValueType& get(KeyType const& key) 
                {

                } 
        }; 
    } 
} 

void test(void) 
{
    cpa::dsa::cpa_map<size_t, float> myMap; 
} 

