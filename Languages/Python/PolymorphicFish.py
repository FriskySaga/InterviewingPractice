'''
    Kevin Tran
    Polymorphism Practice

    Polymorphism is the ability to leverage the same interface for different
    underlying forms such as data types or classes.
    This permits functions to use entities of different types at different
    times.
    For OOP in Python, this menas that a particular object belonging to a
    particular class can be used in the same way as if it were a different
    object belonging to a different class.
    Polymorphism can be carried out through inheritance, with subclasses making
    use of base class methods or overriding them.

    The argument to these functions is the word self, which is a reference to
    objects that are made based on this class. To reference instances (or
    objects) of the class, self will always be the first parameter, but it need
    not be the only one.

'''

class Shark():
    def __init__(self, name):
        self.name = name

    def swim(self):
        print(self.name + " is swimming.")

    def swim_backwards(self):
        print("The shark cannot swim backwards, but can sink backwards.")

    def skeleton(self):
        print("The shark's skeleton is made of cartilage.")

class Clownfish():
    def swim(self):
        print("The clownfish is swimming.")

    def swim_backwards(self):
        print("The clownfish can swim backwards.")

    def skeleton(self):
        print("The clownfish's skeleton is made of bone.")

# A function that can take any object, allowing for polymorphism
def in_the_pacific(fish):
    fish.swim()

def main():
    # Instantiate Shark class
    sammy = Shark("Sammy")
    sammy.skeleton()

    # Instantiate Clownfish class
    casey = Clownfish()
    casey.skeleton()

    print("==================================================================")

    # Iterates through a tuple of objects
    for fish in (sammy, casey):
        fish.swim()
        fish.swim_backwards()
        fish.skeleton()

    print("==================================================================")

    in_the_pacific(sammy)
    in_the_pacific(casey)

# __name__ is a built-in variable which evaluates to the name of the current
# module. Thus, you can test whether your script is being run directly or being
# imported by something else.
if __name__ == "__main__":
    main()
