/*
 *  Project 1
 *  
 *  Adrian Brodzik
 *  Warsaw University of Technology
 */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: app [string]\n");
        printf("Example: ./app \"some string\"\n");

        return 0;
    }

    // Remember if the previous char was a space
    bool prevSpace = false;

    // Iterate over each char
    for (int i = 0; argv[1][i]; ++i)
    {
        // Replace a series of spaces with a single slash
        if (argv[1][i] == ' ')
        {
            if (!prevSpace)
            {
                printf("/");
                prevSpace = true;
            }
        }
        // Duplicate a slash if one already exists
        else if (argv[1][i] == '/')
        {
            printf("//");
            prevSpace = false;
        }
        // Leave all other chars unchanged
        else
        {
            printf("%c", argv[1][i]);
            prevSpace = false;
        }
    }

    printf("\n");

    return 0;
}

