# TODO
import re

# Loop to check each card through regex
while True:
    # get input from user
    cc = input("Credit Card Number: ")
    # conditionals to check each card
    if re.match("^4[0-9]{12}(?:[0-9]{3})?$", cc):
        print("VISA\n")
        break
    elif re.match("^(?:5[1-5][0-9]{2}|222[1-9]|22[3-9][0-9]|2[3-6][0-9]{2}|27[01][0-9]|2720)[0-9]{12}$", cc):
        print("MASTERCARD\n")
        break
    elif re.match("^3[47][0-9]{13}$", cc):
        print("AMEX\n")
        break
    else:
        print("INVALID\n")
        break