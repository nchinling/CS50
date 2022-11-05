# TODO

def main():
    height = get_height()
    j = 0
    for i in range(height):
        if (height - i) > j:
            for j in range(height - i):
                print("a", end="")

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