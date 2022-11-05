# TODO

def main():
    # get amount from user
    amount = get_amount()

    print(f"Amount is {amount}")
    print(f"Quarters: {calculate_quarters(amount)}")
    balance_fq = amount - 25*calculate_quarters(amount)
    print(f"Balance is:{balance_fq}")

    d_balance = balance_fq - calculate_dimes(balance_fq)


    n_balance = d_balance - 5*calculate_nickel(d_balance)
    p_balance = n_balance - calculate_penny(n_balance)
    total_coins = q_balance + d_balance + n_balance + p_balance
    print((f"Total coins is:{total_coins}"))


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


def calculate_quarters(q):

    return int((q) / 25)

def calculate_dimes(d):

    return int((d) / 10)

def calculate_nickel(n):

    return int((n) / 5)

def calculate_penny(p):

    return int((p) / 1)

main()




# int calculate_quarters(int cents);
# int calculate_dimes(int cents);
# int calculate_nickels(int cents);
# int calculate_pennies(int cents);