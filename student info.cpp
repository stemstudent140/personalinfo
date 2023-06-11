#include <iostream>
#include <cctype>
using namespace  std;
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

void checkAge(string ans, string answer[], int i){
    string temp = ans;
    int len = temp.length();
    
    while (!isInteger(temp) || len > 2 || stoi(temp) <= 10)
    {
        cout<<"   please enter your age correctly again (age has to be between 11 and 99): ";
        cin>>temp;
        len = temp.length();
        answer[i] = temp ; 
    }   
    answer[i] = temp ;     
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
    int count = 0;
    bool check = false ;
    for (int i = 0; i < len; i++){
        if (ans == dep[i])
            check = true ;  
    }
    
    return check ;
}

void checkDepartement(string ans, string answer[], int m)
{
    string departement [] = {"computer engineering","electrical engineering", "mechanical engineering","civil engineering","software engineering","information system","information technology"
                            ,"cyber security","food engineering","electro mechanical"};
    int len = sizeof(departement)/sizeof(departement[0]);

    string lower = toLower(ans);
        while(!checkIfInside(lower, len, departement)) {
            cout << "   please enter your department again : ";
            getline(cin, ans);
            lower = toLower(ans);
        }
    
    answer[m] = lower;
    
}
void checkGPA (string ans , string answer [], int i){
    string temp = ans ;
    while (!isInteger(ans) || stof(ans) > 4){
        cout<<" Please enter your GPA : " ;
        cin>> ans;
        temp = ans;
        answer[i] = temp ; 
    }
    answer[i] = temp ;
}
void checkPhonenumber (string ans , string answer [] , int i ){
    string temp = ans ;
    while(!isInteger(ans) || ans.length() > 10){
       cout<<"please enter your phone number again " ;
       cin>>ans ;
       temp = ans ; 
       answer [i] = temp ; 
    }
    answer[i] = temp ; 
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

int main()
{
    string question[] = {"enter your first name: ","enter your middle name: ","enter your last name: ","enter your age: ","enter your department: ","enter your GPA: ","enter your phone number: ","Enter your E-mail adress: "};
    string answer[8];

    for (int i = 0; i < 8; i++) 
    {
        string ans;
        cout<<question[i];
        if (i == 3){
            getline(cin, ans);
            checkAge(ans, answer, i);}
        else if (i==5){
            getline(cin, ans);
            checkGPA(ans, answer , i ) ; }
        else if(i==4){
            getline(cin, ans);
            checkDepartement(ans ,answer,i);
        }
        else if (i== 6){
            getline(cin, ans);
            checkPhonenumber(ans , answer , i) ; 
        }    
        else if(i == 7){
            getline(cin, ans);
            if (checkEmail(ans))
                answer[i] = ans;
            else{
                while (!checkEmail(ans))
                {
                    cout<<"   please enter your email correctly again: ";
                    cin>>ans;
                }
                answer[i]=ans;
            }
        }
        else{
            getline(cin, ans);
            answer[i] = ans;
        }

    }
cout<<" -----------------------------------------------------------------------\n   ";
for (int i = 0; i < 8; i++)
{
    cout<<question[i]<<" = "<<answer[i]<<endl;
}
    return 0;
}
