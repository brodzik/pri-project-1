/*
 *  Project 1
 *  
 *  Adrian Brodzik
 *  Warsaw University of Technology
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// App entry point
int main(int argc, char *argv[])
{
    // Accept exactly one input string
    if (argc != 2)
    {
        // Print correct app usage
        printf("Usage: app [string]\n");
        printf("Example: ./app \"some string\"\n");

        // Exit app with errors
        return -1;
    }

    // Prepare input and output string variables
    char *input = argv[1];
    char output[1024] = "";
    int j = 0;

    // State variable; true if the previous char was a space, else false
    bool prevSpace = false;

    // Iterate over each char until we hit a null terminator
    for (int i = 0; input[i]; ++i)
    {
        if (input[i] == ' ')
        {
            if (!prevSpace)
            {
                output[j++] = '/';
                prevSpace = true;
            }
        }
        else if (input[i] == '/')
        {
            output[j++] = '/';
            output[j++] = '/';
            prevSpace = false;
        }
        else
        {
            output[j++] = input[i];
            prevSpace = false;
        }
    }

    // Print output string
    printf("%s\n", output);

    // Exit app with no errors
    return 0;
}

