'''
    Kevin Tran
    May 15, 2019
'''


# Import the Tkinter Python module.
import Tkinter


'''
@NOTE

import Tkinter as tk
    This will allow you to type "tk" instead of "Tkinter" everywhere down below.
    You can also "import Tkinter as Marcy", but the standard is to use "tk".

from Tkinter import *
    This will allow you to import all Tkinter classes, so you don't need to type "tk" or "Tkinter".
    In other words, you don't need to preface any of the Tkinter classes. (See below)

from Tkinter import Tk, Frame, Menu
    This will allow you to import only those specific Tkinter classes,
    which is useful for conserving memory on a large system with lots library/module/package/file imports.
    In this situation, you don't need to preface Tk, Frame, and Menu with the keywords "tk" or "Tkinter".

The reason why I used "import Tkinter" is to make this code more readable for you.
If you see "Tkinter.Frame", you would know that Frame came from Tkinter, and not from "tk", which you may find confusing,
and that it didn't come from nowhere.
'''


# This is a global variable that I initialized to 0.
# Python convention says to space out two blank lines between every unindented piece of code.
user_input = 0


## A class is a blueprint of an object. Scroll down all the way to the bottom for more details.
class CalculatorInterface:

    # Init stands for "initialize".
    # Initialize the blueprint... of what?
    # We refer to the blueprint CalculatorInterface as "self".
    def __init__(self):

        # Indicate that we want to use the global variable that was declared outside of this class.
        global user_input

        # Create a root window.
        self.root = Tkinter.Tk()

        # Set the title of the root window.
        self.root.title("Oyster's Calculator")

        # Set the window size of the root window (500 x 500 pixels)
        self.root.geometry("500x500")

        # Do not allow for the window to be resized in the x direction and in the y direction.
        # Google "tkinter resizable" to learn the "resizable" method's definition.
        # Google will tell you whether the first False or second False corresponds to the x direction.
        # In this case, we don't care to resize it at all, so we set them both to False.
        # You can also experiment through trial and error to figure out what it does.
        self.root.resizable(False, False)

        # We make a menu on the root window. But it's invisible!
        self.menu = Tkinter.Menu(self.root)

        # We actually show the menu on the root window.
        self.root.config(menu = self.menu)

        # Create the File menu. Tearoff values can either be 0 or 1.
        # Try setting tearoff to 1, and back to 0, and see the difference for yourself.
        # Hint: If tearoff is 1, you can click on the dashed lines to extract the File menu
        #       to a separate window. It's not a very modern feature.
        self.file_menu = Tkinter.Menu(self.menu, tearoff = 0)

        # Visually name the File menu "File", and allow it to cascade to be a dropdown menu.
        self.menu.add_cascade(label = "File", menu = self.file_menu)

        # Add an option on the File menu called "Exit", which will destroy the root window when clicked.
        # In other words, kill the application.
        self.file_menu.add_command(label = "Exit", command = self.root.destroy)

        # Conceptually create a frame to contain other widgets.
        # This frame should go on the root window.
        self.frame = Tkinter.Frame(self.root)

        # The method pack() will pack the corresponding object onto the specified location.
        # As indicated above, we will pack this frame onto the root window.
        self.frame.pack()

        # The frame now "visually" exists after executing the above line of code.
        # It's actually invisible to the naked eye.

        # Make a text label on the frame called "GOOD MORNING!" Give it foreground and background colors.
        self.greet_label = Tkinter.Label(self.frame, text = "GOOD MORNING!", fg = "green", bg = "black")

        # Place the text label on row 1, column 1. We count from top to bottom, and left to right.
        # So, row 0 is all the way to the top, and column 0 is all the way to the left.
        self.greet_label.grid(row = 1, column = 1)

        # Make a button when clicked will call the method mug_number() that we defined below.
        self.button_ask_number = Tkinter.Button(self.frame, text = "Give me a number!", command = self.mug_number)
        self.button_ask_number.grid(row = 2, column = 1)

        # Make a text label. We will dynamically update this text label.
        self.sexy_sum_label = Tkinter.Label(self.frame, text = "This line is where your sum will show up!")
        self.sexy_sum_label.grid(row = 3, column = 1)

        # Make a button when clicked will call the method add_two_numbers() that we defined below.
        self.button_add = Tkinter.Button(self.frame, text = "Click here to add your number to 69!", command = lambda: self.add_two_numbers(69, int(user_input)))
        self.button_add.grid(row = 4, column = 1)

        self.root.mainloop()

    ## This is our method to add two numbers, represented as a and b.
    # self, a, and b are all called "parameters". We have 3 parameters.
    def add_two_numbers(self, a, b):

        # Simple enough.
        # Add the variables "a" and "b", and store them in a variable called "sumValue".
        sumValue = a + b

        # Dynamically update the sexy sum label on row 3, column 1.
        # "Cast" sumValue as a string type to neatly display the text since it was originally a "number" type.
        self.sexy_sum_label.config(text = str(sumValue))

    ## This is our method to mug, sorry, I mean, "ask" our user for a number.
    def mug_number(self):

        # Create a popup object from the Popup class blueprint passing in our frame.
        popup = Popup(self.frame)

## This is another class blueprint that takes in a frame, which we call "master".
class Popup(Tkinter.Frame):
    def __init__(self, master = None):

        # Set a top-level window on master. In other words, this is our popup.
        # If we try to click outside the popup, it will not let us because it is a Toplevel type widget.
        # Widgets are basically any classifiable objects, such as buttons, windows, text labels, etc.
        self.top = Tkinter.Toplevel(master)

        # Set the size of this top-level window to 100 x 100 pixels.
        self.top.geometry("100x100")

        # Make a label.
        # In this case, I'm showing you instead of putting it on a grid, you can just say "pack".
        # When it packs, Tkinter smartly puts it for you wherever it should go.
        self.label_prompt = Tkinter.Label(self.top, text = "Your number")
        self.label_prompt.pack()

        # Make an Entry field object for the user to type something in.
        # Beause we pack this after packing the above label, then this automatically goes right down below.
        self.entry_enter = Tkinter.Entry(self.top)
        self.entry_enter.pack()

        ## This is a "subroutine", meaning that it is a function inside another function/method.
        ## This function will receive the user's input.
        def get_user_input():

            # Indicate that we want to use the global variable.
            global user_input

            # Entry objects have a built-in method called "get()",
            # which will automatically read in input that is typed by the user.
            user_input = self.entry_enter.get()

        # Since this line of code is indented at the same level as the subroutine above,
        # then this line of code is no longer part of the subroutine.
        # INDENTATIONS MATTER!
        # This line of code calls the get_user_input() function when the button is clicked.
        button_enter = Tkinter.Button(self.top, text="Enter", command = get_user_input)
        button_enter.pack()

        # This line of code implements a button that will kill the Toplevel popup window.
        self.button_close = Tkinter.Button(self.top, text = "Close", command = self.top.destroy)
        self.button_close.pack()


# When you start the program, Python will run the code under here first.
# However, if this Python source code file is not the "main" source code file,
# meaning that another Python source code file imports this file,
# then the code below will not run.
if __name__ == '__main__':

    # myCalculator is an object from the class blueprint CalculatorInterace()
    myCalculator = CalculatorInterface() # This line of code will be processed.

    '''
    If I were to write a second line of code:
        anotherCalculator = CalculatorInterface()

    Then once the first line of code finishes processing,
    meaning that once the GUI window has been closed,
    then "another calculator" GUI window will pop up after this one.

    Try it yourself to see.
    '''

