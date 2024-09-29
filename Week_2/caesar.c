#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype Functions
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n"); // Since there's more than 1 argument
        return 1;
    }
    else
    {
        for (int i = 0; i < (strlen(argv[1])); i++)
        {
            char C = argv[1][i];
            if (C < 48 || C > 57)
            {
                printf("Usage: ./caesar key \n"); // Since it's not a integer
                return 1;
            }
        }
        // User Input
        string plaintext = get_string("plaintext: ");
        encrypt(plaintext, argv[1]);
        printf("\n");
    }
}

void encrypt(string plaintext, string key)
{
    int k = atoi(key);
    int cal;
    int tlen = strlen(plaintext);
    if (k > 26)
    {
        k = (k % 26);
    }
    printf("this is the key: %i \n", k);
    char cyphertext[tlen];
    for (int i = 0; i < (tlen); i++)
    {
        char L = plaintext[i];
        if (L > 96 && L < 123) // Lowercase letters
        {
            printf("This is L:%c ~ #:%i \n", L, L);
            if (L + k > 122)
            {
                cal = (k + L - 122) + 96;
                printf("This is mod L:%c >> #:%i \n", L, cal);
            }
            else
            {
                cal = k + L;
            }
        }
        else if (L > 64 && L < 91) // Uppercase letters
        {
            if (L > 90)
            {
                cal = (k + L - 122) + 63;
                printf("This is mod L:%c >> #:%i \n", L, cal);
            }
            else
            {
                cal = k + L;
            }
        }
        else
        {
            cal = L;
        }
        cyphertext[i] = cal;
    }
    printf("ciphertext: ");
    int counterp = 0;
    while (counterp < tlen)
    {
        printf("%c", cyphertext[counterp]);
        counterp++;
    }
}
