#include<iostream>
using namespace std;
class student
{
    int roll_number;
    string name;
    float m1;
    float m2;
    float m3;
    float average;
public:
    student()
    {
       roll_number=4;
       name="hetvi";
       m1=8;
       m2=9;
       m3=7;
       avg();
    }
    student(int r,string Name,float M1,float M2,float M3)
    {
        roll_number=r;
        name=Name;
        m1=M1;
        m2=M2;
        m3=M3;
    }
    void display();
    float avg();

};
float student::avg()
{
    float a;
    a=(m1+m2+m3)/3;
    return a;
}
void student::display()
{
    cout<<"roll no : "<<roll_number<<endl;
    cout<<"name : "<<name<<endl;
    cout<<"marks : "<<m1<<","<<m2<<","<<m3<<endl;
    cout<<"average : "<<avg()<<endl;
}
int main()
{
    student s1;
    s1.display();
    int n;
    string name;
    int roll_number;
    float m1,m2,m3;
    student s[10];
    cout<<"How many students you want to add: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin.ignore();
        cout<<"Enter name: ";
        getline(cin,name);
        cout<<"Enter roll number: ";
        cin>>roll_number;
        cout<<"Enter marks ";
        cin>>m1>>m2>>m3;
        s[i]= student(roll_number,name,m1,m2,m3);
        s[i].display();
    }
    return 0;
}
