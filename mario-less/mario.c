#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; //declare variable height

    //get height that mario needs to climb. Do-while lopp will execute at least once.
    do
    {
        height=get_int("Height: ");


    }
    while (height<1 || height>8);     //user will be reprompted for height

    //build left-aligned hashes


//to iterate rows
for (int i=0;i < height;i++)
        {

        for (int j=0;j < height;j++)  //iterate columns
        {
            if(j<height-1)
                printf(" ");
            else
                printf("#");

        }

        printf(" \n");
        }
printf(" \n");

}