# Binary tree (not balanced)

Problem statement:
-----------------
Make a class of binary search tree with unique values, which supports operations:
- add new node, print sorted tree - value __ number of repeats, 
- print leafs in the ascending order, 
- print crosses (nodes which have 2 sucessors) in ascending order, 
- print branches (nodes, which have 1 seccessor) in ascending order, 
- print max depth of tree,
- print if tree is AVL balanced (for every vertex in tree depth of it's subtrees varies by 1).

Realisation:
------------

There are two classes class Node and class, which consists of elements of Nodes class. Each node has
it's value and pointers for two children nodes. For each new vertex memory is allocated using "new" function.

Input data:
----------
Sequence of int values with 0 in the end. (0 is not the part of tree).

Output data:
------------

- sorted array of input values, 
- ...
The same as in Problem statement.

Example:
----------
Input:

7 3 2 1 9 5 4 6 2 8 0

Output:

1 1

2 2

3 1

4 1

5 1

6 1

7 1

8 1

9 1

---

1

4

6

8

---

3

5

7

---

2

9

---

4

---

YES


