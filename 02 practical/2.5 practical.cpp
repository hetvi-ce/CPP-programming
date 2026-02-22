#include<iostream>
#include<math.h>
using namespace std;
class loan
{
    int loan_id;
    string name;
    double loan_amt;
    double loan_int_rate;
    int loan_tenure;
    double EMI;
public:
    loan()
    {
        loan_id=1;
        name="tarak mehta";
        loan_amt=10000;
        loan_int_rate=10;
        loan_tenure=12;
        calculate_emi();
    }
    loan(int id,string Name,double amt,double rate, int tenure)
    {
        loan_id=id;
        name=Name;
        loan_amt=amt;
        loan_int_rate=rate;
        loan_tenure=tenure;
    }
    void create_loan();
    void calculate_emi();
    void display();
    int getID();
};
void loan::create_loan()
{
    int id,tenure;
    double amt,rate;
    string Name;
    cout<<"enter data : "<<endl;
    cout<<"enter id : ";
    cin>>loan_id;
    cin.ignore();
    cout<<"enter name : ";
    cin>>name;
    cout<<"enter amount : ";
    cin>>loan_amt;
    cout<<"enter intrest rate : ";
    cin>>loan_int_rate;
    cout<<"enter tenure(months) : ";
    cin>>loan_tenure;
    loan(id,Name,amt,rate,tenure);
    calculate_emi();
}
void loan::calculate_emi()
{
    double R=loan_int_rate/12/100;
    double T=loan_tenure;
    if(R==0)
        EMI=loan_amt/T;
    else
    {
        double a =pow(1+R,T);
        EMI =(loan_amt*R*a)/(a-1);
    }
}
void loan::display()
{
    cout<<"-----------------------"<<endl;
    cout<<"loan id : "<<loan_id<<endl<<"name : "<<name<<endl<<"loan amount : "<<loan_amt<<endl;
    cout<<"loan interest rate : "<<loan_int_rate<<"%"<<endl<<"loan tenure(months) : "<<loan_tenure<<endl<<"EMI : "<<EMI<<endl;
}
int loan::getID()
    {
        return loan_id;
    }
int main()
{
    loan l[20];
    int ch,count=1,i;

    do
    {
        cout<<"1. create loan"<<endl<<"2. display loans"<<endl<<"3. exit"<<endl;
        cout<<"enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                if(count>=20)
                {
                    cout<<"loan limit reached";
                    break;
                }
                l[count].create_loan();
                count++;
                break;
            }
        case 2:
            {
                if(count==0)
                {
                    cout<<"no loans availabe";
                    break;
                }
                for(i=0;i<count;i++)
                {
                    l[i].display();
                }
                break;
            }
        case 3:
            {
                return 0;
            }
        default:
            {
                cout<<"enter a valid choice";
                break;
            }
        }
    }while(ch!=3);
    return 0;
}


