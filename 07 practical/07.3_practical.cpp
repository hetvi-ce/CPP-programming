#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class Fahrenheit;
class Celsius
{
    float c;
public:
    Celsius(float x = 0)
    {
        c = x;
    }
    void input()
    {
        cin >> c;
    }
    float getC()
    {
        return c;
    }
    void display()
    {
        cout << c << " C";
    }
    operator Fahrenheit();
};
class Fahrenheit
{
    float f;
public:
    Fahrenheit(float x = 0)
    {
        f = x;
    }
    void input()
    {
        cin >> f;
    }
    float getF()
    {
        return f;
    }
    void display()
    {
        cout << f << " F";
    }
    operator Celsius()
    {
        return Celsius((f - 32) * 5 / 9);
    }
    int isEqual(Celsius c)
    {
        Celsius temp = *this;
        if (abs(temp.getC() - c.getC()) < 0.0001)
            return 1;
        else
            return 0;
    }
};
Celsius::operator Fahrenheit()
{
    return Fahrenheit((9.0/5)*c + 32);
}
int main()
{
    int n;
    cout << "Enter number of values: " << endl;
    cin >> n;

    Celsius carr[50];
    Fahrenheit farr[50];

    queue<Fahrenheit> fq;
    queue<Celsius> cq;

    cout << endl << "Enter Celsius values:" << endl;
    for(int i = 0; i < n; i++)
    {
        carr[i].input();
        fq.push(carr[i]);
    }
    cout << endl << "Enter Fahrenheit values:" << endl;
    for(int i = 0; i < n; i++)
    {
        farr[i].input();
        cq.push(farr[i]);
    }
    cout << endl << "Celsius to Fahrenheit (Array):" << endl;
    for(int i = 0; i < n; i++)
    {
        Fahrenheit f = carr[i];
        f.display();
        cout << endl;
    }
    cout << endl << "Fahrenheit to Celsius (Array):" << endl;
    for(int i = 0; i < n; i++)
    {
        Celsius c = farr[i];
        c.display();
        cout << endl;
    }
    cout << endl << "Queue Processing (FIFO - Celsius to Fahrenheit):" << endl;
    while(!fq.empty())
    {
        fq.front().display();
        cout << endl;
        fq.pop();
    }
    cout << endl << "Queue Processing (FIFO - Fahrenheit to Celsius):" << endl;
    while(!cq.empty())
    {
        cq.front().display();
        cout << endl;
        cq.pop();
    }
    cout << endl << "Equality Check:" << endl;
    for(int i = 0; i < n; i++)
    {
        if(farr[i].isEqual(carr[i]))
            cout << "Equal" << endl;
        else
            cout << "Not Equal" << endl;
    }
    return 0;
}
