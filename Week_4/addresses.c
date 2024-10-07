#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; //pointer 'p' that points 'n' address
    printf("%p\n", p); //prints 'n' address
    printf("%i\n", *p); //prints content of '*p' which is a loc
}
