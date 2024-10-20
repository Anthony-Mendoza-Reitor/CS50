from cs50 import get_float


def get_number():
    while True:
        try:
            n = get_float("Change: ")
            if (n >= 0):
                num = float("%.2f" % n)
                num *= 100
                return num
            else:
                print("Number out of range")
        except ValueError:
            print("Not a correct value")


def calculate_change(num):
    counter = 0

    while num > 0:
        if (num / 25 >= 1):
            num -= 25
            counter += 1
        elif (num / 10 >= 1):
            num -= 10
            counter += 1
        elif (num / 5 >= 1):
            num -= 5
            counter += 1
        elif (num / 1 >= 1):
            num -= 1
            counter += 1
    return counter


num = get_number()
change = calculate_change(num)
print(change)
