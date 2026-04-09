#include<iostream>
using namespace std;
class account
{
    int acc_id;
    string name;
    int balance;
    static int count;
public:
    int getbalance();
    int getid();
    void debit(int amt);
    void credit(int amt);
    void setdata();
    void display();
    void c_display();
};
int account::count=0;
int account::getid()
{
    return acc_id;
}
void account::credit(int amt)
{
    balance+=amt;
}
void account::debit(int amt)
{
    balance-=amt;
}
int account::getbalance()
{
    return balance;
}
void account::setdata()
{
    cout<<"enter id : ";
    cin>>acc_id;
    cout<<"enter name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"enter balance : ";
    cin>>balance;
    count++;
}
void account::display()
{
    cout<<"ID: "<<acc_id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Balance: "<<balance<<endl;
}
void account::c_display()
{
    cout<<"total account no : "<<count<<endl;
}
int main()
{
    int n,i,no1,no2,amt;
    int f1=0,f2=0;
    cout<<"enter number of accounts you want to add : ";
    cin>>n;
    account* acc=new account[n];
    for(i=0;i<n;i++)
    {
        cout<<"enter details for "<<i+1<<" : "<<endl;
        acc[i].setdata();
    }
    cout<<"enter account number from which you have to transfer money : ";
    cin>>no1;
    cout<<"enter account number in which you have to transfer money : ";
    cin>>no2;
    cout<<"enter amount : ";
    cin>>amt;
    for(i=0;i<n;i++)
    {
        if(acc[i].getid()==no1)
        {
            for(int j=0;j<n;j++)
            {
                if(acc[j].getid()==no2)
                {
                    f2=1;
                    if(acc[i].getbalance()>=amt)
                    {
                        acc[i].debit(amt);
                        acc[j].credit(amt);
                        cout<<"transfered successfully "<<endl;
                        f1=1;
                        goto x;
                    }
                    else
                    {
                        cout<<"insufficient balance"<<endl;
                        goto x;
                    }
                }
                else
                {
                   f2=0;
                }
            }
        }
        else
        {
            f1=0;
        }
    }
    if(f1==0|| f2==0)
    {
        cout<<"account not found"<<endl;
    }
    x:
    for(i=0;i<n;i++)
    {
       acc[i].display();
    }
    account::c_display;
    delete[] acc;
    return 0;
}
