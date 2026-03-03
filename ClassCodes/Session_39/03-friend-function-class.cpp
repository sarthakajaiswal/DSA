#include <iostream> 

class Test 
{
    friend void friend_of_test(); 
    friend class FriendClass; 

    private: 
        int num; 
        float f_num; 

    public: 
        Test() 
        {
            this->num = 100; 
            this->f_num = 10.10; 
        }; 
}; 

class FriendClass 
{
    public: 
        void f() 
        {
            Test t1; 
            t1.num = 1000; 
            t1.f_num = 100.100; 
        } 

        void g() 
        {
            Test t2; 
            t2.num = 200; 
            t2.f_num = 200.200; 
        } 

        static void h() 
        {
            Test t3; 
            t3.num = 200; 
            t3.f_num = 1.1; 
        } 
}; 

int main() 
{
    Test myTestObj; 
    
    return 0; 
} 

void friend_of_test() 
{
    Test t; 
    t.num = 500; 
    t.f_num = 100.200; 
} 
