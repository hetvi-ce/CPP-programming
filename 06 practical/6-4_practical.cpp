#include<iostream>
using namespace std;
class account
{
protected:
    int acc_num;
    float cur_bal;

    string history[100];
    float amount[100];
    int type[100];
    int top;

public:
    account(int no,float bal)
    {
        acc_num=no;
        cur_bal=bal;
        top=-1;
    }
    virtual ~account()
    {
        cout<<"Account destroyed\n";
    }
    void deposit(float amt)
    {
        cur_bal += amt;
        history[++top] = "Deposit";
        amount[top] = amt;
        type[top] = 1;
    }
    virtual void withdraw(float amt)
    {
        if(amt <= cur_bal)
        {
            cur_bal -= amt;
            history[++top] = "Withdraw";
            amount[top] = amt;
            type[top] = 2;
        }
        else
            cout<<"Insufficient balance\n";
    }
    void undo()
    {
        if(top == -1)
        {
            cout<<"No transaction to undo\n";
            return;
        }
        if(type[top] == 1)
            cur_bal -= amount[top];
        else if(type[top] == 2)
            cur_bal += amount[top];
        else if(type[top] == 3)
            cur_bal -= amount[top];
        cout<<"Last transaction undone\n";
        top--;
    }
    void showHistory()
    {
        if(top == -1)
        {
            cout<<"No transactions\n";
            return;
        }
        for(int i=0;i<=top;i++)
            cout<<history[i]<<" : "<<amount[i]<<endl;
    }
    void display()
    {
        cout<<"Account No: "<<acc_num<<endl;
        cout<<"Balance: "<<cur_bal<<endl;
    }
};
class savings : public account
{
    float interest;
public:
    savings(int no,float bal,float i) : account(no,bal)
    {
        interest = i;
    }
    void addInterest()
    {
        float amt = cur_bal * interest / 100;
        cur_bal += amt;

        history[++top] = "Interest";
        amount[top] = amt;
        type[top] = 3;
    }
    void display()
    {
        account::display();
        cout<<"Interest Rate: "<<interest<<"%\n";
    }
};
class current : public account
{
    float overdraft;
public:
    current(int no,float bal,float l) : account(no,bal)
    {
        overdraft = l;
    }
    void withdraw(float amt)
    {
        if(amt <= cur_bal + overdraft)
        {
            cur_bal -= amt;
            history[++top] = "Withdraw";
            amount[top] = amt;
            type[top] = 2;
        }
        else
            cout<<"Overdraft limit exceeded\n";
    }
    void display()
    {
        account::display();
        cout<<"Overdraft Limit: "<<overdraft<<endl;
    }
};
int main()
{
    int choice;
    float amt;

    savings s(105,10000,5);
    current c(205,20000,500);

start:
    cout<<"1.Deposit\n2.Withdraw\n3.Add Interest\n4.Display Savings\n5.Display Current\n6.History\n7.Undo\n8.Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter amount: ";
            cin>>amt;
            s.deposit(amt);
            c.deposit(amt);
            goto start;

        case 2:
            cout<<"Enter amount: ";
            cin>>amt;
            s.withdraw(amt);
            c.withdraw(amt);
            goto start;

        case 3:
            s.addInterest();
            goto start;

        case 4:
            s.display();
            goto start;

        case 5:
            c.display();
            goto start;

        case 6:
            cout<<"\nSavings History:\n";
            s.showHistory();
            cout<<"\nCurrent History:\n";
            c.showHistory();
            goto start;

        case 7:
            cout<<"\nUndo Savings:\n";
            s.undo();
            cout<<"\nUndo Current:\n";
            c.undo();
            goto start;

        case 8:
            break;

        default:
            cout<<"Invalid choice\n";
            goto start;
    }

    return 0;
}
