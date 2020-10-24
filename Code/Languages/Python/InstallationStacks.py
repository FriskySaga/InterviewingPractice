# Kevin Tran
# February 21, 2018

# Linux Mint 18.3 Cinnamon Sylvia
# https://tecadmin.net/install-python-3-6-ubuntu-linuxmint
# --------------------------------------------------------

# Python 3.6.4
# Commands to check Python version:
# python3.6 -V
#   OR
# python3.6 --version

# NOTE
# python3.6 => Python 3.6.4
# python3 => Python 3.5.2
# python => 2.7.12

# NOTE
# pip3.6 => pip 9.0.1 (python 3.6)
# pip3 => pip 9.0.1 (python 3.5)
# pip => pip 9.0.1 (python 2.7)

# ----------------------------------------------------
# Commands to install relevant libraries / frameworks:
# sudo pip3.6 install opencv-python
# sudo pip3.6 install numpy
# sudo pip3.6 install tensorflow
# 

# Extra libraries to install (not needed):
# sudo pip3.6 install pygame
# sudo pip3.6 install pyqt5
# sudo pip3.6 install python-magic

# To run this code, write into a terminal:
#   python3.6 stacks.py


# Required libraries / frameworks
import cv2
import numpy as np
import tensorflow as tf

print('NumPy version: ' + np.__version__) # 1.14.1
print('OpenCV version: ' + cv2.__version__) # 3.4.0.12
print('TensorFlow version: ' + tf.__version__) # 1.5.0

# =================
# =================

# # Optional libraries / interfaces / bindings / forks
# import magic # 0.4.15
# import pygame
# from PIL import Image # 5.0.0
# from PyQt5.Qt import PYQT_VERSION_STR

# print('Pygame version: ' + pygame.__version__) # 1.9.3
# print('PyQt version: ' + PYQT_VERSION_STR) # 5.10
