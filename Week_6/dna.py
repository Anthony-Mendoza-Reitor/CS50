import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage 'python dna.py file.csv'")
    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        readD = csv.DictReader(file)
        for data in readD:
            database.append(data)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        readS = csv.DictReader(file)
        sequence = str(readS.fieldnames)
    # TODO: Find longest match of each STR in DNA sequence
    # TODO: Check database for matching profiles
    for i in range(len(database)):
        count = 0
        for j in range(1, len(readD.fieldnames)):
            if (int(database[i][readD.fieldnames[j]]) == longest_match(sequence, readD.fieldnames[j])):
                count += 1
                # print(f"Matching: {database[i]["name"]} pairs {readD.fieldnames[j]} with data base with a value of: {longest_match(sequence, readD.fieldnames[j])}")
            if (count == (len(readD.fieldnames) - 1)):
                print(database[i]["name"])
                return (database[i]["name"])
    else:
        print("no match")
        return ("no match")


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
