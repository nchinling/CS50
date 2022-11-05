# TODO

def main():
    height = get_height()
    for i in range(height):
        for j in range(height - i):
            while (height - i) > j:
                print("a", end="")
                j = j + 1
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