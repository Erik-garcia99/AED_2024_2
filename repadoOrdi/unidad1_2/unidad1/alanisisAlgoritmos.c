#include <stdio.h>

void funcionA(char c);
void funcionB(char c);

int main(void)
{
    printf("\n");
    funcionA('Z');
    printf("\n");
}

void funcionA(char c)
{
    if (c > 'A')
    {
        funcionB(c);
    }
    printf("%c", c);
}

void funcionB(char c)
{
    funcionA(--c);
}