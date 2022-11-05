# TODO
from cs50 import get_float

def main():
    # get amount from user
    amount = get_amount()

    print(f"Amount is {amount}")





# function to get height


def get_amount():
    while True:
        try:
            n = int(input("Amount($): "))
        except ValueError:
            print("That's not a change value!")
        else:
            if n > 0:
                return 100*n

main()

