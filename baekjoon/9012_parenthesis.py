def solution():
    input_string = input()
    stack_count = 0
    for parenthesis in input_string:
        if(parenthesis == "("):
            stack_count += 1
        else:
            stack_count -= 1
            if(stack_count < 0):
                break
    if(stack_count == 0):
        print("YES")
    else:
        print("NO")
            
T = int(input())

for i in range(T):
    solution()