# TODO
import cs50
import re

text = cs50.get_string("Text: ")


def main():
    # number of letters
    letters = count_letters(text)
    # number of words
    words = count_words(text)
    # number of  sentences
    sentences = count_sentences(text)
    print(sentences)

    # calculate the average of letters and sentences
    lavg = letters / words * 100
    savg = sentences / words * 100
    # apply the Coleman-Liau index
    grade = 0.0588 * lavg - 0.296 * savg - 15.8
    # rounds the grade so it is an int
    gradeint = round(grade)

    # print grades
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Grade", gradeint)

# Counts how many letters in text using a for loop


def count_letters(text):
    return len([x for x in text if x.isalpha()])

# counts the number of words using the strip/split functions


def count_words(text):
    return (len(text.strip().split(" ")))

# counts the number of sentences using regex and split function


def count_sentences(text):
    sentence = (re.split(r'[.|!|?]', text))
    return(len(sentence) - 1)


main()