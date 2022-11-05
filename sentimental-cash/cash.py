# TODO

def main():
    # get amount from user
    amount = get_amount()

    print(f"Amount is {amount}")





# function to get height

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


main()




int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);