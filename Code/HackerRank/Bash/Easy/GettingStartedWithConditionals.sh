# Read in one character from STDIN.
# If the character is 'Y' or 'y' display "YES".
# If the character is 'N' or 'n' display "NO".
# No other character will be provided as input. 

read char

# echo -e to enable interpretation of backslash escapes
# grep -i to ignore case when parsing $char
echo -e "YES\nNO\n" | grep -i $char
