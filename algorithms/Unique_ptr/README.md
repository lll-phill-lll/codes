#Unique ptr implementation

# Description:
Unique ptr is smart pointer. The main difference between it and regular pointer are additional functions
such as preventing copying of its contained pointer. These features are intended to reduce bugs caused 
by the misuse of pointers, while retaining efficiency.

#Solution 
There is my implementation of template class unique_ptr. This class constructor is based on T\* - pointer
to object and class or function Deleter, which should be used to destrust pointer correctly.


    
