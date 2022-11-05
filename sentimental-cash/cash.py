# TODO

def main():
    # get height from user
    height = get_height()

    # print number of rows
    for i in range(height):
        # print number of blank spaces
        for j in range(height - (i+1)):
            print(" ", end="")
        # print #
        for k in range(i+1):
            print("#", end="")

        print()

# function to get height


def get_height():
    while True:
        try:
            n = int(input("Height: "))
        except ValueError:
            print("That's not an integer!")
        else:
            if n > 0 and n < 9:
                return n


main()

