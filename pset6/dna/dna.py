import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: '.csv file' 'DNA sequence file' ")

    # TODO: Read database file into a variable

    with open(sys.argv[1], "r") as csvfile:
        csvdict = csv.DictReader(csvfile)
        mydict = list(csvdict)

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2], "r") as dnaseq:
        dnastr = dnaseq.read()

    # TODO: Find longest match of each STR in DNA sequence
    # populate a list with the STRs in the csv file
    z = 1
    strs = []
    while z < len(mydict[0]):
        strs.append(list(mydict[1])[z])
        z += 1

    # populate the list with the longest match of each STR in the DNA sequence file
    i = 0
    longlist = []
    while i < len(strs):
        longlist.append(longest_match(dnastr, strs[i]))
        i += 1

    # TODO: Check database for matching profiles
    for k in range(len(mydict)):
        equal = 0
        for j in range(1, len(csvdict.fieldnames)):
            if int(longlist[j - 1]) == int(mydict[k][csvdict.fieldnames[j]]):
                equal += 1
            if equal == (len(csvdict.fieldnames) - 1):
                print(mydict[k]['name'])
                exit(0)

    print("No match")
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
