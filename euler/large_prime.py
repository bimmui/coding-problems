# this doesnt work, get back to it later

num = 600851475143
base_factors = [7, 5, 3, 2]
is_divisible_by = lambda a, b: a % b == 0

while True:
    print(num)
    if is_divisible_by(num, base_factors[0]):
        num = num / base_factors[0]
    elif is_divisible_by(num, base_factors[1]):
        num = num / base_factors[1]
    elif is_divisible_by(num, base_factors[2]):
        num = num / base_factors[2]
    elif is_divisible_by(num, base_factors[3]):
        num = num / base_factors[3]
    else:
        break
    print(num)

print(num)