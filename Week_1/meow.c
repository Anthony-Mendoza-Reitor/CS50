#include <stdio.h>
#include <cs50.h>

void meow(int n);

int main(void)
{
    int userInput = get_int("How many meows? ");
    meow(userInput);
}

void meow(int n)
{    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
