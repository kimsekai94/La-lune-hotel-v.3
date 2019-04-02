#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void greentext(){SetConsoleTextAttribute(hConsole, 2);  };
void whitetext(){SetConsoleTextAttribute(hConsole, 15);  };
void redtext (){SetConsoleTextAttribute(hConsole,  4);  };
void bluetext (){SetConsoleTextAttribute(hConsole, 11);  };
void yellowtext (){SetConsoleTextAttribute(hConsole, 14);  };
void darktext (){SetConsoleTextAttribute(hConsole, 8);  };


bool MenuLoop = true;
string name ("*****");    
string surname ("*****");
int address1 (00);
string address2 ("*****");
string address3 ("*****");
string address4 ("*****");
string postcode ("*****");
string tel ("00");
int creditcardSelection;
string creditcardType("*****");
string creditcard("****"); 

void resetMemberDetails(){
     name =     "*****";
     surname =  "*****";
     address1 = 00;
     address2 = "*****";
     address3 = "*****";
     address4 = "*****";
     postcode = "*****";
     tel = "00";
     creditcard = "****";
     creditcardType   = "*****";
 
}
void MemberForm(){
 
    system ("cls");
    bluetext();
    cout << "\t\t\t      Member Details\n";
    whitetext();
    cout << "\t________________________________________________________________\n\n";
    cout << "\tMember Form   \t";
    cout << "\t  Member: ";
    if (name != "*****"){greentext();};   // If the field is not the default
    cout << name << " ";                  // value use green text, then
    whitetext();                          // revert back to white text.
    if (surname != "*****"){greentext();};
    cout << surname << "\n";
    whitetext();
    cout << "\t\t\t";
    cout << "\t Address: ";
    if (address1 != 00){greentext();};
    cout << address1 << " ";
    whitetext();
    if (address2 != "*****"){greentext();};
    cout << address2 << "\n";
    whitetext();
    cout << "\t\t";
    cout << "\t\t          ";
    if (address3 != "*****"){greentext();};
    cout << address3 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (address4 != "*****"){greentext();};
    cout << address4 << "\n";
    whitetext();
    cout << "\t\t\t\t          ";
    if (postcode != "*****"){greentext();};
    cout << postcode << "\n";
    whitetext();
    cout << "\t\t\t   Telephone: ";
    if (tel != "00"){greentext();};
    cout << tel;
    whitetext();
    cout << "\n";
    cout << "\t________________________________________________________________\n\n";
    cout << "\t\t           Credit card: ";
    if (creditcard != "****"){greentext();};
    cout << creditcard;
    whitetext();
    cout << "\n\t\t         Credit card Type: ";
    if(creditcard == "No"){
        greentext();
        creditcardType = "No";
    }
    if (creditcardType != "*****"){greentext();};
    cout << creditcardType;
    whitetext();
    cout << "\n\t________________________________________________________________\n\n";
    cout << "\n";
};
 
// Save function for saving member details to a file
void savefile(){
    string saveFileName;
    stringstream out;
    out << name << " " << surname;
    
void createBooking(){}
void billpayment(){}
void priceList(){}
void help(){}
void exit(){}
void mainMenu(){
 
    // Private variable used for menu selection
    int menuchoice;
 
    system ("cls");
 
    resetMemberDetails();
    bluetext();
    cout << "\t\t\t\tMain Menu\n\n";
    whitetext();
    cout << "\t\t1 - Add a new member\n\n";
    cout << "\t\t2 - View price list\n\n";
    cout << "\t\t3 - Create a new booking\n\n";
    cout << "\t\t4 - bill payment\n\n";
    cout << "\t\t5 - Help\n\n";
    cout << "\t\t6 - Exit\n\n\n";
    cout << "\t\t\tPlease choose an option: ";
    cin >> menuchoice;
 
    //Prevents a character entry from crashing the program
    while (cin.fail())
        {cin.clear();
        cin.ignore();
        cout << "\n\t\tPlease enter a valid number:"; cin >> menuchoice;
    };
 
    // Switch statement for menu selection
    switch (menuchoice){
 
        // Enter new member function
        case 1 :
            memberDetails();
            break;
        case 2 :
            createBooking();
            break;
 
        case 3 :
            billpayment();
            break;
 
        case 4 :
            priceList();
            break;
 
        case 5 :
            help();
            break;
 
        case 6 :
            exit();
            break;
 
        default:
            cout << "\n\tPlease enter a correct menu choice\n\n\t";
            system ("pause");
    };
};

void welcome(){
    bluetext();
    cout << "\n\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  *           WELCOME to            *  @\n";
    cout <<       "\t\t\t@  *         La-lune-hotel           *  @\n";
    cout <<       "\t\t\t@  *                                 *  @\n";
    cout <<       "\t\t\t@  ***********************************  @\n";
    cout <<       "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    whitetext();
    cout <<       "\n\n\t\t\t\t>";
    cout << "   Main menu \n";
    greentext();
    cout << "\t\t      press enter in order to approach Main menu... ";
    cin.get(); 
}
int main(){
    welcome();
     while (MenuLoop == true){mainMenu();};      //Main menu loop
    return 0;
}

