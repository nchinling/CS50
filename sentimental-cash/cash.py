# TODO

def main():
    # get amount from user
    amount = get_amount()

    print(f"Amount is {amount}")
    print(f"Quarters: {calculate_quarters(amount)}")
    balance = amount - calculate_quarters(amount)
    print(balance)


# function to get amount from user

def get_amount():
    while True:
        try:
            n = float(input("Amount($): "))
        except ValueError:
            print("That's not a change value!")

        else:
            if n <= 0:
                print("That's not a change value!")
            else:
                return int(100*n)


def calculate_quarters(amount):

    return int((amount) / 25)

def calculate_dimes(amount):

    return int((amount) / 10)

def calculate_nickel(amount):

    return int((amount) / 5)

def calculate_penny(amount):

    return int((amount) / 1)

main()




# int calculate_quarters(int cents);
# int calculate_dimes(int cents);
# int calculate_nickels(int cents);
# int calculate_pennies(int cents);