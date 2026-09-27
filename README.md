<!-- & This creates a banner for the ReadMe -->
<div align="center">
    <img src="img/wisteria-maiden.png" alt="Wisteria Maiden" width="95%" height="475">
</div>

# <p align="center">🌸 Algorithms: The Art of Finding and Solving 🌸</p>

## Practice: Searching, organizing, and solving problems step by step

### Understanding Algorithms: Learning how to design systemic approaches to find data and solve problems efficiently

<hr>

## <p align="center">💫 Overview</p>

- [ ] <b>Algorithms</b> are step-by-step procedures for solving problems. They are the recipes that transofrm raw data into answers. 

<hr>

## <p align="center">🎨 Key Design Features</p>

- [ ] <b>Array Declaration and Initialization</b>
    - [ ] Create an array with `type name[size];` like `int scores[3];` for three integers.
    - [ ] Initialize specific elements with `scores[0] = 72;` or all at once with `int scores[] = {72, 73, 33};`.

- [ ] <b>Array Indexing</b>
    - [ ] Access elements using zero-based indexing. The first elements is at index 0, the last at `size - 1`.
    - [ ] If I forgot this and go past the end, I'll access random memory or worse, cause a crash.

- [ ] <b>Strings as Character Arrays</b>
    - [ ] In C, a `string` is just an array of characters ending with a special `0` (NUL) character marketing the end.
    - [ ] This is why I can access individual characters with `s[0]`, `s[1]`, etc.

- [ ] <b>Command-Line Arguments</b>
    - [ ] `main` can take `int argc` (argument count) and `string argv[]` (argument vector array) to accept inputs when the program starts.
    - [ ] This is how programs get data without prompting the user interactively.

- [ ] <b>Array Length Tracking</b>
    - [ ] Unlike higher-level languages, C does not know how long an array is. I must pass the length explicitly to functions.
    - [ ] `strlen()` is a helper from `<sting.h` that counts characters until it hits `\0`.

<hr>

## <p align="center">🔍 Simple Practice: Real-World Thinking in C</p>

- [ ] Before arrays, I had to hardcode evey score: `score1`, `score2`, `score3`. With arrays, I simply say `scores[i]` inside a loop and process any number of values. It turns a chore into a pattern.

- [ ] Strings are a perfect example. I have been using them all along without realizing they are just arrays of characters. When I type `"HI!"`, C stores it as `['H', 'I', '!', '\0']`. Thay final `\0` is like a period at the end of a sentence telling me the string is complete.

- [ ] `strlen()` is not magic. It is just a loop that counts characters until it sees that `\0`. Understanding this demystifies the library functions I have been relying on.

- [ ] Command-line arguments let me build professional-looking programs. Instead of `get_string()` interrupting the flow, I can just run `./greet Roro` and have the program instantly respond. It is like giving instructions right at the start.

- [ ] Converting between uppercase and lowercase used to be tedious manual math. Now I know that `'A'` is ASCII 65 and `'a'` is ASCII 97, they are exactly 32 apart. Or better yet, I just use `toupper()` from `<ctype.h>`and let the pros handle it.

<hr>

## <p align="center">👩🏾‍💻 C Code Outline</p>
- [ ] <b>Scores with Arrays</b>:
    - [ ] Storing multiple scores in an array, then calculating their average.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            const int N = 3;
            int scores[N];

            for (int i = 0; i < N; i++)
            {
                scores[i] = get_int("Score: ");
            }

            printf("AverageL %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
        }

        /*
            ~ The output:
                ~ Score: 72
                ~ Score: 73
                ~ Score: 33
                ~ Average: 59.333333
        */
        ```

- [ ] <b>Average Function with Array Parameter</b>:
    - [ ] Extracting the average logic into a reusable function, passing both the array and its length.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        float average(int length, int numbers[]);

        int main(void)
        {
            const int N = 3;
            int scores[N];

            for (int i = 0; i < N; i++)
            {
                scores[i] = get_int("Score: ");
            }

            printf("Average: %f\n", average(N, scores));
        }

        float average(int length, int numbers[])
        {
            int sum = 0;
            for (int i = 0; i < length; i++)
            {
                sum += numbers[i];
            }
            return sum / (float) length;
        }
        /*
            ~ The output:
                ~ Score: 72
                ~ Score: 73
                ~ Score: 33
                ~ Average: 59.333333
        */
        ```

