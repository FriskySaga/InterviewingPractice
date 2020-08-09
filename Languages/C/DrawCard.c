/*
    Kevin Tran & Jose Iciano
    The purpose of this program is to allow the user to randomly draw a card from a deck of 52 cards.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_CARDS_IN_SUIT 13
#define NUM_CARDS_IN_DECK 52

// All function prototypes.
int ask_user_to_draw(void);
int card_exists_in_suit(int suit[], int cardIndex);
void determine_card(int index, int display);
void draw_card(int cloves[], int diamonds[], int hearts[], int spades[]);
void draw_card_wrapper(int cloves[], int diamonds[], int hearts[], int spades[]);
int get_base(int suitType);
char *get_suit_string(int suitType);
void give_to_hand(int cardIndex, int base);
void make_suit(int suit[]);
int randomize(int min, int max);
void show_card(int suitType, int cardIndex);
void show_deck(int cloves[], int showCloves, int diamonds[], int showDiamonds, int hearts[], int showHearts, int spades[], int showSpades);
void show_hand(void);
void show_suit(int suit[], int suitType);
void take_card(int suit[], int suitType, int cardIndex);

// This global array contains data on which card the user has.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
// 1 - 13 cloves will take up indices 0 - 12.
// 1 - 13 diamonds will take up indices 13 - 25.
// 1 - 13 hearts will take up indices 26 - 38.
// 1 - 13 spades will take up indices 39 - 51.
int hand[NUM_CARDS_IN_DECK] = {0};

///=========================================================================================================================================

// Ask the user whether they would like to draw a card.
// Returns 1 if the user would like to draw a card. Else, returns 0.
int ask_user_to_draw(void) {
    char answer;
    printf("\nWould you like to draw? Indicate by pressing 'Y' or 'N'.\n\n");
    scanf(" %c", &answer);

    // If the user wishes to draw, then return 1 to indicate they wish to draw a card.
    if (answer == 'Y' || answer == 'y') {
        printf("\n");
        return 1;
    }

    // Up to you, Jose, if you want to implement the case that user enters 'N' or if they enter something else entirely different.
    else {
        return 0;
    }
}


// Check if the card exists.
// Return 1 if the card exists. Else, return 0.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
int card_exists(int cloves[], int diamonds[], int hearts[], int spades[], int suitType, int cardNumber) {
    if (suitType == 1) {
        if (card_exists_in_suit(cloves, cardNumber - 1) == 1) {
            return 1;
        }
    }
    else if (suitType == 2) {
        if (card_exists_in_suit(diamonds, cardNumber - 1) == 1) {
            return 1;
        }
    }
    else if (suitType == 3) {
        if (card_exists_in_suit(hearts, cardNumber - 1) == 1) {
            return 1;
        }
    }
    else {
        if (card_exists_in_suit(spades, cardNumber - 1) == 1) {
            return 1;
        }
    }
}


// Check if the cards exists within the suit.
// Return 1 if the card exists. Else, return 0.
int card_exists_in_suit(int suit[], int cardIndex) {
    if (suit[cardIndex] == 1) {
        return 1;
    }
    else {
        return 0;
    }
}


// Determine the suit and number of the card based on the given index.
// If display is 1, print the card to the console.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
// 1 - 13 cloves will take up indices 0 - 12.
// 1 - 13 diamonds will take up indices 13 - 25.
// 1 - 13 hearts will take up indices 26 - 38.
// 1 - 13 spades will take up indices 39 - 51.
void determine_card(int index, int display) {
    int suitType;

    // Cloves
    if (index >= 0 && index <= 12) {
        suitType = 1;
    }

    // Diamonds
    else if (index >= 13 && index <= 25) {
        suitType = 2;
    }

    // Hearts
    else if (index >= 26 && index <= 38) {
        suitType = 3;
    }

    // Spades
    else if (index >= 39 && index <= 51) {
        suitType = 4;
    }

    // Display the card.
    if (display == 1) {
        show_card(suitType, index % 13);
    }
}


// Draw a card.
void draw_card(int cloves[], int diamonds[], int hearts[], int spades[]) {
    int suitType, cardNumber;

    // Randomly select a suit type and suit number to be drawn.
    // Keep selecting another card if that card has already been drawn.
    do {

        suitType = randomize(1, NUM_SUITS);
        cardNumber = randomize(1, NUM_CARDS_IN_SUIT);
    } while (card_exists(cloves, diamonds, hearts, spades, suitType, cardNumber) == 0);

    // Draw the card. Subtract 1 to account for the fact that array indices start at 0.
    // 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
    if (suitType == 1) {
        take_card(cloves, suitType, cardNumber - 1);
    }

    else if (suitType == 2) {
        take_card(diamonds, suitType, cardNumber - 1);
    }

    else if (suitType == 3) {
        take_card(hearts, suitType, cardNumber - 1);
    }

    else if (suitType == 4) {
        take_card(spades, suitType, cardNumber - 1);
    }
}


// Wrapper function to handle the case that the user draws a card.
void draw_card_wrapper(int cloves[], int diamonds[], int hearts[], int spades[]) {
    int drawAnswer;

    // Keep on asking the user whether they would like to draw a card.
    do {
        // Prompt the user whether they would like to draw a card.
        drawAnswer = ask_user_to_draw();

        // Handle the case the user wants to draw a card.
        if (drawAnswer == 1) {
            printf("Drawing Card...\n");
            draw_card(cloves, diamonds, hearts, spades);

            printf("\nShowing deck...\n");
            show_deck(cloves, 1, diamonds, 1, hearts, 1, spades, 1);
            printf("================================\n");

            show_hand();
        }

        // Up to you, Jose, if you want to handle the case that the user does not want to draw.
    } while (drawAnswer == 1);
}


// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
// 1 - 13 cloves will take up indices 0 - 12.
// 1 - 13 diamonds will take up indices 13 - 25.
// 1 - 13 hearts will take up indices 26 - 38.
// 1 - 13 spades will take up indices 39 - 51.
int get_base(int suitType) {
    if (suitType == 1) return 0;
    else if (suitType == 2) return 13;
    else if (suitType == 3) return 26;
    else return 39;
}


// 1 - 13 cloves will take up indices 0 - 12.
// 1 - 13 diamonds will take up indices 13 - 25.
// 1 - 13 hearts will take up indices 26 - 38.
// 1 - 13 spades will take up indices 39 - 51.
// Give the card to the user's hand.
void give_to_hand(int cardIndex, int base) {
    hand[base + cardIndex] = 1;
}


// Return the string indicating the suit type.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
char *get_suit_string(int suitType) {
    // 'Cloves', 'Hearts', and 'Spades' are each 6 characters long, but 'Diamonds' is 8 characters long.
    // Compensate for the size of the character array with the longest string.
    static char suit[9];

    if (suitType == 1) {
        strcpy(suit, "Cloves");
    }

    else if (suitType == 2) {
        strcpy(suit, "Diamonds");
    }

    else if (suitType == 3) {
        strcpy(suit, "Hearts");
    }

    else if (suitType == 4) {
        strcpy(suit, "Spades");
    }

    return suit;
}


/*
    MAIN FUNCTION
    1. Create all 52 cards.
    2. Allow the user to draw a card.
*/
int main(void) {
    // Create the deck of 52 cards (in alphabetical order).
    int cloves[13], diamonds[13], hearts[13], spades[13];
    make_suit(cloves);
    make_suit(diamonds);
    make_suit(hearts);
    make_suit(spades);

    // Show the deck of cards.
    printf("Showing Deck...\n");
    show_deck(cloves, 1, diamonds, 1, hearts, 1, spades, 1);
    printf("================================\n");

    // Allow the user to draw a card.
    draw_card_wrapper(cloves, diamonds, hearts, spades);

    return 0;
}


