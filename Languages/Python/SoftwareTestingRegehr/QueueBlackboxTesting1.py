'''
    Kevin Tran
    November 3, 2018

    Problem Set 1 - Blackbox Testing

    This is my solution for the Udacity course, Software Testing, taught by
    Dr. John Regehr, who is a professor at the University of Utah.

    This code runs assertion checks and throws an AssertionError for each of
    the 5 incorrect Queues found in queue_test.py.
'''

# CORRECT SPECIFICATION:
#
# the Queue class provides a fixed-size FIFO queue of integers
#
# the constructor takes a single parameter: an integer > 0 that
# is the maximum number of elements the queue can hold.
#
# empty() returns True if and only if the queue currently 
# holds no elements, and False otherwise.
#
# full() returns True if and only if the queue cannot hold 
# any more elements, and False otherwise.
#
# enqueue(i) attempts to put the integer i into the queue; it returns
# True if successful and False if the queue is full.
#
# dequeue() removes an integer from the queue and returns it,
# or else returns None if the queue is empty.
#
# Example:
# q = Queue(1)
# is_empty = q.empty()
# succeeded = q.enqueue(10)
# is_full = q.full()
# value = q.dequeue()
#
# 1. Should create a Queue q that can only hold 1 element
# 2. Should then check whether q is empty, which should return True
# 3. Should attempt to put 10 into the queue, and return True
# 4. Should check whether q is now full, which should return True
# 5. Should attempt to dequeue and put the result into value, which 
#    should be 10
#
# Your test function should run assertion checks and throw an 
# AssertionError for each of the 5 incorrect Queues. Pressing 
# submit will tell you how many you successfully catch so far.


from queue_test import *


# Logic check consists of four dequeue operations and three enqueue operations
# with empty and full checks before and after each operation.
def test():
    # ===========
    # LOGIC CHECK
    # Create a new queue.
    q = Queue(2)
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the first dequeue operation returned the expected result. It should be None.
    value = q.dequeue()
    assert value == None # dequeue operation was not as expected in the fourth Queue

    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the first enqueue operation was successful. It should be.
    succeeded = q.enqueue(1)
    assert succeeded == True
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False # result was not as expected in the fifth Queue
        
    # Check if the second enqueue operation was successful. It should be.
    succeeded = q.enqueue(2)
    assert succeeded == True
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should be.
    is_full = q.full()
    assert is_full == True # result was not as expected in the third Queue
    
    # Check if the third enqueue operation was successful. It should NOT be.
    succeeded = q.enqueue(3)
    assert succeeded == False
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should be.
    is_full = q.full()
    assert is_full == True # result was not as expected in the third Queue
    
    # Check if the second dequeue operation returned the expected result. It should be 1.
    value = q.dequeue()
    assert value == 1
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the third dequeue operation returned the expected result. It should be 2.
    value = q.dequeue()
    assert value == 2
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the fourth dequeue operation returned the expected result. It should be None.
    value = q.dequeue()
    assert value == None
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # LOGIC CHECK
    # ===========
    
    
    # ===============
    # DATA TYPE CHECK
    # Check if the queue supports a negative integer.
    succeeded = q.enqueue(-17)
    assert succeeded == True
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the dequeue operation for the negative integer was successful.
    value = q.dequeue()
    assert value == -17
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the dequeue operation returns the expected result.
    value = q.dequeue()
    assert value == None
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # DATA TYPE CHECK
    # ===============
    
    
    # ============
    # MEMORY CHECK
    # Check if the queue can store a large number, such as 2^32 - 1.
    # We are not using Python's maxint or maxsize function because an error was returned.
    succeeded = q.enqueue(66036)
    assert succeeded == True
    
    # Check if the queue is empty. It should NOT be.
    is_empty = q.empty()
    assert is_empty == False

    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the dequeue operation returns the large integer.
    value = q.dequeue()
    assert value == 66036 # Result was not as expected in the first Queue.
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Check if the dequeue operation returns the expected result.
    value = q.dequeue()
    assert value == None
    
    # Check if the queue is empty. It should be.
    is_empty = q.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = q.full()
    assert is_full == False
    
    # Create a queue can hold a larger number of elements, such as 100.
    b = Queue(100)
    
    # Check if the queue is empty. It should be.
    is_empty = b.empty()
    assert is_empty == True
    
    # Check if the queue is full. It should NOT be.
    is_full = b.full()
    assert is_full == False
    
    # Enqueue lots of times.
    for x in range(1,50):
        value = b.enqueue(x)
    
    # Check if the queue is empty. It should NOT be.
    is_empty = b.empty()
    assert is_empty == False
    
    # Check if the queue is full. It should be.
    is_full = b.full()
    assert is_full == False # Result was not as expected in the first Queue.
    
    # MEMORY CHECK
    # ============
    
    # This print statement should not occur in our five broken Queues.
    print("Finished!")

