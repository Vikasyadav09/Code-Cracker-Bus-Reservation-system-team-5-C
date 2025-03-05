#include <stdio.h>
#include <string.h>

#define BASE_FARE 50
#define RATE_PER_KM 10 

// Function to calculate fare
float calculateFare(float distance) {
    return (RATE_PER_KM * distance);
}
int processPayment(float amount) {
    int choice;
    
    while (1) {
        printf("\n========== Payment Options ========== :");
        printf("\nPress 1 for Credit card ");
        printf("\nPress 2 for Debit Card ");
        printf("\nPress 3 for UPI ");
        printf("\nPress 4 for Wallet ");
        printf("\nSelect Payment Method (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Processing Payment of ₹%.2f...\n", amount);
            printf("Payment Successful!\n");
            return 1;
        } else {
            printf("Invalid Payment Option. Please try again.\n");
        }
    }
}

// Function to generate booking invoice
 void generateInvoice(char name[], char pickup[], char drop[], float distance, float fare) {
    printf("\n=============== Booking Invoice ===============\n");
    printf("\nPassenger Name: %s", name);
    printf("\nPickup Location: %s", pickup);
    printf("\nDrop Location: %s", drop);
    printf("\nDistance: %.2f km\n", distance);
    printf("\nTotal Fare: $ %.2f\n", fare);
    printf("Payment Status: Paid\n");
    printf("==============================\n");
}


int main() {
    char name[50], pickup[50], drop[50];
    float distance, fare;

    printf("Enter Passenger Name: ");
    scanf("%s",&name);
    printf("\nEnter Pickup Location: ");
    scanf("%s",&pickup);
    printf("\nEnter Drop Location: ");
    scanf("%s",&drop);

    printf("\nEnter Distance (km): ");
    while (scanf("%f", &distance) != 1 || distance <= 0) {
        printf("Invalid input! Enter a valid distance in km: ");
        while (getchar() != '\n');
    }

    fare = calculateFare(distance);
    printf("\nTotal Fare: $ %.2f\n", fare);

    if (processPayment(fare)) {
        generateInvoice(name, pickup, drop, distance, fare);
    } else {
        printf("Payment Failed! Please Retry.\n");
    }

    return 0;
}