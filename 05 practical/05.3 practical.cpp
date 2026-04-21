#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    int choice;
    string name, searchName;
    int qty;
    float price;

start:
    cout<<"\n1. Add Item\n2. View All Items\n3. Search Item\n4. Exit\n";
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            ofstream fout("inventory.txt", ios::app);
            cout<<"Enter item name: ";
            cin>>name;
            cout<<"Enter quantity: ";
            cin>>qty;
            cout<<"Enter price: ";
            cin>>price;
            fout<<name<<" "<<qty<<" "<<price<<endl;
            fout.close();
            cout<<"Item added successfully\n";
            goto start;
        }

        case 2:
        {
            ifstream fin("inventory.txt");

            if(!fin)
            {
                cout<<"File not found\n";
                goto start;
            }

            while(fin>>name>>qty>>price)
            {
                cout<<"Name: "<<name<<"  Qty: "<<qty<<"   Price: "<<price<<endl;
            }

            fin.close();
            goto start;
        }

        case 3:
        {
            ifstream fin("inventory.txt");

            if(!fin)
            {
                cout<<"File not found\n";
                goto start;
            }

            cout<<"Enter item name to search: ";
            cin>>searchName;

            int found=0;

            while(fin>>name>>qty>>price)
            {
                if(name==searchName)
                {
                    cout<<"Found "<<endl<<" Name: "<<name<<"   Qty: "<<qty<<"   Price: "<<price<<endl;
                    found=1;
                }
            }

            if(found==0)
                cout<<"Item not found\n";

            fin.close();
            goto start;
        }

        case 4:
            cout<<"Exiting...\n";
            break;

        default:
            cout<<"Invalid choice\n";
            goto start;
    }

    return 0;
}
