#include <stdlib.h>
using namespace std;

class bump 
{
    struct bumballocator
    {
       size_t start;
       size_t end;
       size_t next;
       size_t allocations;
    };
    public:
    bump()
    {
        bumballocator b;
        b.allocations=0;
        b.end=0;
        b.next=0;
        b.allocations =0;
    }
        
    void init_bump(size_t start, size_t size)   
    {
        bumballocator b;
        b.start=start;
        b.end=start + size;
        b.next=start;        
    }
  
    size_t alloc(size_t layout)
    {
        bumballocator b;
        size_t alloc_start=b.next;
        b.next =alloc_start + layout;
        b.allocations+=1;
        if(alloc_start< b.end)
        {
            b.next=0;
            dealloc(layout);
        }
        else 
        {
            b.next=b.end; 
            b.allocations+=1;
        }
         return b.next;
    }
    
    u_int8_t dealloc(size_t layout)
    {
        bumballocator b;
        b.allocations -=1;
        if(b.allocations==0)
        {
            b.next =b.start;
        }
        return b.next;
    }
};
