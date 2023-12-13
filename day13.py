matrices = open('input.txt').read().split('\n\n')

def check_matrix_row(matrix):
    for i in range(len(matrix)):
        print("matrix1",matrix[:i])
        print("matrix2",matrix[i::-1])
        if(len(matrix[:i])==len(matrix[i:]) and matrix[:i] == matrix[i:]):
            return i
            



for matrix in matrices:
    print(check_matrix_row(matrix))