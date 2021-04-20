# Given two integers, X and Y, identify whether X < Y or
# X > Y or X = Y

read -p "First operand: " X
read -p "Second operand: " Y

# [[...]] evaluates the conditional eXpression
[[ $X -gt $Y ]] && echo 'X is greater than Y'
[[ $X -eq $Y ]] && echo 'X is equal to Y'
[[ $X -lt $Y ]] && echo 'X is less than Y'
