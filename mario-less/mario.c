#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; //declare variable height

    //get height that mario needs to climb. Do-while lopp will execute at least once.
    do
    {
        height=get_int("Positive Number: ");


            printf("The height is %d\n",height);

    }
    while (height<1 || height>8);     //user will be reprompted for height

    //build left-aligned hashes


        for (height = 0;height <8;height++)
        {
           #printf("#\n");

        }

//int height =getint("Height:" %i)

    //if height < 0

   // while (height!=0)
    //{print #
    //counter = counter-1
    //Go new line}


}