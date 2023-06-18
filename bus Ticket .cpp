#include <iostream>
# include <ctime>
using namespace std ;

struct timeOfFlight{
    string hour;
    int date;
    int month;
    int year;
};

struct busTicket {
    string fName ;
    string mName ;
    string lName;
    int age;
    int phoneNum;
    string email;
    string departureAdress;
    string destinationAdress;
    timeOfFlight departureDate;
    int fee;
    int ticketNumber;
};

//-------------------------------------------------------------------------------------------------------------------------------------

bool isInteger(string a){
    int len = a.length(), count = 0;
    for (int i = 0; i < len; i++)
    {
        if(isdigit(a[i]) || a[i]=='.'){}
        else
            count++;

    }

    if (count == 0)
        return true;
    else
        return false;    
}

//---------------------------------- Checks if the given string is a number, and lets the user enter agian if not -----------------------

int checkAge(string ans){
    string temp = ans;
    int len = temp.length();
    
    while (!isInteger(temp) || len > 2 || stoi(temp) <= 10)
    {
        cout<<"   please enter your age correctly again (age has to be between 11 and 99): ";
        cin>>temp;
        len = temp.length();
    }   
    return stoi(temp);     
}

//-------------------------------------------------------------------------------------------------------------

string toLower(string a){
    string lower;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i]==' ')
            lower += ' ';
        else
            lower += tolower(a[i]);  
    }
    return lower;
}

bool checkIfInside(string ans, int len, string dep[]){
    bool check = false ;
    for (int i = 0; i < len; i++){
        if (ans == dep[i])
            check = true ;  
    }
    
    return check ;
}

int checkPhonenum (string ans){
    string temp = ans ;
    while(!isInteger(ans) || ans.length() > 10){
       cout<<"please enter your phone number again ";
       cin>>ans ;
       temp = ans ; 
    }
    return stoi(temp) ; 
}

//------------------------------------------------------checks the email has '@' sign and '.com' at the end--------------------------------
bool checkEmail(string email){
    int len = email.length() , count = 0;
    int dotComStarts = len - 4;
    string dotCom;

    for (int i = 0; i < len; i++)
    {
        if(email[i] == '@')
            count++;
        if(i >= dotComStarts){
            dotCom += email[i];
        }
    }

    if(dotCom == ".com" && count != 0)
        return true;
    else
        return false;
    
}

string checkedEmail(string ans){
    if (checkEmail(ans))
        return ans;
    else{
        while (!checkEmail(ans))
        {
            cout<<"   please enter your email correctly again: ";
            cin>>ans;
        }
        return ans;
    }
}

int generateTicketNumber(){
    string a = "";
    for(int i = 0; i < 6; i++){
        a += to_string((rand() % 9));    
    }
    return stoi(a);
}

void display ( busTicket passengerList[] , int length )
{
    for (int i = 0; i < length ; i++)
    {
        
              cout << "\n-----------------Passenger List "<< i + 1<<"------------------------------\n";

        cout << "Full Name :  " << passengerList[i].fName << " " + passengerList[i].mName + " " + passengerList[i].lName << endl;
        cout << "Age: " << passengerList[i].age << endl;
        cout << "Phone Number: " << passengerList[i].phoneNum << endl;
        cout << "E-mail Adress: " << passengerList[i].email << endl;
        cout << "Departure Adress: " <<passengerList[i].departureAdress << endl;
        cout << "Destination Adress: " <<passengerList[i].destinationAdress << endl;
        cout << "Departure time:  " << passengerList[i].departureDate.hour << "  " << passengerList[i].departureDate.date << "/" ;
        cout << passengerList[i].departureDate.month << "/" << passengerList[i].departureDate.year << endl;
        cout << "    Your Ticket Number:  " << passengerList[i].ticketNumber << endl;

    }
}
//-------------------------------------------------------------------------------------------------------------------------------------


int main(){
    busTicket passengerList[100];
    string a = "y";
    int i = 0;
    while(a == "y" || a == "Y"){
        busTicket passengerInfo;

        cout << "enter your first name: ";
        cin >> passengerInfo.fName;
        cout << "enter your middle name: ";
        cin >> passengerInfo.mName;
        cout<< "enter your last name: ";
        cin>> passengerInfo.lName;
        cout << "enter your age: ";
        string ans;
        cin >> ans;
        passengerInfo.age = checkAge(ans);
        cout << "enter your phone number: ";
        cin >> ans ;
        passengerInfo.phoneNum = checkPhonenum(ans);
        cout << "Enter your E-mail adress: ";
        cin >> ans;
        passengerInfo.email = checkedEmail(ans);
        cout << "Enter your departure Adress: ";
        cin>> passengerInfo.departureAdress;
        cout << "Enter your Destination :  ";
        cin>> passengerInfo.destinationAdress;
            timeOfFlight t;
            cout << "           Your Departure date(use Numbers)  \n";
            cout << "   Enter your Departure time(year) : ";
            cin >> t.year;
            cout << "   Enter your Departure time(month) : ";
            cin >> t.month;
            cout << "   Enter your Departure time(date) : ";
            cin >> t.date;
            cout << "   Enter your Departure time(hour) : ";
            cin >> t.hour;
            passengerInfo.departureDate = t;
        
        passengerInfo.ticketNumber = generateTicketNumber();
        passengerList[i] = passengerInfo;
        i++;

        cout << "---------------------------------------------------\n";
        cout << "do you want to add another passenger? (y/n) :  ";
        cin >> a;
        cout << "\n---------------------------------------------------\n";
    }

//-----------------------------------------------------------------------------------------------------------------------------

display (passengerList  , i ) ; 
    

return 0 ;
}
