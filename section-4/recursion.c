#include <cs50.h>
#include <stdio.h>

// ~ Prototype - Teach the compiler what the function I am calling is going to look like
void draw(int n);

int main(void)
{
    // & Create a program that prints out a simple Mario Pyramid

    // ~ Ask the user for the height of the pyramid
    int height = get_int("Height: ");

    // ~ Assume this draw function has been created
    draw(height);
}

// ~ Create the function that will draw(print out) pyramid of that height given by the user
    // ~ Can use recursion as an alternative to iteration by re-implementing the draw function itself
void draw(int n)
{
    // & Want to print a pyramid of height n (really n - 1 plus one more row)
    // ~ Ask ourselves if there is anything to draw: Base Case
        // ~ Will not do anything at all
        // ~ Use <= 0 to handle incase a user gives me a negative number and thus nothing will print as well
        // ~ Ensures that when keep calling draw and it gets smaller and smaller when it hits 0 the program will end
    if (n <= 0)
    {
        return;
    }

    // ~ Print a Pyramid of height n - 1
    draw(n - 1);

    // ~ Print one more row instead of having nesting loops
    for (int i = 0; i < n; i++)
    {
        // ~ Print # (hash) one at a time
        printf("#");
    }
    // ~ End of this loop print out a new line
    printf("\n");
}
