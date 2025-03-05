#include<stdio.h>
#include<string.h>

void payment(int user_id){
int bus_no,seat_no;
printf("Enter bus number(1 to 5):" );
scanf("%d", &bus_no);

if(bus_no<1 || bus_no>5){
printf("invalid bus number.\n");
return;

}

printf("Enter seat number(1 to 50):");
scanf("%d",&seat_no);

if(seat_no<1||seat_no>50){
printf("invalid seat_number.\n");
return;

}

printf("payment successful for bus %d,seat %d.\n",bus_no,seat_no);



}









int main()
{
 payment("user_id");

}

