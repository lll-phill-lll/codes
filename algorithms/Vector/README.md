# Description

Std::vector is a standart container, similar to usual array, but with some features. The goal is to
implement this container with basic functions. Realization for int. 

# About:

My vector has 2 connected fields: size and capacity, in general capacity is twice larger then size, 
it's made to keep complexity O(1)of push and pop operations. In case of memory shortage to insert 
element capacity is doubled, to make reallocation as rarely as possible, because it requires O(n).

Regular int arrays is used as a storage.

