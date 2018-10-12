/*
 *  [PRI] Project 1
 *  Replaces multiple whitespace characters with a single slash, duplicates any existing slashes.
 *  
 *  Adrian Brodzik
 *  Warsaw University of Technology
 *  Faculty of Electronics and Information Technology
 */

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

    // Iterate over each char, print output char by char
    for (int i = 0; argv[1][i]; ++i)
    {
        // If the current char is whitespace
        if (argv[1][i] == ' ')
        {
            // Replace it only if it's the first whitespace char of a series,
            // i.e. the previous char wasn't a whitespace
            if ((i > 0 && argv[1][i - 1] != ' ') || i == 0)
            {
                printf("/");
            }
        }
        // Duplicate a slash if one already exists
        else if (argv[1][i] == '/')
        {
            printf("//");
        }
        // Leave all other chars unchanged
        else
        {
            printf("%c", argv[1][i]);
        }
    }

    printf("\n");

    return 0;
}

