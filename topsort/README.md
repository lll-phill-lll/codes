# TOPOLOGICAL SORTING

Problem statement:
------------------

The main goal is to implement and understans topsort algorithm, because this is applied tool in usual life.

Description:
------------
This sort is the representation of directed graph in specific order verteces: for every edge AB from A to B in ordering A should go before B, but they can be separated by other vertices. 

In everyday life it may take part as a tool for advanced scheduling. If you have a number of tasks and some of them are to be done before others, topsort can order them, with all the conditions.

There is one restriction: topsort makes sense only with graphs which have no directed cycles.

As containers I use std::unordered_map (to save some memory and time) to store edges, and std::deque to keep there sorted vertices.

Example from wikipedia:
----------------------
![Alt text]( https://github.com/lll-phill-lll/codes/blob/master/topsort/topsort.png"Formula")
    
