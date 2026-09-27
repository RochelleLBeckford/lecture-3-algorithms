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
void draw(int n)
{
    // ~ For each row of the Pyramid
    for (int i = 0; i < n; i++)
    {
        // ~ For each column of the Pyramid
        // ~ If i is 0 then i + 1 will give me 1 brick, then 2 bricks then so on. To make sure that I am getting bricks
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // ~ Between each of the rows a new line will be printed
        printf("\n");
    }
}
