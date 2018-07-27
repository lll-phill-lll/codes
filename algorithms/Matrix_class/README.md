# class Matrix

Problem statement:
-----------------
Write template matrix class.

Implementation:
---------------
Basic container is std::vector. Options and operations class supports:
- exception handling, 
- operator "+" for two matrices,
- operator "+=" for matrices, 
- operators "*" and "*=" for matrices,
- operator "(i, j)", returns value is i, j element of matrix (const and non const),
- operator "*" and "*=", for scalar element of other template, 
- method "transpose", which transposes "this" matrix and changes it,
- method "transposed", which is const, it returns transposed matrix, 
- also class objects are printable with std::cout, operator "<<" difined.

Future improvements:
-------------------
Add function to solve linear equations, and singular decomposition.
