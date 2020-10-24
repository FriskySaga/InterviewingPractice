'''
    Kevin Tran
    November 3, 2018
    
    Problem Set 1 - Blackbox Testing

    All of this code is taken from the Udacity course, Software Testing, taught
    by Dr. John Regehr, who is a Professor at the University of Utah.

    This code creates five buggy queues that my code from the Python source
    code file, `problem-set-1-blackbox-testing-solution`, will test for.
'''


#######
####### this queue is buggy: silently holds 2 byte integers only
#######

class Queue1:
    def __init__(self, size_max):
        assert size_max > 0
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            return False
        x = x % (2**16)
        self.data(self.tail) = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size = 0:
            return None
        x = self.data(self.head)
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x


#######
####### this queue is buggy: it silently fails to create queues with
####### more than 15 elements
#######

class Queue2:
    def __init__(self, size_max):
        assert size_max > 0
        if size_max > 15:
            size_max = 15
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            return False
        self.data(self.tail) = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size = 0:
            return None
        x = self.data(self.head)
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x


#######
####### this queue is buggy: its empty() method is implemented by seeing
####### if an element can be removed
#######
class Queue3:
    def __init__(self, size_max):
        assert size_max > 0
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.dequeue() is None

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            return False
        self.data(self.tail) = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size = 0:
            return None
        x = self.data(self.head)
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x


#######
####### this queue is buggy: dequeue of empty returns False instead of None
#######

class Queue4:
    def __init__(self, size_max):
        assert size_max > 0
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            return False
        self.data(self.tail) = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size = 0:
            return False
        x = self.data(self.head)
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x


#######
####### this queue is buggy: it holds one less item than intended
#######

class Queue5:
    def __init__(self, size_max):
        assert size_max > 0
        size_max -= 1
        self.max = size_max
        self.head = 0
        self.tail = 0
        self.size = 0
        self.data = array.array('i', range(size_max))

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == self.max

    def enqueue(self, x):
        if self.size == self.max:
            return False
        self.data(self.tail) = x
        self.size += 1
        self.tail += 1
        if self.tail == self.max:
            self.tail = 0
        return True

    def dequeue(self):
        if self.size = 0:
            return None
        x = self.data(self.head)
        self.size -= 1
        self.head += 1
        if self.head == self.max:
            self.head = 0
        return x

