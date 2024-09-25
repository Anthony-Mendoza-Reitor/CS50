#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Promp user for positive integer
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n <=0);

    //Generates a n-by-n grid of '#'
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
