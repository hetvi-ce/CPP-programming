#include<iostream>
#include<cstdlib>
using namespace std;
#include<ctime>
int recursive(int *x,int i)
{
    if(i==0)
        return 0;

    return x[i-1]+recursive(x,i-1);
}
int main()
{
    int a[100000];
    int n,i,r,sum=0;
    cout<<"enter n:";
    cin>>n;
    //cout<<"enter values: "<<endl;
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100+1;
//        cout<<i+1<<" : ";
//        cin>>a[i];
    }
    clock_t l1=clock();
    r=recursive(a,n);
    clock_t l2=clock();
    double duration1 = double(l2 - l1) / CLOCKS_PER_SEC;
    cout<<endl<<"sum of elements using recursion : "<<r<<"  time for this : "<<duration1<<endl;
    clock_t l3=clock();
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    clock_t l4=clock();
    double duration2 = double(l4 - l3) / CLOCKS_PER_SEC;
    cout<<"sum of elements using iteration : "<<sum<<"  time for this : "<<duration2<<endl;
    return 0;
}


