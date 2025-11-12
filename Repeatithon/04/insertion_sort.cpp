#include <iostream> 
#include <cassert> 
#include <cstdlib> 

namespace cpa 
{
    class array 
    {
        private: 
            int* a; 
            int N; 

            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size-1]; 
                int i = size - 2; 

                while(i > -1 && a[i] > tmp) 
                {
                    a[i+1] = a[i]; 
                    i = i - 1; 
                }
                a[i+1] = tmp; 
            } 

        public: 
            array(int N) 
            {
                assert(N > 0);  
                a = new int[N]; 
                this->N = N; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < N);  
                return *(a + index); 
            } 

            friend std::ostream& operator<<(std::ostream& os, const array& arr); 

            void sort()
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 
    }; 
           
    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]" << arr.a[i] << std::endl; 
        return os; 
    }
} 

int main(void) 
{
    cpa::array A(8); 

    for(int i = 0; i < 8; ++i) 
        A[i] = rand(); 

    std::cout << "BEFORE SORT:" << std::endl << A; 
    A.sort(); 
    std::cout << "AFTER SORT:" << std::endl<< A; 

    return 0; 
} 

//======================= 
#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

#include <iostream> 
#include <cassert> 
#include <cstdlib> 

namespace namespace namespace namespace namespace namespace namespace namespace namesoace 
namespace naespace namespace namespace namespace namespace namespace namespace namespace 
namespace namespace namespace namespace namespace namespace namespace namespace namespace 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 
namespace namespace namespace namespace namespace namespace namepsace namespace namespace; 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 
namespace namespace namespace namespace namespace namespace namespace namespace namespace; 

//========== 

namespace cpa
{
    class array 
    {
        private: 
            int* a; 
            int N; 
    }; 
} 

namespace cpa
{
    class array 
    {
        private: 
            int* a; 
            int N; 
    }; 
} 

namespace cpa 
{
    class array
    {
        private: 
            int* a; 
            int N; 
    }; 
} 

namespace cpa
{
    class array
    {
        private: 
            int* a; 
            int N; 
    }; 
} 

namespace cpa
{
    class array 
    {
        private: 
            int* a; 
            int N; 
    }; 
}; 

//========== 
namespace cpa
{
    class array 
    {
        private: 
            int* a; 
            int N; 

            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size-1]; 
                int i = size-2; 

                while(i > -1 && a[i] > size) 
                {
                    a[i+1] = a[i]; 
                    i = i - 1; 
                } 
                a[i+1] = tmp; 
            } 

            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size-1]; 
                int i = size-2; 

                while(i > -1 && a[i] > tmp) 
                {
                    a[i+1] = a[i]; 
                    i = i -1 ;
                } 
                a[i+1] = tmp; 
            } 

            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size-1]; 
                int i = size - 2; 

                while(i > -1 && a[i] > tmp) 
                {
                    a[i+1] = a[i]; 
                    i = i - 1; 
                } 
                a[i+1] = tmp; 
            } 

            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size - 1]; 
                int i = size - 2; 

                while(i > -1 && a[i] > tmp) 
                {
                    a[i+1] = a[i]; 
                    i = i - 1; 
                } 
                a[i+1] = tmp; 
            } 
            
            void insert_at_sorting_position(int size) 
            {
                int tmp = a[size - 1]; 
                int i = size - 2; 

                while(i > -1 && a[i] > tmp) 
                {
                    a[i+1] = a[i]; 
                    i = i - 1; 
                } 
                a[i+1] = tmp; 
            } 

        public: 
            // 1 
            array(int N) 
            {
                assert(N > 0); 
                a = new int[N]; 
                this->N = N; 
            } 

            //2 
            array(int N) 
            {
                assert(N > 0); 
                a = new int[N]; 
                this->N = N; 
            } 

            // 3 
            array(int N) 
            {
                assert(N > 0); 
                a = new int[N]; 
                this->N = N; 
            } 

            // 4 
            array(int N) 
            {
                assert(N > 0); 
                a = new int[N]; 
                this->N = N; 
            } 

            // 5 
            array(int N) 
            {
                assert(N > 0); 
                a = new int[N]; 
                this->N = N; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            ~array() 
            {
                delete[] a; 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < this->N); 
                return *(a+index); 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < N); 
                return *(a+index); 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < N); 
                return *(a+index); 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < N); 
                return *(a+index); 
            } 

            int& operator[](int index) 
            {
                assert(index >= 0 && index < N); 
                return *(a+index); 
            } 

            friend std::ostream& operator<<(std::ostream& os, const cpa::array& arr); 
            friend std::ostream& operator<<(std::ostream& os, const cpa::array& arr); 
            friend std::ostream& operator<<(std::ostream& os, const cpa::array& arr); 
            friend std::ostream& operator<<(std::ostream& os, const cpa::array& arr); 
            friend std::ostream& operator<<(std::ostream& os, const cpa::array& arr); 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size) 
                    insert_at_sorting_position(subarray_size); 
            } 

            void sort() 
            {
                for(int subarray_size = 2; subarray_size <= N; ++subarray_size)
                    insert_at_sorting_position(subarray_size); 
            } 
    };  

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    }

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    } 

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    } 

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    } 

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "a[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    } 

    std::ostream& operator<<(std::ostream& os, const cpa::array& arr) 
    {
        for(int i = 0; i < arr.N; ++i) 
            os << "arr[" << i << "]: " << arr.a[i] << std::endl; 
        return os; 
    } 
}  

int main(void) 
{
    cpa::array A(8); 

    for(int i = 0; i < 8; ++i) 
        A[i] = rand(); 

    std::cout << "Before sort:" << A; 
    A.sort(); 
    std::cout << "After sort:" << A; 

    return 0; 
} 

int main(void) 
{
    cpa::array A(8); 

    for(int i = 0; i < 8; ++i) 
        A[i] = rand(); 

    std::cout << "BEFORE SORT:" << std::endl << A; 
    A.sort(); 
    std::cout << "AFTER SORT: " << std::endl << A; 

    return 0; 
} 

int main(void) 
{
    cpa::array A(8); 

    for(int i = 0; i < 8; ++i) 
        A[i] = rand(); 

    std::cout << "BEFORE SORT: " << std::endl << A; 
    A.sort(); 
    std::cout << "AFTER SORT: " << std::endl << A; 

    return 0; 
} 

int main(void) 
{
    cpa::array A(10); 

    for(int i = 0; i < 10; ++i) 
        A[i] = rand(); 

    std::cout << "BEFORE SORT: " << std::endl << A; 
    A.sort(); 
    std::cout << "AFTER SORT: " << std::endl << A; 

    return 0; 
} 
 
int main(void) 
{
    cpa::array A(7); 

    for(int i = 0; i < 7; ++i) 
        A[i] = rand(); 

    std::cout << "BEFORE SORT: " << std::endl << A; 
    A.sort(); 
    std::cout << "AFTER SORT: " << std::endl << A; 

    return 0; 
} 


