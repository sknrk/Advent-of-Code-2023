def read_matrix_from_file(file_name):
    with open(file_name, 'r') as file:
        matrix = [list(line.strip()) for line in file.readlines()]
    return matrix

def rotate_matrix_90_clockwise(matrix):
    return [list(reversed(col)) for col in zip(*matrix)]

def move_os_up(matrix):
    row_count = len(matrix)
    col_count = len(matrix[0])
    total = 0
    last_total = 0
    store_total= [] 
    first_total=0
    for t in range(0,100000000):
        for k in range(1,5):
            for row in range(0,row_count):
                for col in range(0,col_count): 
                    if(matrix[row][col]=='O'):
                        temp_row = row
                        while(temp_row-1>=0 and matrix[temp_row-1][col]=='.'):
                            matrix[temp_row][col], matrix[temp_row-1][col] = matrix[temp_row-1][col], matrix[temp_row][col]
                            temp_row=temp_row-1
                            total += row_count-temp_row
            print(total)
            for item in store_total:
                if item[0] == [last_total, total]:
                    print(item[1])
                    break  
            store_total.append([[last_total,total],[t]])
            last_total=total
            total=0
            matrix=rotate_matrix_90_clockwise(matrix)

    return matrix,last_total

# def move_os_up(matrix):
#     row_count = len(matrix)
#     col_count = len(matrix[0])
#     total = 0
#     last_total = 0
#     store_total = []
#     last_seen = {}  # Her ikilinin son görüldüğü 't' değerini saklar

#     t = 0
#     while t < 3000000:
#         print (t)
#         for k in range(1, 5):
#             for row in range(row_count):
#                 for col in range(col_count):
#                     if matrix[row][col] == 'O':
#                         temp_row = row
#                         while temp_row - 1 >= 0 and matrix[temp_row - 1][col] == '.':
#                             matrix[temp_row][col], matrix[temp_row - 1][col] = matrix[temp_row - 1][col], matrix[temp_row][col]
#                             temp_row -= 1
#                             total += row_count - temp_row

#             current_pair = (total, last_total)
#             if current_pair in store_total:
#                 if current_pair in last_seen:
#                     cycle_length = t - last_seen[current_pair]
#                     t += cycle_length  # Bir sonraki tekrar için 't'yi artır
#                     last_seen[current_pair] = t  # Son görülme zamanını güncelle
#                     break  # İç içe döngüden çık
#                 else:
#                     last_seen[current_pair] = t
#             else:
#                 if k % 4 == 1:
#                     store_total.append(current_pair)

#             last_total = total
#             total = 0
#             matrix = rotate_matrix_90_clockwise(matrix)

#         if current_pair not in store_total or current_pair not in last_seen:
#             t += 1  # Eğer ikili yeni ise veya henüz bir döngü başlamamışsa, 't'yi artır

#     return matrix,last_total

def print_matrix(matrix):
    for row in matrix:
        print(''.join(row))

matrix = read_matrix_from_file('input.txt')
modified_matrix,total = move_os_up(matrix)
# print_matrix(modified_matrix)
print(total)
