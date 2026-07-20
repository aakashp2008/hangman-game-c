#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[] = "PROGRAMMING";
    char guessed[20];
    char letter;
    int length = strlen(word);
    int attempts = 6;
    int correct = 0;

    for(int i = 0; i < length; i++)
        guessed[i] = '_';
    guessed[length] = '\0';

    printf("=====================================\n");
    printf("         HANGMAN GAME\n");
    printf("=====================================\n");

    while(attempts > 0)
    {
        printf("\nWord: ");
        for(int i = 0; i < length; i++)
            printf("%c ", guessed[i]);

        printf("\nRemaining Attempts: %d", attempts);
        printf("\nEnter a letter: ");
        scanf(" %c", &letter);

        letter = toupper(letter);

        int found = 0;

        for(int i = 0; i < length; i++)
        {
            if(word[i] == letter && guessed[i] == '_')
            {
                guessed[i] = letter;
                found = 1;
                correct++;
            }
        }

        if(found)
        {
            printf("\nCorrect Guess!\n");
        }
        else
        {
            attempts--;
            printf("\nWrong Guess!\n");
        }

        if(correct == length)
        {
            printf("\nCongratulations! You guessed the word.\n");
            printf("Word: %s\n", word);
            break;
        }
    }

    if(attempts == 0)
    {
        printf("\nGame Over!\n");
        printf("The correct word was: %s\n", word);
    }

    return 0;
}
