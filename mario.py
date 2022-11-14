from cs50 import get_int
import sys

height = get_int("Height: ")
while height < 1 or height > 8:
    print("Input a number between 1 and 8 please!")
    sys.exit(1)

for row in range(height):
    for space in range (height - row - 1):
        print(" ", end="")
    for hash in range (row + 1):
        print("#", end="")
    print("\n", end="")
