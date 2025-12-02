#include <stdlib.h> // required for rand() and srand()
#include <stdio.h>
#include <string.h>
#include <time.h> // required for time()

int main() {

    srand(time(NULL)); /* time(NULL) returns the current time in second since the Epoch 
                        and makes the sequence of "random" numbers different every time
                        the program runs */ 
    int lower_bound = 1;
    int upper_bound = 10;
    /* rand() % (max - min + 1) + min generates a number */
    int secretNumber = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

    int guess = 0;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;
    int guessesLeft = 3;
    char inputBuffer[100]; // Buffer to read string input

    printf("Guess the secret number, between 1 - 10 (You have 3 attempts!)\n");

    while(guess != secretNumber && outOfGuesses == 0) {
        if(guessCount < guessLimit) {
            printf("Please enter a number : ");

            // Read input as a string (up to 99 characters)
            if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
                // Attempt to convert the string to an integer
                // sscanf returns 1 if it successfully reads an integer
                if (sscanf(inputBuffer, "%d", &guess) == 1) {
                    // Valid integer was scanned.
                    // The guess will be checked by the main while loop condition later.
                } else {
                    // Invalid input (non-integer or other format error)
                    printf("Invalid input! This counts as a guess.\n");
                    // The 'guess' variable retains its previous value (e.g., 0)
                    // so the main loop condition continues.
                }
            } else {
                // Handle input error (less common in simple programs)
                printf("Input error!\n");
            }
            
            // In either case (valid or invalid), a guess attempt is consumed
            guessCount += 1;
            guessesLeft -= 1;
            
            if (guess != secretNumber && guessCount < guessLimit) {
                printf("Guesses left: %d\n", guessesLeft);
            }

        } else {
            outOfGuesses = 1;
        }
    }

    // Final message logic
    if(guess == secretNumber) {
        printf("\n***** Well done, you guessed the right number! *****\n\n");
    } else {
        printf("\n~~~~~ Unlucky, you ran out of guesses! ~~~~~\n");
        printf("\n The Secret Number was %d\n\n", secretNumber);
    }

    return 0;
}
