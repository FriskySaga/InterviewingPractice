'''
    Kevin Tran
    February 27, 2018
    Python 3.6.4

    This is the graphical user interface for color-detection.py
'''

import sys
from PyQt5 import QtGui, QtWidgets, uic

# Creation of GUI object.
class GUI(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()

        # Define and make the main window.
        self.width = 480
        self.height = 360
        self.init_main_window()

    # Make the main window.
    def init_main_window(self):
        main_window = uic.loadUi("color-detection-main-window.ui", self)
        main_window.setFixedSize(self.width, self.height)
        
        main_window.push_button_color_picker.clicked.connect(self.add_color_picker)
        self.show()

    def add_color_picker(self, main_window):
        color = QtWidgets.QColorDialog.open(QtWidgets.QColorDialog.getColor())


# Start the GUI.
app = QtWidgets.QApplication(sys.argv)
window = GUI()
sys.exit(app.exec_())
