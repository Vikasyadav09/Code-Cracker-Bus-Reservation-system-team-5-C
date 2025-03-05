#include<stdio.h>
#include<string.h>
#include<ctype.h>

void usermanagement();
void menu();
void login();
void busmanagement();
void bookingdetails();
void payment();
void exit();
int option;
char passward[20];
char name[50];
char destination[50];

void menu()
{
    char ch;
while(1){
printf("\n***************************** : BUS RESERVATION SYSTEM :*****************************");

printf("\n Chosse any option");
printf("\n Enter 1 for for user management details");
printf("\n Enter 2 for Bus details management");
printf("\n Enter 3 for booking information management");
printf("\n Enter 4 for payment details management  ");
printf("\n Enter 0 for exit the program");

while(1){
printf("\n Enter any option : ");
while(scanf("\n%d", &option) !=1)
{
while((ch = getchar()) !='\n' && ch !=EOF);
printf("\n Please enter only number :");


} break;}
if(option==1)
{
    printf("\nRegister and login");
    
}
else if (option==2)
{
printf("\nBus details");
}
else if (option==3)
{
    printf("\nBokking information");
}
else if (option==4)
{
    printf("\nPayment details");
}
else if (option==0)
{
    printf("\n exit or logout");
    break;
}
}


}




int main()
{
    menu();
    
    
}