// Given a suit, make the cards for that suit.
// We will have 1 of each card in each suit.
void make_suit(int suit[]) {
    for (int i = 0; i < NUM_CARDS_IN_SUIT; i++) {
        suit[i] = 1;
    }
}


// Given the minimum and maximum values, randomly select a value within this range.
int randomize(int min, int max) {
    // Seed the random number generator.
    srand(time(0));

    // Generate a random number.
    // E.g., 1 + rand() % 13 generates a range from 1 through 13,
    // because rand() generates a range from 0 to 32,767 in most cases,
    // and rand() % 13 generates a range from 0 through 12,
    // so adding 1 to this number gives us a range from 1 through 13.
    return min + rand() % max;
}


// Print the card number and its suit.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
void show_card(int suitType, int cardIndex) {
    // Get the suit string.
    char *suit = get_suit_string(suitType);

    // To match up the card number and the index of the array given, add 1.
    int cardNumber = cardIndex + 1;

    // Print the card number of the given card type.
    switch (cardNumber) {
        case 1:
            printf("Ace of %s\n", suit);
            break;

        case 2:
            printf("2 of %s\n", suit);
            break;

        case 3:
            printf("3 of %s\n", suit);
            break;

        case 4:
            printf("4 of %s\n", suit);
            break;

        case 5:
            printf("5 of %s\n", suit);
            break;

        case 6:
            printf("6 of %s\n", suit);
            break;

        case 7:
            printf("7 of %s\n", suit);
            break;

        case 8:
            printf("8 of %s\n", suit);
            break;

        case 9:
            printf("9 of %s\n", suit);
            break;

        case 10:
            printf("10 of %s\n", suit);
            break;

        case 11:
            printf("Joker of %s\n", suit);
            break;

        case 12:
            printf("Queen of %s\n", suit);
            break;

        case 13:
            printf("King of %s\n", suit);
            break;

        default:
            printf("\nFuck you!\n");
            break;
    }
}


