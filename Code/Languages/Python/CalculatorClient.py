'''
    Kevin Tran
    November 24, 2017
    Python 3

    This is the client side of a basic calculator program that computes the four
    basic arithmetic operations. This client-side program will be used alongside
    'calculator_server.py'. The server-side program shall start first.
'''


from socket import *


# Connect to the local computer.
server_name = 'localhost'

# Pick an arbitrary server port number between 1024 and 65535.
server_port = 12000

# Create a socket object that implements the various system socket calls.
# AF_INET is the address family IPv4.
# SOCK_STREAM refers to the connection-oriented protocol.
client_socket = socket(AF_INET, SOCK_STREAM)

# Connect to the server.
client_socket.connect((server_name, server_port))

# Explain the purpose of this program.
print("\nThis is the client side of a basic calculator program that" \
      " computes the four\nbasic arithmetic operations. This client-side" \
      " program will be used alongside\n'calculator-server.py'. The" \
      " server-side program shall start first.")

# Tell the user how to use this program.
print("\nThis calculator accepts all decimal integers and floats." \
      " Negative numbers are\nalso valid. Only the four basic arithemetic" \
      " operations are supported.\nUse '+', '-', '*', and '/' to indicate" \
      " the operation." \
      "\nFor example, type '20 + 10.5', and press Enter. The server will" \
      " evaluate the\nresult to '30.5', and send this number to the" \
      " client." \
      "\nTo terminate this program, enter a comma symbol.\n")

# Stop when the user tries to divide by 0.
while 1:
    # Tell the user to enter a basic arithmetic operation.
    expression = input("Enter an arithmetic expression here: ")

    # End the program if the user tries to divide by 0.
    if expression == ',':
        break

    # Convert the user's request to a byte-like object, and send to the server.
    client_socket.send(expression.encode('UTF-8'))

    # Receive the answer from the server.
    result = client_socket.recv(1024)

    # Print the answer to the client screen without the 'b' character.
    print("Evaluation expresion from server: ", result.decode('UTF-8'))

# Tidy up.
client_socket.close()
