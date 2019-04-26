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
//Class Customer
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

//Global Declarations
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

//hotel management class
class HotelMgnt:protected Room
{
    public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkOut(int);
    void guestSummaryReport();
};
