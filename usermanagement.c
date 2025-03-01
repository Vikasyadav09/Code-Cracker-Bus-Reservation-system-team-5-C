#include<stdio.h>
#include<string.h>
#include<ctype.h>

void usermanagement();
void menu();
void login();
//void busmanagement();
//void bookingdetails();
//void payment();
int option;
char passward[20];
char name[50];


void menu()
{
    char ch;
while(1)
{
printf("***************************** : BUS RESERVATION SYSTEM :*");

printf("\n Chosse any option");
printf("\n Enter 1 for for user management details");
printf("\n Enter 2 for Bus details management");
printf("\n Enter 3 for booking information management");
printf("\n Enter 4 for payment details management  ");
printf("\n Enter 0 for exit the program");
printf("\n Enter any option : ");
while(scanf("\n%d", &option) !=1)
{
while((ch = getchar()) !='\n' && ch !=EOF);
printf("\n Please enter only number :");


}
break;}

if(option ==1)
{
    usermanagement();
    login();
}
}


void usermanagement()
{
 int i=0;
 char email[50];
printf("\n First Resister :");
printf("\nEnter your Email id");
scanf("%s",&email);
while(1){
printf("\n Plese enter your name :");
scanf(" %s", &name);
while (name[i] != '\0') {
    if (!isalpha(name[i])) {
        printf("\n Invalid name. Please enter only alphabetic characters.");
        break;
    }
    i++;
}

if(name[i] == '\0') {
 
    break;
}
}
printf("\n Please enter password :");
scanf("%10s",&passward);

    printf("\n RAGISTRACTION SUCESSFULL");
    printf("\nYour name is : %s",name);
    printf("\nyour passward is :%s",passward);

}

 void login(){
    char username[50];
    char password[10];

if(passward==0)
{
    printf("\n first register then login");

}

else
{
while(1){
   printf("\nLogin here");
   printf("\nPlese enter your name :");
   scanf("%s", &username);
   printf("\nEnter your password");
   scanf("%10s",password);
   if(strcmp(username ,name)==0 && strcmp(password ,passward)==0)

   {
    printf("\nLogin Sucessfull");
    break;
   }
   else{
    printf("\nwrong username or password try again");
   }

}  
}

}
int main()
{
    menu();
}