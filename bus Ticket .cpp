#include <iostream>
# include <ctime>
using namespace std ;

struct timeOfFlight{
    string hour;
    string date;
    string month;
    string year;
};

struct busTicket {
    string fName ;
    string mName ;
    string lName;
    int age;
    string phoneNum;
    string email;
    string departureAdress;
    string destinationAdress;
    timeOfFlight departureDate;
    int fee;
    int ticketNumber;
};

string checkForPureString(string name){
    bool flag = false;
    for (int i = 0; i < name.length(); i++){
        if (isdigit(name[i])) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout<<"      Enter an appropriate value(mustn't contain a number) :  ";
        cin>>name;
        checkForPureString(name);
    }
    return name;
}
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
string checkYear (string year )
{
    if (isInteger(year) && stoi(year) >=2023 ){
        return year;
    }
    else{
        cout<<"\t please enter year again(year should be above 2023) : " ; 
        cin>> year ; 
       return checkYear(year) ; 
    }
    
}

string checkMonth(string month )
{
    if (isInteger(month) && stoi(month) >= 1 && stoi(month) <= 13){
        return month;
    }
    else{
        cout<<"\tplease enter year again(month should be 1 - 12) : " ; 
        cin>> month ; 
       return checkMonth(month) ; 
    }
    
}
string checkDate (string date )
{
    if (isInteger(date) && stoi(date) >= 1 && stoi(date) <= 30){
        return date;
    }
    else{
        cout<<"\tplease enter year again(date should be 1 - 30) : " ; 
        cin>> date ; 
       return checkDate(date) ; 
    }
    
}

string checkHour (string hour )
{
    if (isInteger(hour) && stoi(hour) >= 0 && stoi(hour) <= 24){
        return hour;
    }
    else{
        cout<<"\tplease enter hour again(Hour should be 0 - 24) : " ; 
        cin>> hour ; 
       return checkHour(hour) ; 
    }
    
}

//---------------------------------- Checks if the given string is a number, and lets the user enter agian if not -----------------------

int checkAge(string ans)  {
    string temp = ans;
    int len = temp.length();
    
    while (!isInteger(temp) || len > 2 || stoi(temp) <= 10)
    {
        cout<<"\t  please enter your age correctly again (age has to be between 11 and 99): ";
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

string checkPhonenum (string ans){
    string temp = ans ;
    while(!isInteger(ans) || ans.length() > 10 || ans.length() < 10 ) {
       cout<<"\t  Enter correctly  phone number again ( must be 10 digit ) : ";
       cin>>ans ;
       temp = ans ; 
    }
    return temp ; 
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
            cout<<"   please enter your email correctly again ( must contain @ and .com ):  ";
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
    if (length == 0)
       cout<< endl <<"\tThere is no passenger at the list "<<endl ; 
    else 
    {
       for (int i = 0; i < length ; i++)
            {
                
                    cout << "\n----------------------Passenger List "<< i + 1<<"------------------------------\n";

                cout << "Full Name :  " << passengerList[i].fName << " " + passengerList[i].mName + " " + passengerList[i].lName << endl;
                cout << "Age: " << passengerList[i].age << endl;
                cout << "Phone Number: " << passengerList[i].phoneNum << endl;
                cout << "E-mail Adress: " << passengerList[i].email << endl;
                cout << "Departure Adress: " <<passengerList[i].departureAdress << endl;
                cout << "Destination Adress: " <<passengerList[i].destinationAdress << endl;
                cout << "Departure time:  " << passengerList[i].departureDate.hour << ":00 ,  Date :  " << passengerList[i].departureDate.date << "/" ;
                cout << passengerList[i].departureDate.month << "/" << passengerList[i].departureDate.year << endl;
                cout << endl << "    Your Ticket Number:  " << passengerList[i].ticketNumber << endl;
                cout<<"------------------------------------------------------------------------------------------------------------------------";
            }
    }
   
}
int main(){
    busTicket passengerList[100];
    string a = "y";
    int i = 0 , choice , repeat = 1;
    cout<<"***********BUS-TICKET  SYSTEM ************ " ;
    while(repeat != 0){
        cout<<endl << "\t  Press 1 for take passenger  " ;
        cout<<endl << "\t  Press 2 for view passengers list ";
        cout<<endl << "\t  Press 0 to terminate the program " <<endl ;  
        cin>> choice ;
        switch (choice){
        case 1: {
                busTicket passengerInfo;
                cout << "Enter your first name: ";
                cin >> passengerInfo.fName;
                passengerInfo.fName =  checkForPureString(passengerInfo.fName );
                cout << "Enter your middle name: ";
                cin >> passengerInfo.mName;
                passengerInfo.mName =  checkForPureString(passengerInfo.mName );
                cout<< "Enter your last name: ";
                cin>> passengerInfo.lName;
                passengerInfo.lName =  checkForPureString(passengerInfo.lName );
                cout << "Enter your age: ";
                string ans;
                cin >> ans;
                passengerInfo.age = checkAge(ans);
                cout << "Enter your phone number: ";
                cin >> ans ;
                passengerInfo.phoneNum = checkPhonenum(ans);
                cout << "Enter your E-mail adress: ";
                cin >> ans;
                passengerInfo.email = checkedEmail(ans);
                cin.ignore(); 
                cout << "Enter your departure Adress: ";
                getline ( cin , passengerInfo.departureAdress );
                cout << "Enter your Destination :  " ;
                getline (cin , passengerInfo.destinationAdress) ;
                
                    timeOfFlight t;
                    cout << "           Your Departure date(use Numbers)  \n";
                    cout << "           Enter your Departure time(year) : " ;
                    cin >> t.year;
                    t.year = checkYear(t.year);
                    cout << "           Enter your Departure time(month) : "  ;
                    cin >> t.month;
                    t.month = checkMonth(t.month);
                    cout << "            Enter your Departure time(date) : " ;
                    cin >> t.date;
                    t.date = checkDate(t.date);
                    cout << "            Enter your Departure time(hour) : " ;
                    cin >> t.hour;
                    t.hour = checkHour(t.hour);
                    passengerInfo.departureDate = t;
                passengerInfo.ticketNumber = generateTicketNumber();
                passengerList[i] = passengerInfo;
                i++;
                cout<<endl <<"   Passenger succesfully registred    " <<endl ;
             break ; 
            }
        case 2: 
           {
            display (passengerList  , i ) ; 
            break ; 
           }
        default :   
            {
                repeat = 0 ;
                break ; 
            }  
        }
    }
return 0 ;
}
