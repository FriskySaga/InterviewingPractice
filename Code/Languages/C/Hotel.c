// Kevin Tran
// December 09, 2018
// A program to get myself comfortable with structs in C.


#include <stdio.h>


#define SIZE 10


struct hotel {
    int rooms[SIZE];
    int available;
};


int find_room(struct hotel *h);
void get_room(struct hotel *h);
void init_hotel(struct hotel *h);


// Rooms are open if they have an assigned value of 1.
int find_room(struct hotel *h) {

    for (int i = 0; i < SIZE; i++) {
        
        if (h->rooms[i] == 1) {
            return i;
        }
    }
    
    return -1;
}


void get_room(struct hotel *h) {

    int room_number = find_room(h);
    
    if (room_number == -1) {

        printf("Sorry, we are full.\n");
    }

    else {

        printf("You will stay in room %d.\n", room_number);
        h->available--;
        h->rooms[room_number] = 0;
    }
}


void init_hotel(struct hotel *h) {

    for (int i = 0; i < SIZE; i++) {

        h->rooms[i] = 1;
    }

    h->available = SIZE;
}


int main(void) {
    
    struct hotel plaza;
    init_hotel(&plaza);

    int ans;
    printf("Would you like to check out a room? (y = 1, n = 0)\n");
    scanf("%d", &ans);

    while (ans == 1) {
        get_room(&plaza);
        printf("Would you like to check out a room? (y = 1, n = 0)\n");
        scanf("%d", &ans);
    }
    
    return 0;
}


