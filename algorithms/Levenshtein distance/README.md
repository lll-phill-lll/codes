# Levenshtein distance

Problem statement:
-----------------

Interesting to find out the similarity of 2 words. This algorithm may be used in simple predictive text 
system. In case of mistakeit can predict the word user probably wanted to write.

Description:
-----------

The Levenshtein distance is a string metric for measuring the difference between two sequences. 
Informally, the Levenshtein distance between two words is the minimum number of single-character 
edits (insertions, deletions or substitutions) required to change one word into the other. It can be 
applied, for instance, to spell checkers, correction systems for optical character recognition, 
and software to assist natural language translation based on translation memory.

Example:
--------

For example, the Levenshtein distance between "kitten" and "sitting" is 3, since the following 
three edits change one into the other, and there is no way to do it with fewer than three edits:

- kitten → sitten (substitution of "s" for "k")
- sitten → sittin (substitution of "i" for "e")
- sittin → sitting (insertion of "g" at the end).

Algorithm:
----------

It's a dynamic programming algorith similar to knapsack problem solution. The idea is to compute 
distance between subwords, using the formula below and build the table with all values. The answer is
the cell, which refers to the end of each word.


IO data:
--------
Input:

2 words.

Output:

Table of distances and the answer.

Formula:
------- 
![Alt text](https://github.com/lll-phill-lll/codes/blob/master/Levenshtein%20distance/formula.png "Formula")
