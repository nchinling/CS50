#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; //declare variable height

    //get height that mario needs to climb. Do-while lopp will execute at least once.
    do
    {
        height=get_int("Enter positive integer between 1 and 8:");


    }
    while (height<1 || height>8);     //user will be reprompted for height

    //build left-aligned hashes

for (int i=0;i < height;i++)
        {

        for (int j=0;j < height;j++)
        {
           printf("#");

        }
        printf(" \n");
        }
printf(" \n");

}