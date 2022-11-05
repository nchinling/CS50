# TODO

# run main function
main()

def main():
    # get text from user
    text = get_text()

    print(f"Text is: {text}")

# function to get text from user
def get_text():
    while True:
        try:
            s = input("Provide text: ")
        except ValueError:
            print("That is not a text!")

        else:
            return s

# run main function
main()
