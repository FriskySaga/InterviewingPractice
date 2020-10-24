{-|
    Kevin Tran
    COP4020 - Spring 2018
    Test Question #1

    Multiples of 3 or 7 but not 42 and no integers between 305 and 411
-}

-- Get multiples of 3 or 7 but not 42 in the range from 1 through 305.
findMultiples = [x | x <- [1..305], (x `mod` 3 == 0 || x `mod` 7 == 0)
            && x `mod` 42 /= 0]
            
-- Get multiples of 3 or 7 but not 42 in the range from 411 through n.
findMultiples' n = [x | x <- [411..n], (x `mod` 3 == 0 || x `mod` 7 == 0) && x `mod` 42 /= 0]

-- Combine both lists together.
findMultiples'' n = findMultiples ++ findMultiples' n
