x = (1, 2)
even_fibs = [2]
while (x[0] < 4e6) or (x[1] < 4e6):
    next_val = lambda a, b : a + b
    new_num = next_val(x[0], x[1])
    if new_num % 2 == 0: even_fibs.append(new_num)
    x = (x[1], new_num)

print(sum(even_fibs))