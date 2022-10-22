#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float l = letters / words * 100;
    float s = sentences / words * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int i = strlen(text);
    float total_letters = 0;
    for (int j = 0; j < i; j++)
    {
        if (isalpha(text[j]))
        {
            total_letters++;
        }
    }
    return total_letters;
}

int count_words(string text)
{
    float z = strlen(text);
    float total_words = 1;
    for (int w = 0; w < z; w++)
    {
        if (text[w] == ' ')
        {
            total_words++;
        }
    }
    return total_words;
}

int count_sentences(string text)
{
    float h = strlen(text);
    float total_sentences = 0;
    for (int e = 0; e < h; e++)
    {
        if ((text[e] == '.') || (text[e] == '!') || (text[e] == '?'))
        {
            total_sentences++;
        }
    }
    return total_sentences;
}
