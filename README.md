<!-- & This creates a banner for the ReadMe -->
<div align="center">
    <img src="img/maiden-gazing-green-eyes.png" alt="Wisteria Maiden" width="95%" height="530">
</div>

# <h1 align="center">🌸 Algorithms: The Art of Finding and Solving 🌸</h1>

## Practice: Searching, organizing, and solving problems step by step

### Understanding Algorithms: Learning how to design systemic approaches to find data and solve problems efficiently

<hr>

## <h2 align="center">💫 Overview</h2>

- [ ] <b>Algorithms</b> are step-by-step procedures for solving problems. They are the recipes that transform raw data into answers. In this lecture, I learned that algorithms are not abstract concepts reserved for computer scientists for they are practical tools I use every day. Whether I am searching for a name in a phonebook, drawing a pyramid, or deciding between iteration and recursion, algorithms shape how I approach problems. The beauty of algorithms is that there is often more than one way to solve a problem, and choosing the right approach makes all the difference.

<hr>

## <h2 align="center">🎨 Key Design Features</h2>

- [ ] <b>Linear Search</b>
    - [ ] Check each element one by one from start to finish until the target is found or the list ends.
    - [ ] Simple to implement but potentially slow for large datasets, and the worst case would mean checking every single element

- [ ] <b>String Comparison with strcmp()</b>
    - [ ] Unlike integers, strings cannot be compared with `==`. I must use `strcmp()` from `<string.h>`.
    - [ ] `strcmp()` returns `0` when strings match, a negative number if the first is less, and a positive number if greater.

- [ ] <b>Custom Data Types with typedef struct</b>
    - [ ] The `typedef` keyword lets me create my own data types, grouping related data together.
    - [ ] A `struct` bundles multiple values under one name, as in pairing a person's name with their phone number.
    - [ ] Access fields using dot notation: `people[0].name` and `people[0].number`.

- [ ] <b>Iteration vs. Recursion</b>
    - [ ] <b>Iteration</b> uses loops (`for`, `while`) to repeat actions, straightforward and memory-efficient.
    - [ ] <b>Recursion</b> is when a function calls itself, solving smaller versions of the same problem.
    - [ ] Every recursive function needs a <b>base case</b> to stop the recursion, or it will run forever.

- [ ] <b>Exit Status Codes</b>
    - [ ] Returning `0` from `main` signals success; returning non-zero (like `1`) signals an error.
    - [ ] These codes let the operating system and other programs know if my program completed its task.

<hr>

## <h2 align="center">🔍 Simple Practice: Real-World Thinking in C</h2>

- [ ] Before this lecture, I thought searching meant using some built-in function. Now I understand that I can build my own search algorithms. Linear search is like looking for a book on a messy shelf, as in I check each spine until I find the one I want.
- [ ] Comparing strings tripped me up at first. I kept trying to use `==` like I would with integers. Then I learned that strings are arrays of characters, so comparing them means comparing each character one by one. `strcmp()` does this for me, and understanding why made the function feel less like magic.
- [ ] The phonebook example changed how I think about organizing data. Instead of having two separate arrays, one for names and one for numbers. I can bundle them together in a `struct`. Now each person is a complete package, and I do not have to worry about the arrays getting out of sync.
- [ ] Recursion felt like a brain teaser at first. Why would a function call itself? But when I saw how drawing a pyramid of height `n` is just drawing a pyramid of height `n - 1` plus one more row, it clicked. Recursion is not really complicated, it is quite elegant. I just have to remember the base case.
- [ ] Exit status codes seem small, but they matter. They are how my program communicates with the world beyond itself. Returning `0` is like saying "mission accomplished". Returning `1` is like raising a flag that something went wrong.

<hr>

