# TODO
# prompt user for height as an int
height = 0
while True:
    try:
        height = int(input("Desired height? "))
    except ValueError:
        print("Type an integer between 1 and 8")
    if int(height) < 1 or int(height) > 8:
        print("this is not an integer between 1 and 8")
    else:
        break

# print pyramid
height = int(height)

for y in range(int(height)):
    print(" " * int(height - 1), end="")
    print("#" * int(y + 1), end="")
    print("  ", end="")
    print("#" * int(y + 1))
    height = int(height - 1)