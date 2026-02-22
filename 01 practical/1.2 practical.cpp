#include<iostream>
using namespace std;
class library
{
    struct book
    {
        int book_id;
        char title[40];
        char author[40];
        int copies;
    };
    int no_books=0;
    book b[10];
public:

   void add_book();
   void issue_book(int);
   void return_book(int);
   void display_book();
};

void library::add_book()
{
    cout<<"enter book id : ";
    cin>>b[no_books].book_id;
    cout<<"enter title : ";
    cin>>b[no_books].title;
    cout<<"enter name of auther : ";
    cin>>b[no_books].author;
    cout<<"enter copies : ";
    cin>>b[no_books].copies;
    no_books++;
}
void library::issue_book(int x)
{
    int i;
    for(i=0;i<no_books;i++)
    {
        if(b[i].book_id== x)
        {
            if(b[i].copies>0)
            {
                b[i].copies--;
                cout<<"book issued successfully"<<endl;
            }
            else
            {
                cout<<"no copies available"<<endl;
            }
            return;
        }
        else
        {
            cout<<"book not found"<<endl;
        }
    }
}
void library::return_book(int x)
{
    int i;
    for(i=0;i<no_books;i++)
    {
        if(b[i].book_id== x)
        {
            b[i].copies++;
            cout<<"book returned successfully"<<endl;
            return;
        }
        else
        {
            cout<<"book not found"<<endl;
        }
    }
}
void library::display_book()
{
    int i;
    cout<<no_books<<" books are available in library"<<endl;
    if(no_books>0)
    {
        for(i=0;i<no_books;i++)
        {
            cout<<"book id : "<<b[i].book_id<<endl<<"title : "<<b[i].title<<endl<<"name of author : "<<b[i].author<<endl<<"copies : ";
            cout<<b[i].copies<<endl<<"availabe : ";
            if(b[i].copies==0)
                cout<<"no";
            else
                cout<<"yes";
            cout<<endl<<endl;
        }
    }
    else
    {
        cout<<"no books are available in library";
    }
}
int main()
{
    library lib;
    int ch,id;
    n:
        cout<<"---library--"<<endl<<"1. add book"<<endl<<"2. issue book"<<endl<<"3. return book"<<endl<<"4. display book"<<endl<<"5. exit"<<endl;
        cout<<"enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            lib.add_book();
            goto n;

        case 2:
            cout<<"enter book id : ";
            cin>>id;
            lib.issue_book(id);
            goto n;

        case 3:
            cout<<"enter book id : ";
            cin>>id;
            lib.return_book(id);
            goto n;

        case 4:
            lib.display_book();
            goto n;

        case 5:
            return 0;

        default:
            cout<<"enter a valid choice";
            goto n;
        }
    return 0;
}
