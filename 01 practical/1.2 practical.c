#include <stdio.h>
struct Books
{
    int bookId;
    char title[30];
    char author[20];
    int copies;
}b[20];
void addBook(struct Books b[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter Id: ");
        scanf("%d",&b[i].bookId);
        printf("Enter title: ");
        getchar();
        gets(b[i].title);
        printf("Enter author: ");
        gets(b[i].author);
        printf("Enter no of copies: ");
        scanf("%d",&b[i].copies);
    }
}

void issueBook(struct Books b[],int n)
{
    int id,i;
    printf("Which book id you want to issue: ");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(b[i].bookId==id)
        {
            if(b[i].copies>0)
            {
                printf("Book is issued");
                b[i].copies--;
            }
            else
            {
                printf("Book is not available.");
            }

        }
    }
}

void returnBook(struct Books b[],int n)
{
    int id,i;
    printf("Which book id you want to return: ");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(b[i].bookId==id)
        {
            printf("Book is returned");
            b[i].copies++;
        }
    }
}

void display(struct Books b[],int n,int id)
{
        int i;
        for(i=0;i<n;i++)
        {
            if(b[i].bookId==id)
            {
                printf("Book Id: %d", b[i].bookId);
                printf("Title: %s",b[i].title);
                printf("Author: %s,",b[i].author);
                printf("Copies: %d",b[i].copies);
            }
        }


}
int main()
{
    int ch,n;

    x: printf("\n 1) Add book\n");
    printf("2) Issue book\n");
    printf("3) Return book\n");
    printf("4) Display total books\n");
    printf("5) Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        {
            printf("How many books you want to add: ");
            scanf("%d",&n);
            addBook(b,n);
            goto x;
        }
    case 2:
        {
            issueBook(b,n);
            goto x;
        }
    case 3:
        {
            returnBook(b,n);
            goto x;
        }
    case 4:
        {
            int id;
            printf("Which book details you want to access. Enter id: ");
            scanf("%d",&id);
            display(b,n,id);
            goto x;
        }
    case 5:
        {
            printf("Thank you.");
            break;
        }
    default:
        {
            printf("Invalid input.");
        }
    }
}
