#include <cs50.h>
#include <stdio.h>
#include <string.h>

// ~ This is a C keyword that lets you create your own data type
// ~ This will create a new data type called person & assume each person has a string called name and a string called number
typedef struct
{
    string name;
    string number;
 } person;

int main(void)
{
    // ~ Create an array called people inside of which has room for 3 persons inside of which each person has a name and a number
    person people[3];

    // ~ Go into the array people at location 0 and access the name field
    // ~ '.' tells you to go inside of that structure and access that strcuture name attribute
    people[0].name = "Kelly";
    // ~ Go back into that 0 location and set the number for that person
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-617-495-1000";

    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    // ~ Ask the user for the name they are looking for
    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        // ~ people[i].name to go access the name of that ith person and compare it to the name given by the user
        // ~ When strcmp returns 0 -> means it is true
        if (strcmp(people[i].name, name) == 0)
        {
            // ~ When I find that person will go to that location and print out the number
            printf("Found %s\n", people[i].number);
            // ~ Exit status 0 -> means it was succesful
            return 0;
        }
    }
    printf("Not found\n");
    // ~ Exit status 1 -> means it was not succesful
    return 1;
}

