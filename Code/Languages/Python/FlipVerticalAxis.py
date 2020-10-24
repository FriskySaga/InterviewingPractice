'''
    Kevin Tran
    Flip a m x n 2D image matrix in-place along its vertical axis.
'''

matrix_2_2 = [
    [1,0],
    [1,0]
]

matrix_2_3 = [
    [1, 2, 3],
    [1, 2, 3]
]

def print_matrix(matrix):
    for row in matrix:
        print row
    print '\n'

def flip_vertical_axis(matrix):
    print '\nGiven matrix:'
    print_matrix(matrix)
    
    for i in range(len(matrix)):
        matrix[i] = matrix[i][::-1]
    
    print 'Flipped matrix:'
    print_matrix(matrix)
    print '========================\n'

flip_vertical_axis(matrix_2_2)
flip_vertical_axis(matrix_2_3)
