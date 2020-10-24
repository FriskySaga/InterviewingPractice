'''
    Kevin Tran
    November 24, 2017
    Python 3

    This is the server side of a basic calculator program that computes the four
    basic arithmetic operations. This server-side program will be used alongside
    'calculator_client.py'. The server-side program shall start first.
'''


from socket import *
from time import sleep


# Pick an arbitrary server port number between 1024 and 65535.
server_port = 12000

# Create a socket object that implements the various system socket calls.
# AF_INET is the address family IPv4.
# SOCK_STREAM refers to the connection-oriented protocol.
server_socket = socket(AF_INET, SOCK_STREAM)

# Bind the server socket, and listen to incoming requests.
server_socket.bind(('', server_port))

# Keep only one connection waiting if the server is busy.
server_socket.listen(1)

# Print to the server side.
print("The server is ready to receive.")

# Establish connection with the client.
connection_socket, addr = server_socket.accept()
print("Connected by client on", addr)

# Stop when the user tries to divide by 0.
while 1:
    # Receive an expression of max buffer length 1024.
    expression = connection_socket.recv(1024)
    expression = expression.decode('UTF-8')

    # Print to the server screen the received message.
    print("Received expression from client:", expression)

    # Store the operands and character count. Check for negative numbers.
    operand_1 = ''
    operand_2 = ''
    operator = ''
    cnt = 0
    neg_1 = False
    neg_2 = False
    float_1 = False
    float_2 = False

    # Parse the string until we find an operator.
    for c in expression:
        # Check for a negative sign before the first operand.
        if cnt == 0 and c == '-':
            neg_1 = True

        # Increment the letter count.
        cnt += 1

        # Find the first operand.
        if c.isdigit():
            operand_1 += c

        # Recognize decimal points.
        elif c == '.' and float_1 == False:
            float_1 = True
            operand_1 += c

        # Break the loop if we find an operator.
        elif c == '+' or c == '-' or c == '*' or c == '/':
            operator = c
            break

        # Ignore spaces.
        elif c == ' ':
            continue

        # Report an error if we encounter a second decimal point, or any
        # unsupported character.
        else:
            print("\nError: Invalid syntax before operator.")
            sleep(3)
            quit()

    # Check if the user entered any operator.
    if operator == '':
        print("\nError: No operator was entered.")
        sleep(3)
        quit()

    # Parse the rest of the expression.
    for c in range(cnt, len(expression)):
        # Check for a negative sign before the first operand.
        if c == cnt and expression[c] == '-':
            neg_2 = True

        # Get the second operand.
        elif expression[c].isdigit():
            operand_2 += expression[c]

        # Recognize decimal points.
        elif expression[c] == '.' and float_2 == False:
            float_2 = True
            operand_2 += expression[c]

        # Ignore spaces.
        elif expression[c] == ' ':
            continue

        # Report an error if we encounter a second decimal point, or any
        # unsupported character.
        else:
            print("\nError: Invalid syntax after operator.")
            sleep(3)
            quit()

    # Evaluate the expression.
    operand_1 = float(operand_1)
    operand_2 = float(operand_2)
    result = 0
    if operator == '+':
        result = operand_1 + operand_2
    elif operator == '-':
        result = operand_1 - operand_2
    elif operator == '*':
        result = operand_1 * operand_2
    elif operator == '/':
        result = operand_1 / operand_2

    # Send the computed answer to the client.
    result = str(result)
    print("Send back answer", result)
    connection_socket.send(result.encode('UTF-8'))

# Tidy up.
connection_socket.close()
server_socket.close()
