#include<iostream>
#include<string.h>
using namespace std;

class BOOKS
{
    int id;
    char title[20];
    char author[20];
    float price;
    int stock;

    public:BOOKS(int i,char t[],char a[],float p,int s)
           {
               id=i;
               strcpy(title,t);
               strcpy(author,a);
               price=p;
               stock=s;
           }
           int check(int a)
           {
               if(id==a)
                return 0;
               else
                return 1;
           }
           void display()
           {
               cout<<"\n"<<id<<"\t"<<title<<"\t"<<author<<"\t"<<price<<"\t"<<stock;
           }
};

int main()
{
    BOOKS *B[10];
    int ch,i=-1,j,q,d;
    int id,stock;
    char title[20],author[20];
    float price;

    while(1)
    {cout<<"\n::WELCOME TO BOOK'S DATABASE::\n\nSELECT ANY ONE OF THE FOLLOWING:\n\n1.ENTER NEW BOOK STOCK\n2.DISPLAY CURRENT STOCK\n3.RENT BOOKS4.EXIT\n\nEnter your option:";
    cin>>ch;
    switch(ch)
    {
        case 1:do
               {
                   i++;
                   cout<<"\nEnter Book ID:";
                   cin>>id;
                   for(j=1;j<=i;j++)
                   {
                      q=B[j-1]->check(id);
                      if(q==0)
                      {
                          cout<<"BOOK ID ALREADY EXIST!!!";
                          break;
                      }
                   }
                   if(q==0)
                   {
                       break;
                   }
                   cout<<"\nEnter Book Title:";
                   cin>>title;
                   cout<<"\nEnter Book's author name:";
                   cin>>author;
                   cout<<"\nEnter Price:";
                   cin>>price;
                   cout<<"\nEnter Quantity:";
                   cin>>stock;
                   B[i]=new BOOKS(id,title,author,price,stock);
                   cout<<"\nEnter 0 to stop or 1 to continue:";
                   cin>>d;
               }
               while(d==1);
               break;

        case 2:cout<<"\n"<<"id"<<"\t"<<"title"<<"\t"<<"author"<<"\t"<<"price"<<"\t"<<"stock";
               for(j=0;j<=i;j++)
                        B[j]->display();
               break;

        case 4:cout<<"Thank You:::";
                    return 0;

        default:cout<<"Wrong Input.Input Again:";
                break;

    }

}
}
