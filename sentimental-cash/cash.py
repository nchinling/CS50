# TODO

def main():
    # get amount from user
    amount = get_amount()

    print(f"Amount is {amount}")

    # get number of quarters
    quarters = calculate_quarters(amount)
    print(f"Quarters: {quarters}")

    # get balance from quarters
    balance_fq = amount - 25*calculate_quarters(amount)
    #print(f"Balance is:{balance_fq}")

    # get number of dimes
    dimes = calculate_dimes(balance_fq)
    print(f"Dimes is:{dimes}")

    # get balance from dimes
    balance_fd = balance_fq - 10*dimes
    #print(f"Balance from dimes is:{balance_fd}")

    # get number of nickels
    nickels = calculate_nickel(balance_fd)
    print(f"Nickels is:{nickels}")

    # get balance from nickels
    balance_fn = balance_fd - 5*nickels
    #print(f"Balance from nickels is:{balance_fn}")

    # get number of pennies
    pennies = balance_fn
    print(f"Pennies is:{pennies}")

    #total number of coins
    total = quarters + dimes + nickels + pennies
    print(f"Total coins:{total}")

# function to get amount from user
def get_amount():
    while True:
        try:
            n = float(input("Change owed($): "))
        except ValueError:
            print("That's not a change value!")

        else:
            if n <= 0:
                print("That's not a change value!")
            else:
                return int(100*n)

# function to get amount from user
def calculate_quarters(amt):

    return int((amt) / 25)

# function to get amount from user
def calculate_dimes(amt):

    return int((amt) / 10)

# function to get amount from user
def calculate_nickel(amt):

    return int((amt) / 5)

# # function to return penny
# def calculate_penny(amt):

#     return amt

# run the program
main()
