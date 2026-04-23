#include<iostream>
using namespace std;
class shape
{
    float radius;
public:
    shape(float r)
    {
        radius=r;
    }
    float get_r()
    {
        return radius;
    }
};
class circle:public shape
{
    float area;
public:
    circle(float r):shape(r){}
    float calc_area()
    {
        area=3.1415*get_r()*get_r();
        return area;
    }
    void display()
    {
        cout<<"area : "<<area<<endl;
    }
};
int main()
{
    float r;
    int i,n;
    x:
    cout<<"n : ";
    cin>>n;
    if(n>10)
    {
        cout<<"enter n<10 "<<endl;
        goto x;
    }
    circle* c[10];
    for(i=0;i<n;i++)
    {
        cout<<"Enter radius "<<i+1<<" : ";
        cin>>r;
        if(r>0)
        {
            c[i] = new circle(r);
        }
        else
        {
            cout<<"invalid radius"<<endl;
            i--;
        }
    }
    for(i=0;i<n;i++)
    {
        c[i]->calc_area();
        c[i]->display();

    }
    for(i=0;i<n;i++)
    {
        delete c[i];
    }
    return 0;
}
