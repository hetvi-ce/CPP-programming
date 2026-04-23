#include<iostream>
using namespace std;
class fuel
{
protected:
    string type;
public:
    fuel(string t)
    {
        type=t;
    }
    void display_t()
    {
        cout<<"fuel type : "<<type<<endl;
    }
};
class brand
{
protected:
    string b_name;
public:
    brand(string n)
    {
        b_name=n;
    }
    void display_b()
    {
        cout<<"brand name : "<<b_name<<endl;
    }
};
class car:public fuel ,public brand
{
public:
    car(string f,string b):fuel(f),brand(b)
    {   }
    void display_c()
    {
        display_t();
        display_b();
    }
};
int main()
{
    int n,i;
    string type,brand;
    cout<<"n : ";
    cin>>n;

    car* c[10];

    for(i=0;i<n;i++)
    {
        cout<<"enter fuel type : ";
        cin>>type;
        cout<<"enter brand : ";
        cin>>brand;
        c[i]= new car(type,brand);
    }
    for(i=0;i<n;i++)
    {
        c[i]->display_c();
    }
    return 0;
}
