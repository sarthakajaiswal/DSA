#include <iostream> 

class Test 
{
    private: 
        int a; 
        char b; 
        float c; 

    public: 
        Test() 
        {
            this->a = 100; 
            this->b = 'a'; 
            this->c = 1.1f; 
        } 

        void show() 
        {
            std::cout << "this->a: " << this->a << std::endl 
                        << "this->b: " << this->b << std::endl  
                        << "this->c: " << this->c << std::endl; 
        } 

        static void someFunction(float x, float y) 
        {
            int num = 100; 

            std::cout << "x:" << x << std::endl 
                        << "y:" << y << std::endl 
                        << "num:" << num << std::endl; 
        } 
}; 

void test(); 

int main() 
{
    test(); 
    return 0; 
} 

void test(void) 
{
    Test t1, t2; 

    t1.show(); 
    t2.show(); 

    Test::someFunction(100.01, 300.03); 
    t1.someFunction(1.1, 2.2); 
    t2.someFunction(500.5, 600.6);     
} 

