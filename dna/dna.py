import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database = []

    with open(sys.argv[1]) as datafile:
        read_database = csv.DictReader(datafile)
        for data in read_database:
            database.append(data)
        print(f"{database}")

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as textfile:
        dnaseq = textfile.read()
        print(dnaseq)

    # TODO: Find longest match of each STR in DNA sequence

    # obtain key values from database
    subsequence = database[0].keys()

    # form change dictionary key values to a list
    full_list = list(subsequence)

    # remove 'name' from list
    subsequence_list = list(full_list[1:])

    # for debugging
    print(subsequence_list)
    print(len(subsequence_list))

    count = 0
    str_freq = []
    while (count < len(subsequence_list)):
        print(longest_match(dnaseq, subsequence_list[count]))
        str_freq.append(longest_match(dnaseq, subsequence_list[count]))
        count += 1
    print(str_freq)

    # TODO: Check database for matching profiles

    person = list(database[0].values())
    print(person)


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
