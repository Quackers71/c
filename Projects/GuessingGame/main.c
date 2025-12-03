#include <stdlib.h> // required for rand() and srand()
#include <stdio.h>
#include <string.h>
#include <time.h> // required for time()


/* define some stuff */
#define LOWER_BOUND 1
#define UPPER_BOUND 10
#define MAX_ATTEMPTS 3
#define GUESS_LIMIT 3
#define INPUT_BUFFER_SIZE 100


int main() {

    srand(time(NULL)); /* time(NULL) returns the current time in second since the Epoch 
                        and makes the sequence of "random" numbers different every time
                        the program runs */ 
    
    /* rand() % (max - min + 1) + min generates a number */
    int secretNumber = (rand() % (UPPER_BOUND - LOWER_BOUND + 1)) + LOWER_BOUND;

    int guess = 0;
    int guessCount = 0;
    int guessLimit = GUESS_LIMIT;
    int outOfGuesses = 0;
    int guessesLeft = MAX_ATTEMPTS;
    char inputBuffer[INPUT_BUFFER_SIZE]; // Buffer to read string input

    printf("Guess the secret number, between 1 - 10 (You have 3 attempts!)\n");

    while(guess != secretNumber && outOfGuesses == 0) {
        if(guessCount < guessLimit) {
            printf("Please enter a number : ");

            // Read input as a string (up to 99 characters)
            if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
                // Attempt to convert the string to an integer
                // sscanf returns 1 if it successfully reads an integer
                if (sscanf(inputBuffer, "%d", &guess) == 1) {

                    if (guess < LOWER_BOUND || guess > UPPER_BOUND) {
                        printf("Input is out of range! This counts as a guess.\n");
                    }
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
