# TODO

def main():
    # get text from user
    text = get_text()
    total_letters = count_letters(text)

    print(f"Text is: {text}")
    print(f"Total letters: {total_letters}")

    printf


# function to get text from user
def get_text():
    while True:
        try:
            s = input("Provide text: ")
        except ValueError:
            print("That is not a text!")

        else:
            return s

# function to calculate index
def cal_index(L, S):

    index = 0.0588 * L - 0.296 * S - 15.8
    return index

# function to calculate index
def count_letters(text):

    number_of_letters = len(isalpha(text))
    return number_of_letters


# run main function
main()
