#include<iostream>
using namespace std;
class point
{
    int x=0,y=0;
public:
    void getdata()
    {
        cout<<"enter x: ";
        cin>>x;
        cout<<"enter y: ";
        cin>>y;
    }
    point& move(int dx,int dy);
    void updatePoint(point *p);
    void display();
};
point& point::move(int dx,int dy)
{
    x=x+dx;
    y=y+dy;
    return *this;
}
void point::updatePoint(point *p)
{
    p->move(5,5);
}
void point::display()
{
    cout<<"x = "<<x<<"  y = "<<y<<endl;
}
int main()
{
    point p;
    int a,b,c,d;
    p.getdata();
    p.move(2, 3).move(-1, 4);
    cout<<"by using chainable function(it adds (2,3) and then (-1,4) to x and y) : "<<endl;
    p.display();
    p.updatePoint(&p);
    cout<<"by using pass by reference (it adds(5,5) to current x and y) : "<<endl;
    p.display();
    return  0;
}
