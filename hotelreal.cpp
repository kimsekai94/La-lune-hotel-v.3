#include<iostream>
#include <ctime>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>

#define max 100
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext(){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext(){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext(){SetConsoleTextAttribute(hConsole, 14);  };
void darktext(){SetConsoleTextAttribute(hConsole, 8);  };
using namespace std;

bool Menupricelist = true;
int number;

class Customer
{
    public:
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    double ServiceCharge;
    int booking_id;
};


class Room
{
    public:
    string type;
    string stype;
    string ac;
    int roomNumber;
    int rent;
    int status;

    class Customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void deleteRoom(int);
    void displayRoom(Room);
};


class Room rooms[max];
int count=0;

Room Room::addRoom(int rno)
{
    class Room room;
    room.roomNumber=rno;
    cout<<"\n\t\tType AC/Non-AC (Yes=Y/No=N) : ";
    cin>>room.ac;
    cout<<"\n\t\tType Room (Single=S/Double=D) : ";
    cin>>room.type;
    cout<<"\n\t\tType Size (Big=B/Small=S) : ";
    cin>>room.stype;
    cout<<"\n\t\tDaily Rent : ";
    cin>>room.rent;
    room.status=0;
    greentext();
    cout<<"\n\t\tRoom Added Successfully!";
    getch();
    return room;
}


void Room::searchRoom(int rno)
{
    int i,found=0;
    for(i=0;i<count;i++){
        if(rooms[i].roomNumber==rno){
        found=1;
        break;
        }
    }
    if(found==1)
    {   
        cout<<"\n\t\t---Room Details---\n";
        if(rooms[i].status==1){
        redtext();
        cout<<"\n\t\tRoom is Reserved";
        }else{
            greentext();
            cout<<"\n\t\tRoom is available";
            }
    whitetext();
    displayRoom(rooms[i]);
    getch();
    }else{
    cout<<"\nRoom not found";
    getch();
    }
}

void Room::displayRoom(Room tempRoom)
{
    cout<<"\n\t\tRoom Number : \t"<<tempRoom.roomNumber;
    cout<<"\n\t\tType AC/Non-AC (Yes=Y/No=N) : "<<tempRoom.ac;
    cout<<"\n\t\tType Room (Single=S/Double=D) : "<<tempRoom.type;
    cout<<"\n\t\tType Size (Big=B/Small=S) : "<<tempRoom.stype;
    cout<<"\n\t\tRent : "<<tempRoom.rent;
}


class HotelMgnt:protected Room
{
    public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

    if(count==0){
        redtext();
        cout<<"\n\t\t No Guest in Hotel !!";
    } 
    for(int i=0;i<count;i++){
        if(rooms[i].status==1){
            cout<<"\n\t\t Customer Name : "<<rooms[i].cust.name;
            cout<<"\n\t\t Room Number : "<<rooms[i].roomNumber;
            cout<<"\n\t\t Address (only city) : "<<rooms[i].cust.address;
            cout<<"\n\t\t Phone : "<<rooms[i].cust.phone;
            cout<<"\n\t\t Enter Check In Date (DD-MM-YY): "<<rooms[i].cust.from_date;
            cout<<"\n\t\t Enter Check Out Date (DD-MM-YY): "<<rooms[i].cust.to_date;
            greentext();
            cout<<"\n\t\t==================================================================="; 
            whitetext();
        }
    
    }
    getch();
}


void HotelMgnt::checkIn(){
    system("cls");

    int i,found=0,rno,k;
    string j;
    char Parking ; 
    char gym;
    double parkingCost;
    double gymCost;


    class Room room;
    cout<<"\n\t\tEnter Room number : ";
    cin>>rno;
    for(i=0;i<count;i++){
        if(rooms[i].roomNumber==rno){
            found=1;
            break;}
    }if(found==1){
        if(rooms[i].status==1){
            redtext();
            cout<<"\n\t\tRoom is already Booked";
            getch();
            return;
        }

        cout<<"\n\t\tEnter booking id(Number 4 digit): ";
        rooms[i].cust.booking_id =rand()%8999+1000;
        cout <<  rooms[i].cust.booking_id <<"\n";

        cout<<"\n\t\tEnter Customer Name (First Name): ";
        cin>>rooms[i].cust.name;

        cout<<"\n\t\tEnter Address (only city): ";
        cin>>rooms[i].cust.address;

        cout<<"\n\t\tEnter Phone: ";
        cin>>rooms[i].cust.phone;

        cout<<"\n\t\tEnter Check In Date (DD-MM-YY): ";
        cin>>rooms[i].cust.from_date;

        cout<<"\n\t\tEnter Check Out Date (DD-MM-YY): ";
        cin>>rooms[i].cust.to_date;
        
        cout <<"\n\t\tEnter Service : ";
        do {
        cout << "\n\t\tDo you want a parking spot during your stay? ";
        cin >> Parking;
        if (Parking == 'Y' || Parking == 'y'){

            parkingCost = 20;
            break;
        }
        else if (Parking == 'N' || Parking == 'n'){
            parkingCost = 0;
            break;
        }
        else{
            cout << "\n\t\tYou entered an invalid answer. Please enter 'Y' for yes or 'N' for no.\n";
        }
        }while (Parking != 'Y' && Parking != 'y' && Parking != 'N' && Parking != 'n');
        
        
        do {
        cout << "\n\t\tDo you want a high speed internet during your stay? ";
        cin >> gym;
        if (gym == 'Y' || gym == 'y'){
            gymCost = 50;
            break;
        }
        else if (gym == 'N' || gym == 'n'){
            gymCost = 0;
            break;
        }
        else{
            cout << "\n\t\tYou entered an invalid answer. Please enter 'Y' for yes or 'N' for no.";
        } 
        }while (   gym != 'Y' && gym != 'y' && gym != 'N' && gym != 'n');

        rooms[i].cust.ServiceCharge = parkingCost + gymCost;

        do{
            cout<<"\n\t\tEnter  your Type of Creditcard : ";
            cout<<"\n\t\t\t[1] GSB (- 90 % )";
            cout<<"\n\t\t\t[2] KTB (- 85 % )";
            cout<<"\n\t\t\t[3] SCB (- 60 % )";
            cout<<"\n\t\t\t[4] No Creditcard ";
            cout<<"\n\t\tEnter  your Type of Creditcard : ";
            cin>>j;
            if (j == "1"){
                rooms[i].cust.payment_advance = 0.9; };
            if (j == "2"){
                rooms[i].cust.payment_advance = 0.85; };
            if (j == "3"){
                rooms[i].cust.payment_advance = 0.6; };
            if (j == "4"){
                rooms[i].cust.payment_advance = 1.0; };
        }while (j!= "1" && j!= "2" && j!= "3" && j!= "4" );
      
        
        

        rooms[i].status=1;
        greentext();
        cout<<"\n\t\t Customer Checked-in Successfully..";
        
        getch();
        
    }
}
void HotelMgnt::getAvailRoom(){
    system("cls");
    int i,found=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==0){
                displayRoom(rooms[i]);
                greentext();
                cout<<"\n\n\t\tPress enter for next room";
                whitetext();
                found=1;
                getch();
            }
        }if(found==0){
            redtext();
        cout<<"\n\t\tAll rooms are reserved";
        getch();
        
        }
}


