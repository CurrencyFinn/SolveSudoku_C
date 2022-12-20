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


This can then finally be looped over with a "while True" loop that stops (False) at the point there is not addition of a zero in the full loop (internal, vertical, horizontal solving)
