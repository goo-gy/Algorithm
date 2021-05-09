string = input()
string_bomb = input()

fixed_string = ""
matching_indexes = []

for char in string:
    if(char == string_bomb[0]):
        matching_indexes.append(1)
        if(matching_indexes[-1] == len(string_bomb)):
            matching_indexes.pop()
    elif(len(matching_indexes) > 0 and char == string_bomb[matching_indexes[-1]]):
        matching_indexes[-1] += 1
        if(matching_indexes[-1] == len(string_bomb)):
            matching_indexes.pop()
    else:
        for length in matching_indexes:
            fixed_string += string_bomb[:length]
        fixed_string += char
        matching_indexes = []

for length in matching_indexes:
    fixed_string += string_bomb[:length]
if(len(fixed_string) == 0):
    print("FRULA")
else:
    print(fixed_string)