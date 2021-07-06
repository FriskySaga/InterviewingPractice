# A mathematical expression containing +,-,*,^, / and parenthesis will be
# provided. Read in the expression, then evaluate it. Display the result rounded
# to decimal places.
# 
# Constraints
#   All numeric values are <= 999.
 
read num

# Basic calculator with math library
echo $num | bc -l | xargs printf "%.3f"
