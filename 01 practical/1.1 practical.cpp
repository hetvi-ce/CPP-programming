#include <iostream>
using namespace std;
class bank_account
{
private:
    int id;
    string username;
    int balance;
public:
    void setValues(int n, string name, int bal);
    int loadMoney(int amt);
    int transferMoney(Wallet &receiver, int amt);
    void display();
};

void bank_account :: setValues(int n, string name, int bal)
    {
        id=n;
        username=name;
        balance= bal;
    }

int bank_account :: loadMoney(int amt)
    {
        balance+=amt;
        return balance;
    }
int bank_account :: transferMoney(bank_account &receiver, int amt)
    {
       if (amt <= 0)
        {
            cout << "Invalid amount.\n";
            return 0;
        }
        else if (amt > balance)
        {
            cout << "Insufficient balance.\n";
            return 0;
        }
        else
        {
            balance -= amt;
            receiver.balance += amt;
            cout << "Transfer successful.\n";
            return 0;
        }
    }
void bank_account :: display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"username: "<<username<<endl;
        cout<<"balance: "<<balance<<endl;
    }

int main()
{
    bank_account b1,b2;
    int ch;
    int id,balance;
    string username;
    cout<<"Enter details for bank account 1:"<<endl;
    cout<<"ID: ";
    cin>>id;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Balance: ";
    cin>>balance;
    cout<<endl;

    b1.setValues(id,username,balance);


    cout<<"Enter details for bank account 2:"<<endl;
    cout<<"ID: ";
    cin>>id;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,username);
    cout<<"Balance: ";
    cin>>balance;
    cout<<endl;

    b2.setValues(id,username,balance);

    n: cout<<"1) Load money"<<endl;
    cout<<"2) Transfer money"<<endl;
    cout<<"3) Display details"<<endl;
    cout<<"4) Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        {
            int amt,n;
            cout<<"In which account you want to add money: ";
            cin>>n;
            cout<<"Enter the amount you want to load: ";
            cin>>amt;
            if(n==1)
            {
                cout<<"Current balance is: "<<b1.loadMoney(amt)<<endl;
            }
            else if(n==2)
            {
                cout<<"Current balance is: "<<b2.loadMoney(amt)<<endl;
            }
            else
            {
                cout<<"bank account does not exist"<<endl;
            }

            goto n;
        }
    case 2:
        {
            int n,amt;
            cout<<"From which account you want to transfer money: ";
            cin>>n;
            cout<<"Enter the amount you want to transfer: ";
            cin>>amt;
            if(n==1)
            {
                b1.transferMoney(b2, amt);
            }
            else if(n==2)
            {
                b2.transferMoney(b1, amt);
            }
            else
            {
                cout<<"bank account does not exist.";
            }

            goto n;
        }
    case 3:
        {
            b1.display();
            b2.display();
            goto n;
        }
    case 4:
        {
            cout<<"THANK YOU!";
            break;
        }
    default:
        {
            cout<<"Invalid choice entered";
        }
    }
}
