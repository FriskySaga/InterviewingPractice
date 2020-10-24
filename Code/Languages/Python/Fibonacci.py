'''
    Kevin Tran
    October 25, 2017
    Python 3.6.1
    Generate a sequence of Fibonacci numbers, or find the nth Fibonacci number.
'''


from time import sleep


# Ask the user to select a feature.
def ask_feature():
    print("\nThis program has two features:" \
          "\n  1. Generate a sequence of Fibonacci numbers." \
          "\n  2. Find the nth Fibonacci number." \
          "\nPress [1] to select feature 1. Press [2] to select feature 2." \
          " Press [3] to quit the program. Omit the brackets.")
    feature_choice = int(input("Make your selection here: "))
    select_feature(feature_choice, 0)


# Ask the user if they would like to restart the program.
def ask_restart():
    print("\nWould you like to restart the program?" \
          "\nPress [N] for no, and press any other key for yes." \
          " Omit the brackets.")
    restart_choice = input("Type here: ")

    if restart_choice == 'N' or restart_choice == 'n':
        quit()
    else:
        print()
        ask_feature()


# Verify that the user's input is a valid Fibonacci term.
def check_fib(n, troll_count):
    while n < 0:
        detect_troll(troll_count)
        n = int(input("\nInvalid request. Try again: "))
    return n


# Crush the troll.
def detect_troll(troll_count):
    if troll_count > 4:
        print("\nYOU ARE A TROLL! BEGONE!")
        sleep(3)
        quit()


# Find the nth Fibonacci number with dynamic programming.
def find_fib(n):
    fib = [0, 1]
    for i in range(2, n+1):
        fib[i%2] = fib[0] + fib[1]
    print_fib(n, fib[n%2])


# Generate and print the first n Fibonacci numbers with dynamic programming.
def generate_fib_sequence(n):
    print("{0", end="")
    if n >= 1:
        print(", 1", end="")
        if n > 1:
            fib = [0, 1]
            for i in range(2, n+1):
                fib[i%2] = fib[0] + fib[1]
                print(", {}".format(fib[i%2]), end="")
    print("}")


# Get the correct ordinal indicator for n.
def get_ordinal(n):
    if n % 10 == 1 and n % 100 != 11:
        return 'st'
    elif n % 10 == 2 and n % 100 != 12:
        return 'nd'
    elif n % 10 == 3 and n % 100 != 13:
        return 'rd'
    else:
        return 'th'


# Print the nth Fibonacci number.
def print_fib(n, fib):
    print("\nThe {}{} Fibonacci number is {}.".format(n, get_ordinal(n), fib))


# Go to the requested feature.
def select_feature(feature_choice, troll_count):
    if feature_choice == 1 or feature_choice == 2:
        print("\nNote these first two terms of the Fibonacci sequence:" \
              "\n  F(0) = 0\n  F(1) = 1")
        if feature_choice == 1:
            n = int(input("\nEnter the number of Fibonacci numbers to" \
                          " generate: "))
            n = check_fib(n, troll_count + 1)
            generate_fib_sequence(n)
        elif feature_choice == 2:
            n = int(input("\nEnter the nth term of the Fibonacci sequence" \
                          " that you would like to find: "))
            n = check_fib(n, troll_count + 1)
            find_fib(n)
    elif feature_choice == 3:
        quit()
    else:
        detect_troll(troll_count)
        feature_choice = int(input("\nYour entry was not recognized." \
                                   " Try again: "))
        select_feature(feature_choice, troll_count + 1)

    # Ask if user wants to restart the program after trying a feature.
    ask_restart()


#Start the program.
ask_feature()