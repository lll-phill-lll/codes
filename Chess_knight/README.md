# Min path length for chess-knights

Problem statement:
-------------------
There is a chess field with knights coordinates and destination coordinate. The task is to print 
the sum of the minimum lengths of the knights' paths to the target field. length = number of steps.

Solution:
----------

First of all lets pretend that chess-field is a graph, where two vertices are connected, if 
one may be reached from another with a knight step. The idea is to write to all the cells 
minimum path length to the destination point. 
The algorithm for this is similar to Dijkstra: we check all cells around each point to figure out the
best "parent" cell. Then for all the cells we know the distance to the finish.

Input data:
-----------
Five numbers:
- field size N x M, coordinates start from 1,
- coordinates of destination point, 
- P number of knighs.

Then P lines with knights coordinates.

Output data:
-----------
Minimal sum of path lenghts or -1, if one or more knight can't reach finish point.

Example:
---------

Input:

4 4 1 1 16

1 1

1 2

1 3

1 4

2 1

2 2

2 3

2 4

3 1

3 2

3 3

3 4

4 1

4 2

4 3

4 4


Output:

42
