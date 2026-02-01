#include "vector.hpp" 

void test_vector(void); 

int main(void) 
{
    test_vector();
    std::cout << "main():Program exited succesfully" << std::endl; 
    return EXIT_SUCCESS; 
} 

void test_vector(void) 
{
    vector* pVec = new vector; 

    pVec->push_back(100); 
    pVec->push_back(200); 
    pVec->push_back(300); 
    pVec->push_back(400); 
    pVec->push_back(500); 

    std::cout << "pVec->size() : " << pVec->size() << std::endl; 

    for(int i = 0; i < pVec->size(); ++i) 
    {
        int current_value = pVec->get_value_at_index(i); 
        std::cout << "value at index" << i << " = " << current_value << std::endl; 
    } 

    std::cout << "Setting value at each index to (index + 1) * 10" << std::endl; 
    for(int i = 0; i < pVec->size(); ++i) 
        pVec->set_value_at_index(i, (i+1) * 10); 

    std::cout << "Showing the values after setting" << std::endl; 
    for(int i = 0; i < pVec->size(); ++i) 
    {
        int current_value = pVec->get_value_at_index(i); 
        std::cout << "value at index " << i << " = " << current_value << std::endl; 
    } 

    std::cout << "Delete vector" << std::endl; 
    delete pVec; 
    pVec = 0; 
} 
