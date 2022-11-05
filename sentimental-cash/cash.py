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
    balance_fn = balance_fd - 5*dimes
    #print(f"Balance from nickels is:{balance_fn}")

    # get number of pennies
    pennies = balance_fn

    #total number of coins
    total = quarters + dimes + nickels + pennies
    print(f"Total coins:{total}")







    # n_balance = d_balance - 5*calculate_nickel(d_balance)
    # p_balance = n_balance - calculate_penny(n_balance)
    # total_coins = q_balance + d_balance + n_balance + p_balance
    # print((f"Total coins is:{total_coins}"))


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


def calculate_quarters(amt):

    return int((amt) / 25)

def calculate_dimes(amt):

    return int((amt) / 10)

def calculate_nickel(amt):

    return int((amt) / 5)

def calculate_penny(amt):

    return amt

main()




# int calculate_quarters(int cents);
# int calculate_dimes(int cents);
# int calculate_nickels(int cents);
# int calculate_pennies(int cents);