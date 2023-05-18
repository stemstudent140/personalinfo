#include <iostream>
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


void checkNumber(string ans, string answer[], int i){
    string temp;
    if (isInteger(ans))
        answer[i] = ans;
    else{
        while (!isInteger(ans))
        {
            cout<<"   please enter correctly again: ";
            cin>>temp;
            ans = temp;
        }
        answer[i] = temp;
    }
}


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
            count++;
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
        cin>>ans;
        if (i == 6 || i == 3 || i == 5)
            checkNumber(ans, answer, i);
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