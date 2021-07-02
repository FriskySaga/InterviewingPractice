# Given three integers (x,y,z) representing the three sides of a triangle,
# identify whether the triangle is scalene, isosceles, or equilateral.
# 
#     If all three sides are equal, output EQUILATERAL.
#     Otherwise, if any two sides are equal, output ISOSCELES.
#     Otherwise, output SCALENE.
# 
# Input Format
#   Three integers, each on a new line.
# 
# Constraints
#   The sum of any two sides will be greater than the third.
# 
# Output Format
#   One word: either "SCALENE" or "EQUILATERAL" or "ISOSCELES" (quotation marks excluded).

# Read input on new lines
read a
read b
read c

if [ $a -eq $b ] && [ $a -eq $c ]
then
  echo "EQUILATERAL"
elif [ $a -eq $b ] || [ $a -eq $c ] || [ $b -eq $c ]
then
  echo "ISOSCELES"
else
  echo "SCALENE"
fi
