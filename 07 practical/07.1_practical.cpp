#include<iostream>
using namespace std;
class calculator
{
    int add_i;
    float add_f;
    int flag=0;
public:
    int add(int a,int b);
    float add(float a,float b);
    float add(float a,int b);
    float add(int a,float b);
    void display();
};
int calculator::add(int a,int b)
{
    add_i=a+b;
    flag=1;
    return add_i;
}
float calculator::add(float a,float b)
{
    add_f=a+b;
    return add_f;
}
float calculator::add(float a,int b)
{
    add_f=a+b;
    return add_f;
}
float calculator::add(int a,float b)
{
    add_f=a+b;
    return add_f;
}
void calculator::display()
{
    if(flag==0)
        cout<<"sum : "<<add_f<<endl;
    else
        cout<<"sum : "<<add_i<<endl;
}
int main()
{
    int i,n=0,ch;
    int a,b;
    float x,y;
    calculator c[10];
start:
    cout<<"1. for integer value "<<endl<<"2. for float value "<<endl<<"3. for first integer and second float "<<endl;
    cout<<"4. for first float and second integer"<<endl<<"5. display"<<endl<<"6. exit"<<endl;
    cout<<"enter choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            {
                cout<<"enter a: ";
                cin>>a;
                cout<<"enter b: ";
                cin>>b;
                c[n].add(a,b);
                n++;
                goto start;
            }
        case 2:
            {
                cout<<"enter a: ";
                cin>>x;
                cout<<"enter b: ";
                cin>>y;
                c[n].add(x,y);
                n++;
                goto start;
            }
        case 3:
            {
                cout<<"enter a: ";
                cin>>a;
                cout<<"enter b: ";
                cin>>y;
                c[n].add(a,y);
                n++;
                goto start;
            }
        case 4:
            {
                cout<<"enter a: ";
                cin>>x;
                cout<<"enter b: ";
                cin>>b;
                c[n].add(x,b);
                n++;
                goto start;
            }
        case 5:
            {
                for(i=0;i<n;i++)
                {
                    c[i].display();
                }
                goto start;
            }
        case 6:
            {
                return 0;
            }
    return 0;
    }
}
