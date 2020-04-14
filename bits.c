#include <stdio.h>
#include <stdlib.h>

void toBinary(int n);
void toBin(int n);

int main()
{
    int n = 16;

    toBinary(n);
    
    n = 123456789;
    toBinary(n);
    toBin(n);
    
    return 0;
}

/* toBinary: converts integer to binary */
void toBinary(int n)
{
    int binary[32], i;

    for (i = 0; n > 0; i++)
    {
        binary[i] = n % 2;
        n /= 2;
    }

    for (i = i - 1; i >= 0; i--)
        printf("%d", binary[i]);
    printf("\n");
}

/* toBin: converts integer to binary using bit manipulation */
void toBin(int n)
{
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    printf("\n");
}
