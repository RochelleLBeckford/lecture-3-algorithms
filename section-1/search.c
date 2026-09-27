#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // & Create a simple Linear Search Algo for integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50 };

    // ~ Ask user for the number that they want to search for
    int n = get_int("Number: ");

    // ~ Run linear search to find that number -> use a for loop
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            // ~ 0 = success -> exit status
            return 0;
        }
    }
    printf("Not found\n");
    // ~ 1 = did not find the number
    return 1;
}
