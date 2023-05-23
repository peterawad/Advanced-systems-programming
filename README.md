# Advanced systems programming worksheet2



## bump allocator:(task1)
![bump](/uploads/0b25593ccaedb6085ef1b1fae019a9d2/bump.png)

 - First step: We define the start operation, the end location, next, and allocation in struct bump.
 - Second step: initialize the value equal to zero in the default constructor.
 - third step: the start pointer refers to the start in the bump and the end pointer refer start plus the size of bump and then the next       pointer refer to the start in the beginning.
 - When calling or execute allocate we must take a parameter called layout , and layout, start the allocation in the position of pointer next and change the next by adding layout on the start allocation increasing allocation with one.
 - If the start grater than the end decrements the bump allocation and if equal zero make the pointer next stop on the start.


## testing (task2)
 - We declare object called b to represent the class bump and define pointer(ptr1) that calls allocation and check for pointer or the return value equal zero then is failed to locate else the allocation done.

## timing  (task3)
![test](/uploads/104de3140849a05e94ab40bad169b633/test.jpg)

 - We used the chrono library, properties, high resolution clock, duration, millisecond.
 - To calculate the real time between start and end allocation and get the time in millisecond.
