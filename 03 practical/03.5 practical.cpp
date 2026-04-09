#include<iostream>
using namespace std;
int summ(long long num)
{
    int x,sum=0;
    do
    {
        x=num%10;
        sum+=x;
        num=num/10;
    }while(num!=0);
    return sum;
}
int main()
{
    long long num;
    int i,k,fsum=0;
    cout<<"enter number : ";
    cin>>num;
    cout<<"enter number of repetition : ";
    cin>>k;
    for(i=0;i<k;i++)
    {
        fsum+=summ(num);
    }
    do
    {
        fsum=summ(fsum);
    }while(fsum%10==0);

    cout<<"final number is : "<<fsum<<endl;
    return 0;
}
