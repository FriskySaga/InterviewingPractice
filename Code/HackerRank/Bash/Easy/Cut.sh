# Given n lines of input, print the 3rd character from each line as a new line
# of output. It is guaranteed that each line of input will have a 3rd character
cut -c3 $1

# Display the 2nd and 7th character from each line of text
cut -c2,7 $1

# Display a range of characters starting at the 2nd position of a string and
# ending at the 7th position (both positions included)
cut -c2-7 $1

# Display the first four characters from each line of text
cut -c-4 $1

# Given a tab delimited file with several columns (tsv format), print the first
# three fields
cut -f1-3 $1

# Print the characters from the 13th position to the end
cut -c13- $1
