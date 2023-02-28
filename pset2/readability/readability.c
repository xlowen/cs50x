#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)

{
    //get input from user
    string text = get_string("Text: ");

    //number of letters
    float letters = count_letters(text);
    //number of words
    float words = count_words(text);
    //number of sentences
    float sentences = count_sentences(text);

    //print the number of letters, words and sentences
    //printf("%f letter(s)\n", letters);
    //printf("%f word(s) \n", words);
    //printf("%f sentence(s) \n", sentences);
    
    //Calculate the average number of letters per 100 words
    float lavg = letters / words * 100;
    //Calculate the average number of sentences per 100 words
    float savg = sentences / words * 100;
    //Calculates the Coleman-Liau Index
    float grade = 0.0588 * lavg - 0.296 * savg - 15.8;
    
    //Cast float grade to int gradeint
    int gradeint = round(grade);
    
    //Print the results of the Index
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeint);
    }
    

    
    //print the grade based on the Coleman-Liau index.
    //printf( "%f \n", lavg);
    //printf("%f \n", savg);
    //printf("grade: %f \n", round (grade));
}

int count_letters(string text)
{
    int countl = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            countl++;
        }
    }
    return countl;
}
int count_words(string text)
{
    int countw = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            countw++;
        }
    }
    countw = countw + 1;
    return countw;
}
int count_sentences(string text)
{
    int counts = 0;
    char p1 = 33;
    char p2 = 46;
    char p3 = 63;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == p1 || text[i] == p2 || text[i] == p3)
        {
            counts++;
        }
    }
    return counts;
}




