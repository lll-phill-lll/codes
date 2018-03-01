# Striming median

Problem statement:
-------------------

Find median in data stream, this means that we can't store all the elements. And the goal is to find an effective algorithm, which finds right median with good probability -  median close to rhe real value. Also this method should allow to compute median every moment. As a measure for "close" I'll use the ratio of number of elements higher then found median to elements lower. 

We are allowed to use constant amount of memory and we can go through the strea monly once.

Solution:
---------

According to J.I.Munro and M.S.Paterson [article](https://www.cs.ucsb.edu/~suri/cs290/MunroPat.pdf "link") there is an algorithm, which provides good accuracy under given conditions. The main idea is to create a set of fixed size which represents the data of all set.

Algorithm explanation:
---------------------

As was mentioned earlier the idea is to keep in memory small set of data from which we will take the
value we are looking for. Also the algorithm requires to store two counters: number of stream elements,
which are smaller, then the minimum of set - l, and which are greater, then the maximum - h. After the set is full we will maintain the equality of 2 counters. For example, if h > l, we erase minimum, and then
add next value to the set. Similatly with h < l. With this algorithm we want to store middle part of streaming data. 

When will it work?
------------------
J.I.Munro and M.S.Peterson proved, that optimal value of set is \sqrt{N}, where N is the size of input (in most number of cases this parameter is unknown), still it doesn't guarantee that, value is right. 

Hypothesis:
------------
It seems that with uniform destribution algorithm will work ok, but what about destribution with nonlinear
density function? For example lognormal?
Probably the set we make will be incorrect.

Results:
--------
While testing on streams of size around 500000, on lognormal distribution algorithm showed worst result
then on even distribution, but the average difference is about 5-8 percents and the values were 90 - 95% accuracy.

Summorize:
This is a good example of approximate algorithm, which can work with streams. 
