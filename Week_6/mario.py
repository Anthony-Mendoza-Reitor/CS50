from cs50 import get_int


def get_number():
    while True:
        try:
            n = int(get_int("Height: "))
            if (n >= 1 and n <= 8):
                return n
            else:
                print("Number out of range")
        except ValueError:
            print("Not a correct value")


n = get_number()

for i in range(1, n + 1):
    print(" " * (n-i), end="")
    print("#" * i, end="")
    print()
