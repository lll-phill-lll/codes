# Custom hash table

Problem statement:
-----------------

Implement custom hash table as class with compexity of search, insert and delete O(1). It has to support rehash and avoid collisions.

Realisation:
-------------

As basic container I use vector of lists, but the size of lists is limited to 5 elements.  As hash function I've chosen  simple mod function, that's why arrays consisting of identical numbers are the cause of collisions, but with random numbers it works ok.
 
To maintain complexity resize function doubles the size of vector. To avoid waste of memory too empty table causes rehash and truncation of size. Also too filled table leads to the similar effect. 

Conclusion:
--------------
Such hash function has some problems with identical numbers or with the same mod result. So it's better to use finctions like family of universal hash, kind of:

h(x) = ((ax + b) mod p)mod m, with prime p and random nonzero a, b, which guarantee the probability of hashing 2 different elements to the same key < 2/m.
