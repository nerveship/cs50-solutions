#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string digits);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    string digits = argv[1];
    int key = atoi(argv[1]); // converts the string into an int
    if (argc != 2) //checks if the user inputs a single input as the command line and rejects it if not
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (only_digits(digits)) //makes sure the command line argument is a number
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string plaintext;
    plaintext = get_string("plaintext: "); //prompts the user for plaintext
    int n = strlen(plaintext);
    int ciphertext[n];
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

bool only_digits(string digits)
{
    int length = strlen(digits);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(digits[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return ((c + n) % 26);
        //return (c - 65) + n % 26 + 65; <- wrong!?!?!?!?!
    }
    else if (islower(c))
    {
        return ((c + n) % 26);
        //return (c - 97) + n % 26 + 97; <- also wrong
    }
    else
    {
        return c;
    }
}
