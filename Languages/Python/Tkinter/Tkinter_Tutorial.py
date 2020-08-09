# -*- coding: utf-8 -*-
"""
Created on Mon May 29 18:11:01 2017

@author: Kevin
"""

from tkinter import *
import tkinter.messagebox

'''
#master refers to the main/root window. (Video 8)
class KevinButtons:
    def __init__(self, master):
        #Blank window.
        frameClass = Frame(master)
        frameClass.pack()
        
        #Simple button.
        self.printButton = Button(frameClass, text="Print message...", command=self.printMessage)
        self.printButton.pack(side=LEFT)
        
        #Quit button instead of "X" button.
        self.quitButton = Button(frameClass, text="Quit", command=master.destroy)
        self.quitButton.pack(side=LEFT)
    
    #self is the object from KevinButtons class.
    def printMessage(self): print("Nice, this worked!")

#--------------------------------------------------------
'''

#Blank window.
root = Tk()

'''
##--------------------------------------------------------

#Store a file in the object "photo" (Video 14)
photo = PhotoImage(file="4Crew.png")

#Slap a photo in a label.
label = Label(root, image=photo)
label.pack()


##--------------------------------------------------------

#Make a canvas to draw on. (Video 13)
canvas = Canvas(root, width=200, height=100)
canvas.pack()

#By default, all graphics are black.
#First two parameters are x and y coordinates for starting point (top-left).
#Last two parameters are x and y coordinates for ending point.
blackLine = canvas.create_line(0, 0, 200, 50)
redLine = canvas.create_line(0, 100, 200, 50, fill="red")

#Make a shape. XY for top-left. XY for bottom-right.
greenBox = canvas.create_rectangle(25, 25, 130, 60, fill="green")

#Hide/delete a graphic.
canvas.delete(redLine)

#Wipe the canvas
canvas.delete(ALL)

##--------------------------------------------------------

#Remember to import some stuff for the messagebox. (Video 12)
tkinter.messagebox.showinfo("Window Title", "Monkeys can live up to 300 years.")

#This will give some options (yes/no).
answer = tkinter.messagebox.askquestion("Question 1", "Do you like silly faces?")
if answer == "yes":
    print(" B===D= ")

#--------------------------------------------------------
#(Video 9-11)
def doNothing():
    print("Okay, I won't.")

#CREATE MENU.
#We're configuring a menu to our menu object (left parameter is required). (Video 9-11)
menu = Menu(root)
root.config(menu=menu)

#Create a submenu, i.e., a menu item within the main menu (the dropdown).
subMenu = Menu(menu)

#Dropdown functionality is called "cascading". Implement for main menu.
menu.add_cascade(label="File", menu=subMenu)

#Add something to our submenu and link to our functions.
subMenu.add_command(label="New Project...", command=doNothing)
subMenu.add_command(label="New...", command=doNothing)

#Add a separator to create a line to separate one group of items from another group.
subMenu.add_separator()

#Add another functionality.
subMenu.add_command(label="Exit", command=doNothing)

#Create another menu item in our main menu. tearoff=0 removes the dashed line above the dropdown list.
editMenu = Menu(menu, tearoff=0)
menu.add_cascade(label="Edit", menu=editMenu)
editMenu.add_command(label="Redo", command=doNothing)

#CREATE TOOLBAR.
#Create the toolbar that sits in the main window.
toolbar = Frame(root, bg="blue")

#Add a button into our toolbar.
insertButt = Button(toolbar, text="Insert Image", command=doNothing)

#2 pixels padding to give some space
insertButt.pack(side=LEFT, padx=2, pady=2)

#Another button into our toolbar.
printButt = Button(toolbar, text="Print", command=doNothing)
printButt.pack(side=LEFT, padx=2, pady=2)

#Display the actual toolbar. Take up entire width of window.
toolbar.pack(side=TOP, fill=X)

#CREATE STATUS BAR.
#bd stands for "border", anchor west
status = Label(root, text="Preparing to do nothing...", bd=1, relief=SUNKEN, anchor=W)
status.pack(side=BOTTOM, fill=X)

#--------------------------------------------------------

#Create an object to access the class. (Video 8)
k = KevinButtons(root)

#--------------------------------------------------------

#Bind multiple functions to a widget. (Video 7)
def leftClick(event): print("Left")
def middleClick(event): print("Middle")
def rightClick(event): print("Right")

#Invisible frame inside the root window.
frame = Frame(root, width=300, height=250)
frame.bind("<Button-1>", leftClick)
frame.bind("<Button-2>", middleClick)
frame.bind("<Button-3>", rightClick)
frame.pack()

#--------------------------------------------------------

#This is a function that we're going to bind to our widget. (Video 6)
def printName(): print("Hello, my name is Kevin.")

#When this button is clicked, call this function "printName".
button_1 = Button(root, text="Print my name.", command=printName)
button_1.pack()

#Alternative way to bind a function to our widget.
def printAge(event): print("My age is 20.")
button_2 = Button(root, text="Print my age.")
button_2.bind("<Button-1>", printAge) #left-clicking
button_2.pack()

#--------------------------------------------------------

#Entry allows for input from the user. (Videos 4 and 5)
label_1 = Label(root, text="Name")
label_2 = Label(root, text="Password")
entry_1 = Entry(root)
entry_2 = Entry(root)

#Instead of packing, use the grid layout. By default, column=0.
label_1.grid(row=0, sticky=E) #E is short for east
label_2.grid(row=1)
entry_1.grid(row=0, column=1)
entry_2.grid(row=1, column=1)

#This checkbox widget takes up two columns.
c = Checkbutton(root, text="Keep me logged in.")
c.grid(columnspan=2)

#--------------------------------------------------------

#This label will not stretch if the window size changes. (Video 3)
one = Label(root, text="One", bg="red", fg="white")
one.pack()

#This label will stretch in the x-direction if the window size changes.
two = Label(root, text="Two", bg="green", fg="black")
two.pack(fill=X)

#This label will stretch in the y-direction if the window size changes.
three = Label(root, text="Three", bg="blue", fg="white")
three.pack(side=LEFT, fill=Y)

#--------------------------------------------------------

#Make invisible containers in the main window (root). (Video 2)
topFrame = Frame(root)
topFrame.pack()
bottomFrame = Frame(root)
bottomFrame.pack(side=BOTTOM)

#Create buttons.
button1 = Button(topFrame, text="Button 1", fg="red")
button2 = Button(topFrame, text="Button 2", bg="red")
button3 = Button(topFrame, text="Button 3", fg="blue")
button4 = Button(bottomFrame, text="Button 4", fg="purple")

#Display widgets.
button1.pack(side=LEFT)
button2.pack(side=LEFT)
button3.pack(side=LEFT)
button4.pack()

#--------------------------------------------------------

#Create text on screen. (Video 1)
theLabel = Label(root, text="This is too easy")

#Place the text on the screen.
theLabel.pack()
'''

#Keep window open.
root.mainloop()