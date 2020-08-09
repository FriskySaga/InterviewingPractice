'''
    Kevin Tran
    February 10, 2018
    Python 3.6.1

    This program detects all purple objects.
'''


import cv2
import numpy as np


# Open the default camera.
cap = cv2.VideoCapture(0)

# This drives the program into an infinite loop.
while True:
    # Capture the live stream frame-by-frame.
    ret, frame = cap.read()

    # Convert the images from BGR to HSV since HSV values are easier to work with.
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # lower_purple is closer to blue, and upper_purple is closer to red
    # The hue value is taken from MS Paint and then multiplied by 180/240 because
    # MS Paint's hue range goes from 0-239 but OpenCV's hue range goes from 0-180.
    # Choosing too low of a saturation and value will generate more false positives.
    lower_purple = np.array([132, 50, 50])
    upper_purple = np.array([168, 255, 255])

    # Define the range of purple in HSV. This creates a mask of purple-colored objects in the frame.
    mask = cv2.inRange(hsv, lower_purple, upper_purple)

    # The bitwise AND of the frame and mask is needed so that only purple-colored objects are highlighted.
    res = cv2.bitwise_and(frame, frame, mask = mask)

    # Removes noise by erosion followed by dilation.
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, None, iterations = 2)

    # Reduces noise (effective against salt-and-pepper noise in images).
    frame = cv2.medianBlur(frame, 5)

    # Find contours of purple objects.
    contours = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]

    # If we find a contour:
    if len(contours) > 0:
        # Get the largest contour.
        max_c = max(contours, key = cv2.contourArea)
            
        # Find the circumference of the contour.
        ((x, y), radius) = cv2.minEnclosingCircle(max_c)
        
        # Get the image moment.
        M = cv2.moments(max_c)
        
        # Find the center of the image moment.
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

        # Draw the outer circle that encompasses the object.
        cv2.circle(frame, (int(x), int(y)), int(radius),  (0,255,255), 2)

        # Draw an inside red dot to identify the center of the tracked object.
        cv2.circle(frame, center, 5, (0, 0, 255), -1)

    # Display the frame window.
    cv2.imshow('Frame', frame)

    # Quit if the user presses Q
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Destroy all of the HighGUI windows.
cv2.destroyAllWindows()

# Release the capture.
cap.release()
