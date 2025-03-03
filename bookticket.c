#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_BUSES 5
#define MAX_SEATS 10

char users[MAX_USERS][50]; 
char passwords[MAX_USERS][50]; 
int user_count = 0; 

int bus_capacity[MAX_BUSES] = {50, 50, 50, 50, 50}; 
char bus_source[MAX_BUSES][50] =      {"Delhi", "  MUmbai", " Lucknow", "  Jaipur", "    Gurgoan"};
char bus_destination[MAX_BUSES][50] = {" Lucknow", "Delhi", " Ayodhya", "   Paryagraj", " Ambedkarnagar"};
int booked_seats[MAX_BUSES][MAX_SEATS] = {0}; 

void menu();
void registerUser();
int loginUser();
void showBusDetails();
void bookTicket(int user_id);
void cancelTicket(int user_id);
void payment(int user_id);

void menu() {
    int choice, user_id;
    
    while (1) {
        printf("\n*** Bus Reservation System ***\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                user_id = loginUser();
                if (user_id != -1) {
                    int action;
                    while (1) {
                        printf("\nWelcome, %s\n", users[user_id]);
                        printf("1. View Bus Details\n");
                        printf("2. Book Ticket\n");
                        printf("3. Cancel Ticket\n");
                        printf("4. Make Payment\n");
                        printf("5. Logout\n");
                        printf("Enter your choice: ");
                        scanf("%d", &action);
                        
                        switch (action) {
                            case 1:
                                showBusDetails();
                                break;
                            case 2:
                                bookTicket(user_id);
                                break;
        
                            case 3:
                                printf("Logging out...\n");
                                break;
                            default:
                                printf("Invalid choice! Try again.\n");
                        }
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
            
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void registerUser() {
    if (user_count < MAX_USERS) {
        printf("Enter username: ");
        scanf("%s", users[user_count]);
        printf("Enter password: ");
        scanf("%s", passwords[user_count]);
        user_count++;
        printf("Registration successful!\n");
    } else {
        printf("User limit reached. Cannot register more users.\n");
    }
}

int loginUser() {
    char username[50], password[50];
    int i;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    for (i = 0; i < user_count; i++) {
        if (strcmp(username, users[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            printf("Login successful! Welcome, %s\n", username);
            return i;
        }
    }
    printf("Invalid username or password.\n");
    return -1;
}

void showBusDetails() {
    printf("\nBus Details:\n");
    printf("Bus No | Capacity | Source | Destination\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        printf("%d\t%d\t\t%s\t%s\n", i+1, bus_capacity[i], bus_source[i], bus_destination[i]);
    }
}

void bookTicket(int user_id) {
    int bus_no, seat_no;
    printf("Enter bus number (1 to 5): ");
    scanf("%d", &bus_no);
    
    if (bus_no < 1 || bus_no > 5) {
        printf("Invalid bus number.\n");
        return;
    }

    printf("Enter seat number (1 to 50): ");
    scanf("%d", &seat_no);
    
    if (seat_no < 1 || seat_no > 50) {
        printf("Invalid seat number.\n");
        return;
    }

    if (booked_seats[bus_no - 1][seat_no - 1] == 0) {
        booked_seats[bus_no - 1][seat_no - 1] = 1;
        printf("Ticket booked successfully for Bus %d, Seat %d.\n", bus_no, seat_no);
    } else {
        printf("Sorry, this seat is already booked.\n");
    }
}
int main()
{
    menu();
    return 0;
}