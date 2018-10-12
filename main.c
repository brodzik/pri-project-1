/*
 *  [PRI] Project 1
 *  Replaces multiple white characters with a single slash, duplicates any existing slashes.
 *  
 *  Adrian Brodzik
 *  Warsaw University of Technology
 *  Faculty of Electronics and Information Technology
 */

#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Accept only one argument
    if (argc != 2)
    {
        printf("Usage: app [string]\n");
        printf("Example: ./app \"some string\"\n");

        return 0;
    }

    // Remember if the previous char was a space
    bool prevSpace = false;

    // Iterate over each char, print output char by char
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

