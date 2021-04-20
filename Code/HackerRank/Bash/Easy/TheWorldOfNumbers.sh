# Given two integers, X and Y, find their sum, difference,
# product, and quotient.
read -p "First operand: " operand1
read -p "Second operand: " operand2

# $((...)) means to perform arithmetic and return the result
# of the calculation.
echo $((operand1 + operand2))
echo $((operand1 - operand2))
echo $((operand1 * operand2))
echo $((operand1 / operand2))