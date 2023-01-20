# SolveSudoku_C
defeating grannies in no time


## hor_solve():

uses mainly the frame to reorder the internal 9, 3*3 matrix into the horizontal rows of the large 3 * 3 matrix externals.

## transpose():

used together with hor_solve to find the vertical columns. As they are the transpose of the horizontal solved matrix.

## int_solve():

is a zero step solution finder. Checks if there is one missing value (0) in a row and checks that for every row. The input is a 3 * 3 matrix (ordered in one row). 
For internally solving that 9 smaller 3 * 3 Matrixes input the frame. 
To solve for horizontal rows. First use hor_solve, then int_solve, then reuse hor_solve with reversed order. For the vertical columns this same step is done,
with the addition of a tranpose. 


This can then finally be looped over with a "while True" loop that stops (False) at the point there is not addition of a zero in the full loop (internal, vertical, horizontal solving).

## updates:

* Combining row and internal operation together (number of 0 > 2).
    ** will be done by filling in all possible values at position (and therefore easy way of combining operations)
* Picture input read towards right frame.

## preformance:

https://en.wikipedia.org/wiki/Sudoku 

output:

5 3 4   6 7 2   1 9 8   
6 7 8   1 9 5   3 4 2   
9 1 2   3 4 8   5 6 7   

8 5 9   4 2 6   7 1 3   
7 6 1   8 5 3   9 2 4   
4 2 3   7 9 1   8 5 6   

9 6 1   2 8 7   3 4 5   
5 3 7   4 1 9   2 8 6   
2 8 4   6 3 5   1 7 9   

solved in 1079ms.