void HotelMgnt::searchCustomer(char *pname){
    system("cls");
        int i,found=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0){
                cout<<"\n\t\tCustomer Name: "<<rooms[i].cust.name;
                cout<<"\n\t\tRoom Number: "<<rooms[i].roomNumber;
                greentext();
                cout<<"\n\n\t\tPress enter for next record";
                found=1;
                getch();
            }
        }if(found==0)
        {
            redtext();
        cout<<"\n\t\tPerson not found.";
        getch();
        
        }
}


void HotelMgnt::checkOut(int roomNum)
{       system("cls");
        int i,found=0,days,rno;
        float billAmount=0;
        for(i=0;i<count;i++){
            if(rooms[i].status==1 && rooms[i].roomNumber==roomNum){
            
            found=1;
            
            break;
            }
        }if(found==1)
        {   

            cout<<"\n\t\tEnter Number of Days (How many do you stay):\t";
            cin>>days;
            billAmount= (days * rooms[i].rent) + rooms[i].cust.ServiceCharge;
            cout<<"\t\t=============================================\n";
            bluetext();
            cout<<"\t\t                CheckOut Details \n";
            whitetext();
            cout<<"\t\t=============================================\n";
            cout<<"\n\t\tBooking ID : "<<rooms[i].cust.booking_id;
            cout<<"\n\t\tCustomer Name : "<<rooms[i].cust.name;
            cout<<"\n\t\tRoom Number : "<<rooms[i].roomNumber;
            cout<<"\n\t\tAddress : "<<rooms[i].cust.address;
            cout<<"\n\t\tPhone : "<<rooms[i].cust.phone;
            cout<<"\n\t\tEnter Check In Date (DD-MM-YY): "<<rooms[i].cust.from_date;
            cout<<"\n\t\tEnter Check Out Date (DD-MM-YY): "<<rooms[i].cust.to_date;
            cout<<"\n\t\tTotal ServiceCharge: " << rooms[i].cust.ServiceCharge <<" baht";
            cout<<"\n\t\tTotal Amount Due : "<<billAmount <<" baht";
            cout<<"\n\t\tAdvance Paid(discount): "<<rooms[i].cust.payment_advance<<" %";
            cout<<"\n\t\t*** Total Payable: "<< billAmount*rooms[i].cust.payment_advance<<" baht ";

            rooms[i].status=0;
        }
    getch();
    
}