## <h2 align="center">👩🏾‍💻 C Code Outline</h2>
- [ ] <b>Linear Search for Integers</b>:
    - [ ] Searching through an array of numbers one by one to find a match.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            // & Create a simple Linear Search Algo for integers
            int numbers[] = {20, 500, 10, 5, 100, 1, 50};

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
        /*
            ~ The output:
                ~ Number: 100
                ~ Found
        */
        ```

- [ ] <b>Linear Search for Strings</b>:
    - [ ] Searching through an array of strings using `strcmp()` for comparison

        ```c
        #include <cs50.h>
        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            // & Create a linear search for strings of text instead of integers
            // ~ String of pieces from monopoly
            string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

            // ~ Ask the user for what string they are looking for
            string s = get_string("String: ");

            // ~ Run linear search to find the string given by the user
            for (int i = 0; i < 6; i++)
            {
                // ~ Use strcmp to compare the 2 strings character by character
                // ~ strcmp returns 0 when correct, otherwise neg. or pos. #
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
        /*
            ~ The output:
                ~ String: iron
                ~ Found
        */
        ```

- [ ] <b>Phonebook with Parallel Arrays</b>:
    - [ ] Using two seperate arrays to store names and numbers, then searching by name.

        ```c
        #include <cs50.h>
        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            // & Create a Phonebook
            string names[] = {"Kelly", "David", "John"};
            // ~ Write as string instead of int b/c the value also has non-digits
            string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

            // ~ Ask the user for the name they are looking for
            string name = get_string("Name: ");
            for (int i = 0; i < 3; i++)
            {
                // ~ Compare names[i] with name given by the user
                if (strcmp(names[i], name) == 0)
                {
                    // ~ Print the phone number at the same location of i
                    printf("Found: %s\n", numbers[i]);
                    // ~ Exit status = 0 -> means success
                    return 0;
                }
            }
            printf("Not found\n");
            // ~ Exit status = 1 -> means not successful
            return 1;
        }
        /*
            ~ The output:
                ~ Name: David
                ~ Found: +1-617-495-1000
        */
        ```

- [ ] <b>Phonebook with Structs</b>:
    - [ ] Creating a custom `person` data type to bundle names and numbers together.

        ```c
        #include <cs50.h>
        #include <stdio.h>
        #include <string.h>

        // ~ This is a C keyword that lets you create your own data type
        // ~ Creates a new data type called person with a name and a number
        typedef struct
        {
            string name;
            string number;
        } person;

        int main(void)
        {
            // ~ Create an array called people with room for 3 persons
            person people[3];

            // ~ Use '.' to go inside the structure and access attributes
            people[0].name = "Kelly";
            people[0].number = "+1-617-495-1000";

            people[1].name = "David";
            people[1].number = "+1-617-495-1000";

            people[2].name = "John";
            people[2].number = "+1-949-468-2750";

            // ~ Ask the user for the name they are looking for
            string name = get_string("Name: ");

            for (int i = 0; i < 3; i++)
            {
                // ~ Access the name of the ith person and compare it
                if (strcmp(people[i].name, name) == 0)
                {
                    // ~ Print out the number for that person
                    printf("Found %s\n", people[i].number);
                    // ~ Exit status 0 -> means it was successful
                    return 0;
                }
            }
            printf("Not found\n");
            // ~ Exit status 1 -> means it was not successful
            return 1;
        }
        /*
            ~ The output:
                ~ Name: John
                ~ Found +1-949-468-2750
        */
        ```

- [ ] <b>Drawing a Pyramid with Iteration</b>:
    - [ ] Using nested loops to print a Mario-style pyramid row by row.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        // ~ Prototype - Teach the compiler what the function will look like
        void draw(int n);

        int main(void)
        {
            // & Create a program that prints out a simple Mario Pyramid
            // ~ Ask the user for the height of the pyramid
            int height = get_int("Height: ");

            // ~ Assume this draw function has been created
            draw(height);
        }

        // ~ Create the function that will draw a pyramid of that height
        void draw(int n)
        {
            // ~ For each row of the Pyramid
            for (int i = 0; i < n; i++)
            {
                // ~ For each column of the Pyramid
                // ~ If i is 0 then i + 1 gives me 1 brick, then 2, etc.
                for (int j = 0; j < i + 1; j++)
                {
                    printf("#");
                }
                // ~ Between each row a new line will be printed
                printf("\n");
            }
        }
        /*
            ~ The output:
                ~ Height: 4
                ~ #
                ~ ##
                ~ ###
                ~ ####
        */
        ```

- [ ] <b>Drawing a Pyramid with Recursion</b>:
    - [ ] Re-implementing the pyramid using a function that calls itself.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        // ~ Prototype - Teach the compiler what the function will look like
        void draw(int n);

        int main(void)
        {
            // & Create a program that prints out a simple Mario Pyramid
            // ~ Ask the user for the height of the pyramid
            int height = get_int("Height: ");

            // ~ Assume this draw function has been created
            draw(height);
        }

        // ~ Use recursion as an alternative to iteration
        void draw(int n)
        {
            // & Want to print a pyramid of height n (n - 1 plus one more row)
            // ~ Base Case: if there is nothing to draw, return
            // ~ Use <= 0 to handle negative numbers
            if (n <= 0)
            {
                return;
            }

            // ~ Print a Pyramid of height n - 1
            draw(n - 1);

            // ~ Print one more row instead of having nested loops
            for (int i = 0; i < n; i++)
            {
                // ~ Print # (hash) one at a time
                printf("#");
            }
            // ~ End of this loop print out a new line
            printf("\n");
        }
        /*
            ~ The output:
                ~ Height: 4
                ~ #
                ~ ##
                ~ ###
                ~ ####
        */
        ```

<hr>

## <h2 align="center">✨ Encompassed Technologies</h2>

- [ ] <b>C Programming Language:</b>
    - [ ] The foundation that gives me the tools to implement algorithms directly. From loops and conditionals to recursion and custom data types, C teaches me how algorithms actually work under the hood.
- [ ] <b>CS50 Library:</b>
    - [ ] Provides `get_string()`, `get_int()`, and the `string` type, letting me focus on algorithm design rather than low-level memory management.
- [ ] <b>Standard Libraries:</b>
  - [ ] `<stdio.h>` for input/output operations like `printf()`.
  - [ ] `<string.h>` for string manipulation functions like `strcmp()` and `strlen()`.
- [ ] <b>GCC Compiler:</b>
    - [ ] Translates my C code into machine instructions, handling the memory allocation and function calls that make my algorithms run.
- [ ] <b>Terminal/Command Line:</b>
    - [ ] Where I compile my programs with `make`, execute them with `./program`, and pass command-line arguments directly to my programs turning my code into action as in checking exit status codes with `echo $?`. It is where my algorithms come to life.
- [ ] <b>VS Code:</b>
    - [ ] This is my coding sanctuary. A lightweight but powerful source code editor that provides an integrated terminal, syntax highlighting, extensions for writing and testing code efficiently.

