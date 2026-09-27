#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // & Create a linear search for stings of text instead of integers
    // ~ String of pieces from monoploy
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // ~ Ask the user for what string they are looking for
    string s = get_string("String: ");

    // ~ Run linear search to find the string given by the user -> use for loop
    for (int i = 0; i < 6; i++)
    {
        // if (strings[i] == s)
        // ~ Use strcamp to compare the 2 strings character by character to make sure they are the same
        // ~ Pass in one of thstrings
        // ~ Pass in the string from the user
        // ~ strcmp when correct will return 0, otherwise will return a neg. or pos. #
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            // ~ exit status 0 = success
            return 0;
        }
    }
    printf("Not found\n");
    // ~ exit status 1 = error
    return 1;
}
