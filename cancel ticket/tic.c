#include <stdio.h>
#include <stdlib.h>

#define MAX_SEATS 10

int seats[MAX_SEATS] = {0}; // 0 means available, 1 means booked

void displaySeats() {
    printf("\nSeats Status (0 = Available, 1 = Booked):\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %d\n", i + 1, seats[i]);
    }
}

void bookSeats() {
    int n, seatNumber;
    
    printf("\n please enter how many seat book? ");
    scanf("%d", &n);

    printf("Enter seat numbers (1-%d) separated by space: ", MAX_SEATS);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seatNumber);
        
        if (seatNumber < 1 || seatNumber > MAX_SEATS) {
            printf("Invalid seat number: %d\n", seatNumber);
            continue;
        }
        if (seats[seatNumber - 1] == 1) {
            printf("Seat %d already booked!\n", seatNumber);
        } else {
            seats[seatNumber - 1] = 1;
            printf("Seat %d booked successfully!\n", seatNumber);
        }
    }
}

void cancelSeats() {
    int n, seatNumber;
    
    printf("\nplease enter how many seat book? ");
    scanf("%d", &n);

    printf("Enter seat numbers (1-%d) separated by space: ", MAX_SEATS);
    for (int i = 0; i < n; i++) {
        scanf("%d", &seatNumber);
        
        if (seatNumber < 1 || seatNumber > MAX_SEATS) {
            printf("Invalid seat number: %d\n", seatNumber);
            continue;
        }
        if (seats[seatNumber - 1] == 0) {
            printf("Seat %d is not booked yet!\n", seatNumber);
        } else {
            seats[seatNumber - 1] = 0;
            printf("Seat %d booking canceled successfully!\n", seatNumber);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Booking & Ticketing System ---\n");
        printf("1. View Seats\n");
        printf("2. Book Seats\n");
        printf("3. Cancel Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeats();
                break;
            case 3:
                cancelSeats();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
