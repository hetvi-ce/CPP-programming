#include <iostream>
using namespace std;

class account
{
private:
    string acc_name;
    int acc_id;
    float acc_balance;
public:

    //default constructor
    account()
    {
        acc_name="Hetvi";
        acc_id=05;
        acc_balance = 1000.0;
    }
    //parameterized constructor
    account(string name,int id,float balance)
    {
        acc_name=name;
        acc_id=id;
        acc_balance=balance;
    }
    void create_acc();
    void deposit();
    void withdraw();
    void display();
    int getID();
};

void account :: create_acc()
{
        cout<<"enter details:\n";
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,acc_name);
        cout<<"enter id: ";
        cin>>acc_id;
        cout<<"enter balance: ";
        cin>>acc_balance;
}

void account :: deposit()
{
    float amt;
    cout << "enter amount to deposit: ";
    cin >> amt;

    if (amt > 0)
        acc_balance += amt;
    else
        cout << "invalid amount!\n";
}

void account :: withdraw()
{
    float amt;
    cout << "enter amount to withdraw: ";
    cin >> amt;

    if (amt > acc_balance)
        cout << "insufficient balance"<<endl;
    else
        acc_balance -= amt;
}

void account :: display()
{
    cout<<"-----------------------"<<endl;
    cout << "name: " << acc_name<<endl;
    cout << "ID: " << acc_id<<endl;
    cout << "balance: " << acc_balance << endl;
}

int account :: getID()
{
    return acc_id;
}
int main()
{
    account acc[10];
    cout<<"account with default balance is created"<<endl;
    acc[0].display();

    int ch,n=1;
    x:
    cout<<"1. ceate new account"<<endl;
    cout<<"2. deposit money"<<endl;
    cout<<"3. withdraw money"<<endl;
    cout<<"4. display"<<endl;
    cout<<"5. exit"<<endl;
    cout<<"enter your choice: "<<endl;
    cin>>ch;

    switch(ch)
    {
    case 1:
        {
            if (n<10)
            {
                acc[n].create_acc();
                n++;
            }

            goto x;
        }
    case 2:
        {
            int idd;
            cout << "enter account ID: ";
            cin >> idd;
            int i = 0;
            for (i = 0; i < n; i++)
            {
                if (acc[i].getID() == idd)
                {
                    acc[i].deposit();
                    break;
                }
            }
            if(i==n)
                cout<<"no id found"<<endl;
            goto x;
        }
    case 3:
        {
            int idd;
            cout << "enter account ID: ";
            cin >> idd;
            int i = 0;
            for (i = 0; i < n; i++)
            {
                if (acc[i].getID() == idd)
                {
                    acc[i].withdraw();
                    break;
                }
            }
            if(i==n)
                cout<<"no id found"<<endl;
            goto x;
        }
    case 4:
        {
             for (int i = 0; i < n; i++)
             {
                 acc[i].display();
             }
              goto x;
        }
    case 5:
        {
            return 0;
        }
    default:
        {
            cout<<"Invalid choice.";
            goto x;
        }
    }
    return 0;
}
