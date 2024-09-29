#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// This are the prototypes functions
int letterCounter(string text);
int wordCounter(string text);
int sentenceCounter(string text);

int main(void)
{
    // User text input
    string text = get_string("Text: ");
    // Calling all the counting functions based on user input
    int nLetter = letterCounter(text);
    int nWord = wordCounter(text);
    int nSentence = sentenceCounter(text);

    // Calculates Coleman-Liau index
    float L = ((nLetter * 100.0000) / nWord);
    float S = ((nSentence * 100.0000) / nWord);
    float CLI = ((0.0588 * L) - (0.296 * S) - 15.8);
    int index = round(CLI);

    // Logic for the ouputs
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// This function counts the letters in text
int letterCounter(string text)
{
    int letterCount = 0;
    for (int i = 0; i < (strlen(text)); i++)
    {
        char L = toupper(text[i]);
        if (L > 64 && L < 91)
        {
            letterCount++;
        }
    }
    return letterCount;
}

// This function counts the words in text
int wordCounter(string text)
{
    int wordCount = 0;
    for (int i = 1; i < (strlen(text)); i++)
    {

        char C = text[i]; // Current
        if (C == 32)
        {
            wordCount++;
        }
    }
    printf("Wordcounter # %i\n", wordCount);
    return (wordCount + 1);
}

// This function counts the sentences in text
int sentenceCounter(string text)
{
    int sentenceCount = 0;
    for (int i = 1; i < (strlen(text)); i++)
    {
        char C = text[i]; // Current
        if (C == 46 || C == 33 || C == 63)
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}