// Show the deck of cards for the suits that we want to show.
// This makes the function more customizable.
// For example, say if we only wanted to show diamonds and spades rather than all four suits.
void show_deck(int cloves[], int showCloves, int diamonds[], int showDiamonds,
               int hearts[], int showHearts, int spades[], int showSpades)
{
    // Show cloves.
    if (showCloves == 1) {
        show_suit(cloves, 1);
        printf("\n");
    }

    // Show diamonds.
    if (showDiamonds == 1) {
        show_suit(diamonds, 2);
        printf("\n");
    }

    // Show hearts.
    if (showHearts == 1) {
        show_suit(hearts, 3);
        printf("\n");
    }

    // Show spades.
    if (showSpades == 1) {
        show_suit(spades, 4);
        printf("\n");
    }
}


// Show the user's hand.
void show_hand(void) {
    printf("Showing hand...\n");

    // Loop through all indices inside the hand array.
    for (int i = 0; i < NUM_CARDS_IN_DECK; i++) {
        // If an index is marked as 1, that means the user has that card.
        // Find out which card it is.
        if (hand[i] == 1) {
            determine_card(i, 1);
        }
    }

    printf("================================\n");
}


// Show the given suit, as determined by the value of suitType.
// 1 indicates cloves, 2 indicates diamonds, 3 indicates hearts, 4 indicates spades
void show_suit(int suit[], int suitType) {
    for (int i = 0; i < NUM_CARDS_IN_SUIT; i++) {
        // Only show cards that exist.
        if (suit[i] == 1) {
            show_card(suitType, i);
        }
    }
}


// Draw the card and give it to the hand.
void take_card(int suit[], int suitType, int cardIndex) {
    // Get the base to determine the index number.
    int base = get_base(suitType);

    // Give the card to the user's hand.
    give_to_hand(cardIndex, base);

    // Indicate that this card in this suit no longer exists.
    suit[cardIndex] = 0;
}

