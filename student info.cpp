#include <iostream>
#include <cctype>
using namespace  std;


bool isInteger(string a){
    int len = a.length(), count = 0;
    for (int i = 0; i < len; i++)
    {
        if(isdigit(a[i])){}
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
    string temp;
    int len = ans.length();
    
    while (!isInteger(ans) || len > 2 || stoi(ans) <= 10)
    {
        cout<<"   please enter your age correctly again (age has to be between 11 and 99): ";
        cin>>temp;
        ans = temp;
        len = ans.length();
    }
       answer[i] = ans;
              
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

bool checkIfInside(string ans, string dep[]){
    int len = sizeof(dep)/sizeof(dep[0]), count = 0;
    for (int i = 0; i < len; i++)
    {
        if (ans == dep[i])
            count++;
    }
    if(count == 0)
        return false;
    else
        return true;
    
}

void checkDepartement(string ans, string answer[], int m)
{
    string departement [] = {"computer engineering","electrical engineering", "mechanical engineering","civil engineering","software engineering","information system","information technology"
                            ,"cyber security","food engineering","electro mechanical"};
        
    string lower = toLower(ans);
    while (!checkIfInside(lower, departement))
    {
        cout << "   please enter the correct department: ";
        getline(cin, ans);
        lower = toLower(ans);

    }
    answer[m] = lower;
    
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
        string ans = "";
        cout<<question[i];
        getline(cin, ans);
        if (i == 3)
            checkAge(ans, answer, i);
        if(i==4)
            checkDepartement(ans ,answer,i);
        else if(i == 7){
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
        else
            answer[i] = ans;

    }
cout<<"-----------------------------------------------------------------------\n";
for (int i = 0; i < 8; i++)
{
    cout<<question[i]<<" = "<<answer[i]<<endl;
}
    return 0;
}
