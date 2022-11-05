# TODO
import string

def main():
    # get text from user
    text = get_text()
    total_letters = count_letters(text)
    total_words = count_words(text)
    total_sentences = count_sentences(text)

    print(f"Text is: {text}")
    print(f"Total letters: {total_letters}")
    print(f"Total words: {total_words}")
    print(f"Total sentences: {total_sentences}")


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

# function to count number of letters
def count_letters(text):

    number_of_letters = 0

    for letter in text:
        if letter.isalpha():
            number_of_letters += 1

    return number_of_letters


# function to count number of words
def count_words(text):

    number_of_spaces = 0
    number_of_words = 0

    for word in text:
        if word.isspace():
            number_of_spaces += 1

    number_of_words = number_of_spaces+1

    return number_of_words

# function to count number of words
def count_sentences(text):

    number_of_sentences = 0

    for char in text:
        if (char == "." or char == "?" or char == "!"):
            number_of_sentences += 1

    return number_of_sentences

# function to count number of words
def average_letters(text):


# run main function
main()
