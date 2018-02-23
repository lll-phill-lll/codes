# Levenstein distance

Problem statement:
-----------------

Interesting to find out the similarity of 2 words. This algorithm may be used in simple predictive text system. In case of mistakeit can predict the word user probably wanted to write.

Description:
-----------

The Levenshtein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (insertions, deletions or substitutions) required to change one word into the other.

Example:
--------

For example, the Levenshtein distance between "kitten" and "sitting" is 3, since the following three edits change one into the other, and there is no way to do it with fewer than three edits:

- kitten → sitten (substitution of "s" for "k")
- sitten → sittin (substitution of "i" for "e")
- sittin → sitting (insertion of "g" at the end).

Formula:
-------
![Alt text](https://github.com/lll-phill-lll/codes/blob/master/Levenshtein%20distance/formula.png "Formula")
