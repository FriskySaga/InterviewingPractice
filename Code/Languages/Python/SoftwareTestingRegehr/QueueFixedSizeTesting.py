'''
    Kevin Tran
    September 9, 2018

    Majority of code taken from the Udacity course, Software Testing, taught by
    Dr. John Regehr, who is a Professor at the University of Utah.

    This code creates a fixed-sized queue, and implements unit tests to verify
    the correctness of the code.
'''

# CORRECT SPECIFICATION:
#
# The Queue class provides a fixed-sized FIFO queue of integers.
#
# The constructor takes a single parameter:
#   A positive integer that indicates the maximum number of elements that the
#   queue can hold.
#
# Methods:
#   empty() returns True iff the queue holds no elements.
#
#   full() returns True iff the queue cannot hold any more elements.
#
#   enqueue() attempts to put an in integer i into the queue.
#   Returns True if successful, else returns False.
#
#   dequeue() removes an integer from the queue and returns it.
#   Returns None if the queue is empty.


import array


class Queue:

    # Allocates a fixed-sized region of statically allocated memory that can
    # only store integers to avoid Python's dynamic checks that make the queue
    # slow. According to Dr. Regehr's benchmarks, this statically-sized,
    # statically-typed queue is more than 10 times faster than a queue based
    # on a Python list.
    def __init__(self, max_size):
        assert max_size > 0, "max_size is not positive!"
        self.max = max_size
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(max_size))

    # Check if the queue is empty.
    def empty(self):
        return self.size == 0

    # Check if the queue is full.
    def full(self):
        return self.size == self.max

    # Add an element to the queue.
    def enqueue(self, x):

        # Do not add if the queue is full.
        if self.size == self.max:
            return False

        # Add the element to the end of the line.
        self.data[self.tail] = x
        self.size += 1
        self.tail += 1

        # Wraparound to avoid going beyond the array's limits.
        # This code will only matter if we dequeue a full queue, and then
        # enqueue again.
        if self.tail == self.max:
            self.tail = 0
        
        # Indicate a successful enqueue operation.
        return True

    # Remove an element from the queue.
    def dequeue(self):

        # Do not dequeue an empty queue.
        if self.size == 0:
            return None

        # Dequeue the first element in the line.
        x = self.data[self.head]
        self.size -= 1
        self.head += 1

        # Wraparound to avoid going beyond the array's limits.
        # This code will only matter if we dequeue a full queue, and then
        # enqueue the queue, and finally dequeue.
        if self.head == self.max:
            self.head = 0

        # Returned the dequeued integer.
        return x

    # Check representation of the queue.
    def check_rep(self):
        
        # Confine the size variable of the queue.
        assert self.size >= 0 and self.size <= self.max

        # Confirm that head and tail is consitent with size of queue.
        if self.tail > self.head:
            assert (self.tail - self.head) == self.size

        # Wraparound case: (head - tail) should equal # of empty spaces.
        if self.head > self.tail:
            assert (self.head - self.tail) == (self.max - self.size)

        # Assures queue is empty or full.
        if self.tail == self.head:
            assert self.size == 0 or self.size == self.max

    # This is a test case created by Dr. Regehr as an example.
    # This test case ensuTres that our code supports basic enqueueing and
    # dequeueing operations.
    def test1(self):
        
        # Create a queue of size 3.
        q = Queue(3)

        # Check if the queue is empty. The queue should be empty.
        res = q.empty()
        if not res:
            print("test1 NOT OK")
            return

        # Try to enqueue 10. This should work.
        res = q.enqueue(10)
        if not res:
            print("test1 NOT OK")
            return

        # Try to enqueue 11. This should work.
        res = q.enqueue(11)
        if not res:
            print("test1 NOT OK")
            return

        # Try to dequeue the first element, 10. This should work.
        x = q.dequeue()
        if x != 10:
            print("test1 NOT OK")
            return

        # Try to dequeue the remaining element, 11. This should work.
        x = q.dequeue()
        if x != 11:
            print("test1 NOT OK")
            return

        # Check if the queue is empty. The queue should be empty.
        res = q.empty()
        if not res:
            print("test1 NOT OK")
            return

        # The test case has passed.
        print("test1 OK")

    # This method was given as an exercise from Dr. Regehr.
    # This test case checks the full and empty cases. 
    def test2(self):
        
        # Create a queue of size 3.
        q = Queue(3)

        # Enqueue the first time. This should work.
        res = q.enqueue(1)
        if not res:
            print("test2 not ok")
            return

        # Enqueue the second time. This should work.
        res = q.enqueue(2)
        if not res:
            print("test2 not ok")
            return

        # Enqueue the third time. This should work.
        res = q.enqueue(3)
        if not res:
            print("test2 not ok")
            return

        # Enqueue a fourth time. This should not work.
        res  = q.enqueue(4)
        if res:
            print("test2 not ok")
            return

        # =====================================================================

        # Dequeue operation should work.
        x = q.dequeue()
        if x != 1:
            print("test2 not ok")
            return
        
        # Dequeue operation should work.
        x = q.dequeue()
        if x != 2:
            print("test2 not ok")
            return
        
        # Dequeue operation should work.
        x = q.dequeue()
        if x != 3:
            print("test2 not ok")
            return

        # Dequeue operation should not work, since the queue should be empty.
        x = q.dequeue()
        if x != None:
            print("test2 not ok")
            return

        # All operations were successful.
        print("test2 ok")

    # This method was given as an exercise from Dr. Regehr.
    # This test case checks for the wraparound cases in enqueue() and dequeue().
    def test3(self):
        
        # Create a queue of size 3.
        q = Queue(3)

        # Enqueue the first time. This should work.
        res = q.enqueue(1)
        if not res:
            print("test3 not ok")
            return

        # Enqueue the second time. This should work.
        res = q.enqueue(2)
        if not res:
            print("test3 not ok")
            return

        # Enqueue the third time. This should work.
        res = q.enqueue(3)
        if not res:
            print("test3 not ok")
            return

        # Check if the queue is full. This should be the case.
        res = q.full()
        if not res:
            print("test3 not ok")
            return

        # Dequeue once the queue is full.
        x  = q.dequeue()
        if x != 1:
            print("test3 not ok")
            return

        # Enqueue again. It should work because we wrapped the tail back to the
        # start.
        res = q.enqueue(4)
        if not res:
            print("test3 not ok")
            return
        
        # =====================================================================

        # Check if the queue is full. This should be the case.
        res = q.full()
        if not res:
            print("test3 not ok")
            return

        # Dequeue the entire queue.
        x = q.dequeue()
        if x != 2:
            print("test3 not ok")
            return
        
        # Dequeue again.
        x = q.dequeue()
        if x != 3:
            print("test3 not ok")
            return

        # Dequeue to make the queue empty.
        x = q.dequeue()
        if x != 4:
            print("test3 not ok")
            return

        # Check if the queue is empty. This should be the case.
        res = q.empty()
        if not res:
            print("test3 not ok")
            return

        # Enqueue the queue. This should work.
        res = q.enqueue(5)
        if not res:
            print("test3 not ok")
            return

        # Now dequeue the queue to test wraparound. This should work.
        x = q.dequeue()
        if x != 5:
            print("test3 not ok")
            return

        # The queue should be empty once again.
        res = q.empty()
        if not res:
            print("test3 not ok")
            return

        # All operations were successful.
        print("test3 ok")



if __name__ != "__ main__":
    my_queue = Queue(10)
    
    # Run all 3 tests.
    my_queue.test1()
    my_queue.test2()
    my_queue.test3()

    # Check representation of the queue.
    my_queue.check_rep()

