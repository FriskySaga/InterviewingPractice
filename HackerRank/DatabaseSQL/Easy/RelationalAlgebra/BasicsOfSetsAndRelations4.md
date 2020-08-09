# Basic of Sets and Relations #4
**Type: Databases > Relational Algebra**  
**Difficulty Level: Easy**

### Problem Statement
You are given two sets.
Set **A** = {1,2,3,4,5,6}
Set **B** = {2,3,4,5,6,7,8}
What is the total number of ordered pairs present in the Cartesian product **A X B**?

### Answer
Definition of Cartesian product:
  A × B = {(x, y) : x ∈ A, y ∈ B} 

Set **A X B** = {(1,2), (1,3), (1,4), ..., (1,7), (2,2), (2,3), ..., (2,8), (3,2), ..., (6,8)}

To compute the number of elements in the set `A X B`, literally take the product of the cardinality of set A and and the cardinality of set B.
  |A| * |B| = |A X B|

Recall that the _cardinality_ of a set is a measure of that set's size.
  |A| = 6
  |B| = 7

Therefore, there are 42 elements.

