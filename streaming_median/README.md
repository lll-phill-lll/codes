# Striming median

Problem statement:
-------------------

Find median in data stream, this means that we can't store all the element. And the goal is to find an effective algorithm, which finds right median with good probability or median close to rhe real value. As a measure for "close" I'll use the ratio of number of elements higher then found median to elements lower. 

We are allowed to use constant amount of memory and we can go through the strea monly once.

Solution:
---------

According to J.I.Munro and M.S.Paterson [artcle](https://www.cs.ucsb.edu/~suri/cs290/MunroPat.pdf/ "link") there is an algorithm, which provides good accuracy under given conditions. The main idea is to create a set of fixed size
