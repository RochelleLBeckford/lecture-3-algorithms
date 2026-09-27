#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // & Create a Phonebook
    string names[] = {"Kelly", "David", "John"};
    // ~ Write as string instead of int b/c the value also has non-digits within it
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // ~ Ask the user for the name they are looking for
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // ~ Compare the string in names[i] w/ name given by the user to see if they are the same
        // ~ When strcmp return value is 0 -> means it is true
        if (strcmp(names[i], name) == 0)
        {
            // ~ Will print the phone number at the same location of i in the numbers[]
            printf("Found: %s\n", numbers[i]);
            // ~ Exit status = 0  -> means success
            return 0;
        }
    }
    printf("Not found\n");
    // ~ Exit status - 1 -> means not successful
    return 1;
}

typedef struct
{
    string name;
    string number;
}
person;

