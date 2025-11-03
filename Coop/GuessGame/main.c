#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int secretNumber = 5;
    int guess = 0;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;
    int guessesLeft = 3;
    char inputBuffer[100]; // Buffer to read string input

    printf("Guess the secret number\n");

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
        printf("You guessed the right number!\n");
    } else {
        printf("You ran out of guesses!\n");
    }

    return 0;
}
