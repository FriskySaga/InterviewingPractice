"""
Random Number Generator

Creates a list to count the number of times each number
has been randomly generated. If a number has been generated
5 times, that number is the winner.
"""

import random, time

# Makes the code run faster if enabled
RUN_FAST = False

# If configured to run slow, this is the amount of time
# to wait each iteration before generating a new number
SUSPENSEFUL_DELAY_IN_SECONDS = 0.1

# Number of times a number is chosen before the RNG
# declares it as winner
MAX_NUMBER_OF_OCCURRENCES = 25

# Both values are inclusive
MIN_NUMBER = 1
MAX_NUMBER = 26

MAX_DIGITS = len(str(MAX_NUMBER))

# Initialize number of occurrences for each number to be 0
freq = [0] * (MAX_NUMBER - MIN_NUMBER + 1)

# Initialize the chosen randomly generated number
n = None

# Time how long it took to randomly generate a number
endTime = None
startTime = time.time()

while True:
  
  # To create suspense...
  if not RUN_FAST:
    time.sleep(SUSPENSEFUL_DELAY_IN_SECONDS)

  # Randomly generate a number from [1, 26]
  n = random.randint(MIN_NUMBER, MAX_NUMBER)

  # Note that list indices start at 0.
  # Suppose n is the smallest possible number that can be
  # generated.
  # Subtracting n from the smallest number will yield 0
  index = n - MIN_NUMBER

  # Increment number of times this number has been generated
  freq[index] += 1

  # Keep on generating until the same number has been
  # generated the maximum number of occurrences
  if freq[index] < MAX_NUMBER_OF_OCCURRENCES:
    print(f"\nfreq[{index}] is now {freq[index]}...")

  else:
    endTime = time.time()
    break

# View the results for funsies
print("\n-----------------------\n")
for x in range(MIN_NUMBER, MAX_NUMBER + 1):
  print(f"Number: {x:>{MAX_DIGITS}}, Occurrences: {freq[x-MIN_NUMBER]}")

print(f"\nThe random number generator took {endTime-startTime} seconds.")

print("\nWinner:", n)