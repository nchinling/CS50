#include <stdio.h>
#include <cs50.h>

//main program
int main(void)
{
    printf("hello, world\n");   //prints "hello world"
    string name = get_string("What is your name?\n"); //Obtain user's name
    printf("hello, %s\n", name);  //prints with name
}
