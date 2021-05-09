def get_sum(formula_plus):
    numbers = formula_plus.split('+')
    number_sum = 0
    for number in numbers:
        number_sum += int(number)
    return number_sum

formula = input()
N = int(len(formula)/2)
formulas = formula.split('-')

result = get_sum(formulas[0])
for formula_plus in formulas[1:]:
    result -= get_sum(formula_plus)
print(result)