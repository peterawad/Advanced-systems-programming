#include <iostream>
#include <cstring>
#include <memory>
#include "bump.hpp"
#include <thread>
#include "simpletest.hpp"
using namespace std;
void alloc_test(int ptr)
{
	using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
bump b;
	auto t1 = high_resolution_clock::now();

    size_t ptr1 = b.alloc(ptr);
    if(ptr1 == 0)
        cout<<"Failed to allocate!!!!"<<endl;
    else 
        cout<<"allocate done "<<endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << " ms\n";
}
int main()
{    
    bump b;
    b.init_bump(10,20);
    alloc_test(10);
    alloc_test(10);
    alloc_test(10);
    return 0;
}
