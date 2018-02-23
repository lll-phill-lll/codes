# comparison of sorting algorithms
Filitov Mikhail 2017

Problem statement:
------------------

Compare different types of sorting algorithms. The measure of sorts success if time it requires to cope with an array of random numbers. Also it's pretty interesting to implement such functions and to try  divide and conquer idea in life. 

Description:
------------

All sorts are writen using iterators, to be similar in use. After finish possible to check if the arrays are in right order, folowing the menu instructions.
Algorithms under consideration:

 - Quicksort (mine, partition function takes element, shiftet to the left of the middle)
 - Mergesort (mine)
 - Heapsort (mine)
 - Bubblesort (mine)
 - Insertssort (mine)
 - Quicksort + insertssort (mine, during testing I found out, then on the small sizes of arrays insertsort works faster then quicksort. In this section choise of an algorithm depends on the size of array).
 - Quicksort + bubblesort (mine, the same idea as with inserts)
 - std::qsort (to compare with a standart algo)
 - std::heapsort

Conclusion:
------------

On the average std::qsort in the fastest one on the random arrays, merge sort is also fast. All other are abuot the same, excepting bubble and inserts, on  the large sizes of arrays easy to feel the difference between n^2 and n\log{n} complexity, these tho algorithms work extremely bad, but sometimes (with sizes about 100) they work normal. Also insertssort is twice  faster, then bubble.