- [ ] <b>String as Character Arrays</b>:
    - [ ] Understanding that a string is just an array of characters, ending with `0`.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            string s = 'HI!';

            printf("%c%c%c\n", s[0], s[1], s[2]);
            printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
        }

        /*
            ~ The output:
                ~ HI!
                ~ 72 73 33 0
        */
        ```

- [ ] <b>Array of Strings</b>:
    - [ ] Creating a two-dimensional structure, where each string is itself an array.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(void)
        {
            string words[2];
            words[0] = "HI!";
            words[1] = "BYE!";

            printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
            printf("%c%c%%cc\n", words[0][0], words[0][1], words[0][2]. words[0][3]);
        }

        /*
            ~ The output:
                ~ HI!
                ~ BYE!
        */
        ```

- [ ] <b>Computing String Length</b>:
    - [ ] Manually counting characters by lookin for `\0`, then using the built-in `stlen()`.

        ```c
        #include <cs50.h>
        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            string name = get_string("Name: ");

            int n = 0;
            while (name[n] != '\0')
            {
                n++
            }
            printf("%i\n", n);

            // ~ Or simply:
            printf("%i\n", strlen(name));
        }

        /*
            ~ The output:
                ~ Name: Roro
                ~ 4
                ~ 4
        */
        ```

- [ ] <b>Iterating Through a String</b>:
    - [ ] Using a `for` loop with `strlen()` to access each character individually.

        ```c
        #include <cs50.h>
        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            string s = get_string("Input:  ");

            printf("Output: ");
            for (int i = 0; n = strlen(s); i < n; i++)
            {
                printf("%c", s[i]);
            }
            printf("\n");
        }

        /*
            ~ The output:
                ~ Input:  hello
                ~ Output: hello
        */
        ```

- [ ] <b>Converting to Uppercase</b>:
    - [ ] Lowercase letters in ASCII are 32 greater than their uppercase counterparts. Or use `toupper()` from `<ctype.h>`.

        ```c
        #include <cs50.h>
        #include <ctype.h>
        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            string s = get_string("Before: ");

            printf("After: ");
            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (islower(s[i]))
                {
                    printf("%c", toupper(s[i]));
                }
                else
                {
                    printf("%c", s[i]);
                }
            }
            printf("\n");
        }

        /*
            ~ The output:
                ~ Before: hello
                ~ After:  HELLO
        */
        ```

- [ ] <b>Command-Line Arguments</b>:
    - [ ] Accepting user input directly when the program starts, instead of prompting during execution.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(int argc, string argv[])
        {
            if (aargc == 2)
            {
                printf("hello, %s\n", argv[1]);
            }
            else
            {
                printf("hello, word\n");
            }
        }

        /*
            ~ The output:
                ~ $ ./greet Roro
                ~ hello, Roro
        */
        ```

- [ ] <b>Exit Status Codes</b>:
    - [ ] Returning values from `main` to signal success (0) or failure (non-zero) to the operating system.

        ```c
        #include <cs50.h>
        #include <stdio.h>

        int main(int argc, string argv[])
        {
            if (arg != 2)
            {
                printf("Missing command-line argument\n");
                return 1; // ~ Error
            }
            printf("hello, %s\n", argv[1]);
            return 0; // ~ Success
        }

        /*
            ~ The output:
                ~ $ ./status
                ~ Missing command-line argument
                ~ $ echo $?
                ~ 1
        */
        ```

<hr>

## <p align="center">✨ Encompassed Technologies</p>

- [ ] <b>C Programming Language:</b>
    - [ ] The foundation that gives me precise control over how data is stored and accessed in memory. Arrays are on of C's most fundamental data stuctures, teaching me how compilers organize collections of information.
- [ ] <b>CS50 Library:</b>
    - [ ] Provides `get_string()`, `get_int()`, and the `string` type, making it easy to work with arrays and strings without getting bogged down in low-level pointer mechanics.
- [ ] <b>Standard Libraries:</b>
  - [ ] `<stdio.h>` for input/output operations.
  - [ ] `<string.h>` for strings manipulation functions like `strlen()`.
  - [ ] `<ctype.h>` for character classification and conversion functions like `toupper()` and `islower()`.
- [ ] <b>GCC Compiler:</b>
    - [ ] Translate my C code with arrays into machine instructions that allocate memory, index into arrays, and perform operations efficiently.
- [ ] <b>Terminal/Command Line:</b>
    - [ ] Where I compile my programs with `make`, execute them with `./program`, and pass command-line arguments directly to my programs turning my code into action
- [ ] <b>VS Code:</b>
    - [ ] This is my coding sanctuary. A lightweight but powerful source code editor that provides an integrated terminal, syntax highlighting, extensions for writing and testing code efficiently.

