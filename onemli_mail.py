
str_in = input()
length = len(str_in)


def return_next(end):
    global str_in
    cursor = end - 1
    while cursor >= 0:
        if str_in[cursor] == '[':
            return str_in[cursor + 1:end] + return_next(cursor)
        elif str_in[cursor] == ']':
            return return_next(cursor) + str_in[cursor + 1:end]
        cursor -= 1
    return str_in[:end]


print(return_next(length))





# def return_next(start):
#     global str_in
#     global length
#     cursor = start + 1
#     while cursor < length:
#         if str_in[cursor] == '[':
#             return return_next(cursor) + str_in[start + 1:cursor]
#         elif str_in[cursor] == ']':
#             return str_in[start + 1: cursor] + return_next(cursor)
#         cursor += 1
#     return str_in[start+1:]
#
#
# print(return_next(-1))






# str_in = input()
# list = []
# cursor = 1
# for c in str_in:
#     if c == ']':
#         cursor = -1
#     elif c == '[':
#         cursor = 0
#     else:
#         list.insert(cursor, c)
#         cursor += 1
#
# print("".join(list))
