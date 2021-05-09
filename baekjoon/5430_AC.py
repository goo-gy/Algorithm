def solution():
    commands = input()
    N = int(input())
    numbers = eval(input())
    # solution
    is_reversed = False
    for command in commands:
        if(command == 'R'):
            is_reversed = not is_reversed
        else:
            if(len(numbers) == 0):
                print("error")
                return
            if(is_reversed):
                numbers.pop()
            else:
                numbers.pop(0)
    if(is_reversed):
        numbers.reverse()
    result = '[' + ','.join(map(str, numbers)) + ']'
    print(result)
    
T = int(input())

for i in range(T):
    solution()