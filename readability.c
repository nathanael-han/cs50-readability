// This program determines the reading level of a given text.

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)

// Get input text from user
{
    string text = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Finds the letter, word and sentence count

    for (int i = 0, len = strlen(text); i < len ; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters += 1;
        }

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences += 1;
        }

        if (text[i] == ' ')
        {
            words += 1;   // This find the number of spaces
        }
    }

    // Adds 1 to number of spaces to get the number of words.
    words += 1;



    // Calculates the Coleman-Liau Index

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Prints the grade level from the Coleman-Liau Index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
}
