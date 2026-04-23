#include<iostream>
using namespace std;
class person
{
protected:
    string name;
    int age;
public:
    person(string n,int a)
    {
        name=n;
        age=a;
    }
    void display_p()
    {
        cout<<"name : "<<name<<endl<<"age : "<<age<<endl;
    }
};
class employee:public person
{
protected:
    int id;
public:
    employee(string n,int a,int i):person(n,a)
    {
        id=i;
    }
    void display_e()
    {
        cout<<"employee id : "<<id<<endl;
    }
};
class manager:public employee
{
    string dept;
public:
    manager(string n,int a,int i,string d):employee(n,a,i)
    {
        dept=d;
    }
    void display_m()
    {
        display_p();
        display_e();
        cout<<"department : "<<dept<<endl;
    }
    int getid()
    {
        return id;
    }
};
int main()
{
    int n;
    cout<<"n : ";
    cin>>n;
    manager* m[10];
    string name,dept;
    int age,id,i;
    for(i=0;i<n;i++)
    {
        cout<<"enter name : ";
        cin.ignore();
        getline(cin,name);
        cout<<"age : ";
        cin>>age;
        cout<<"id : ";
        cin>>id;
        cout<<"department : ";
        cin.ignore();
        getline(cin,dept);
        m[i]=new manager(name,age,id,dept);
    }
    int s_id;
    cout<<"enter id for display : ";
    cin>>s_id;
    for(i=0;i<n;i++)
    {
        if(m[i]->getid()==s_id)
        {
            m[i]->display_m();
        }
    }
    return 0;
}
