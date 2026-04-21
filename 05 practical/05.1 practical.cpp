#include<iostream>
using namespace std;
#include<string>

int main()
{
    string str;
    int i;
    cout<<"enter string : ";
    getline(cin,str);

    char s[str.length()+1], t[str.length()+1];

    for(i=0;i<str.length();i++)
        s[i]=str[i];
    s[str.length()]='\0';

    for(i=0;i<str.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i]=s[i]+32;
    }

    int j=0;
    for(i=0;i<str.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') ||
           (s[i]>='0' && s[i]<='9') ||
           (s[i]==' ' && i>0 && s[i-1]!=' '))
        {
            t[j++]=s[i];
        }
    }

    if(j>0 && t[j-1]==' ')
        j--;
    t[j]='\0';

    string words[100];
    int count=0;
    string temp="";

    for(i=0;t[i]!='\0';i++)
    {
        if(t[i]!=' ')
            temp+=t[i];
        else
        {
            words[count++]=temp;
            temp="";
        }
    }
    if(temp!="")
        words[count++]=temp;

    int freq[100]={0};
    int flag;
    for(i=0;i<count;i++)
    {
        flag=0;
        for(int k=0;k<i;k++)
        {
            if(words[i]==words[k])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;

        freq[i]=1;
        for(int k=i+1;k<count;k++)
        {
            if(words[i]==words[k])
                freq[i]++;
        }
    }
    cout<<"\nword frequencies:\n";
    for(i=0;i<count;i++)
    {
        if(freq[i]!=0)
            cout<<words[i]<<" : "<<freq[i]<<endl;
    }

    return 0;
}
