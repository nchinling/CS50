# TODO

def main():
    height = get_height()
    for i in range(height):
        for j in range(height - i):
            if (height - i) > j + 1:
                print("", end="")
            else:
                print("#", end="")
        print()


def get_height():
    while True:
        try:
            n = int(input("Height: "))
        except ValueError:
            print("That's not an integer!")
        else:
            if n > 0:
                return n

main()