#include<iostream>
using namespace std;
struct item
{
    int item_id;
    string item_name;
    int item_price;
    int item_stock;
public:
    item()
    {
        item_id=01;
        item_name="book";
        item_price=20;
        item_stock=100;
    }
    item(int Id,string Name, int Price, int Stock)
    {
        item_id=Id;
        item_name=Name;
        item_price=Price;
        item_stock=Stock;
    }
    void add_item();
    void add_stock();
    void sell_stock();
    void display();
    int getId();
};
void item::add_stock()
{
    int stock;
    cout<<"enter how many stock you want to add : ";
    cin>>stock;
    item_stock=item_stock+stock;
    cout<<"stock added successfully"<<endl;
    return;
}
void item::sell_stock()
{
    int stock;
    cout<<"enter how many stock you want to sell : ";
    cin>>stock;
    if(item_stock<stock)
    {
        cout<<"insufficient stock"<<endl;
        return;
    }
    item_stock=item_stock-stock;
    cout<<"stock sold successfully"<<endl;
    return;
}
void item::display()
{
    cout<<"---------------------"<<endl;
    cout<<"item id : "<<item_id<<endl;
    cout<<"item name : "<<item_name<<endl;
    cout<<"item price : "<<item_price<<endl;
    cout<<"item stock : "<<item_stock<<endl;
}
int item :: getId()
{
    return item_id;
}
int main()
{
    item I[30];
    int id,price,stock,ch,count=1;
    int i=0,ID;
    string name;
    do
    {
        cout<<"--------inventory--------"<<endl<<"1. add item"<<endl<<"2. add stock"<<endl<<"3. sell stock"<<endl<<"4. display"<<endl<<"5. exit"<<endl;
        cout<<"enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                if(count>30)
                {
                    cout<<"item limit reached";
                    break;
                }
                int id,price,stock;
                string name;
                cout<<"enter data for item "<<endl;
                cout<<"enter item id : ";
                cin>>id;
                cout<<"enter name : ";
                cin>>name;
                cout<<"enter price for item : ";
                cin>>price;
                cout<<"enter stock for item : ";
                cin>>stock;
                I[count]=item(id,name,price,stock);
                count++;
                break;
            }
            case 2:
            {
                cout<<"enter id of item in which you want to add stock : ";
                cin>>ID;
                for(i=0;i<=count;i++)
                {
                   if(I[i].getId() == ID)
                   {
                       I[i].add_stock();
                       break;
                   }
                }
                break;
            }
        case 3:
            {
                cout<<"enter id of item in which you want to sell stock : ";
                cin>>ID;
                for(i=0;i<=count;i++)
                {
                   if(I[i].getId() == ID)
                   {
                       I[i].sell_stock();
                       break;
                   }
                }
                break;
            }
        case 4:
            {
                for(i=0;i<count;i++)
                {
                    I[i].display();
                }
                break;
            }
        case 5:
            {
                return 0;
            }
        default :
            {
                cout<<"Enter a valid choice";
            }
        }
    }while(ch!=5);
    return 0;
}
