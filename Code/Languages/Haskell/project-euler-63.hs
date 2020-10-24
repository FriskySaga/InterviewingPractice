-- Kevin Tran
-- Project Euler 63
-- Determine the number of n-digit positive integers that exist which are also an nth power.

-- My solution: Pure brute forcing
bf = length [x^y | x <- [1..99], y <- [1..99], y == (length (show (x^y)))]
