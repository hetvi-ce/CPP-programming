#include<iostream>
using namespace std;
int main()
{
    int n,m,i,j,k;
    cout<<"enter number of elements for array 1 :";
    cin>>n;
    cout<<"enter number of elements for array 2 :";
    cin>>m;
    int* arr1=new int[n];
    int* arr2=new int[m];

    cout<<"enter sorted elements for array 1 :";
    for(i=0;i<n;i++)
        cin>>arr1[i];
    cout<<"enter sorted elements for array 2 :";
    for(j=0;j<m;j++)
        cin>>arr2[j];

    int* merged=new int[n+m];
    i=0,j=0;k=0;
    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }
    while(i < n)
    {
        merged[k++] = arr1[i++];
    }

    while(j < m)
    {
        merged[k++] = arr2[j++];
    }
    cout<<"merged sorted array : ";
    for(i=0;i<k;i++)
    {
        cout<<" "<<merged[i]<<" ";
    }
    return 0;
}
