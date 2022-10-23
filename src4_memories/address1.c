// Prints address of first char of a string

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    char c = s[1];
    char *p = &c;
    printf("%d\n", *p);
}
