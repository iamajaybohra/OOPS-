#include<iostream>
using namespace std;
class base1
{
    int id;
    string name;
    string dob;
    char a;
public:
    base1(int i,string n,string d,char A)
    {
        id=i;
        name=n;
        dob=d;
        a=A;
    }
    void display()
    {
        cout<<id<<"\t"<<name<<"\t"<<dob<<"\t"<<a<<"\t";
    }
    int get(int i)
    {
        if(i==id)
            return 1;
        else
            return 0;
    }
    void edit()
    {
         cout<<"Enter the name and DOB and Blood group\n";
         cin>>name>>dob>>a;
    }
};
class base2
{
    int height,weight;
public:
    base2(int h,int w)
    {
        height=h;
        weight=w;
    }
    void display()
    {
        cout<<height<<"\t"<<weight<<"\t";
    }
    void edit()
    {

         cout<<"Enter the Height and Weight\n";
         cin>>height>>weight;
    }
};
class base3
{
    int polno;
    string address;
public:
    base3(int p,string a)
    {
        polno=p;
        address=a;
    }
    void display()
    {
        cout<<polno<<"\t"<<address<<"\t\t";
    }
    void edit()
    {
        cout<<"Policy number and address\n";
         cin>>polno>>address;
    }
};
class derived:public base1,public base2,public base3
{
    string driving;
    int telephone;
public:
    derived(int id,string name,string dob,char a,int height,int weight,int polno,string address,string drivin,int telephon):base1(id,name,dob,a),base2(height,weight),base3(polno,address)
    {
        driving=drivin;
        telephone=telephon;
    }
    void display()
    {
        base1::display();
        base2::display();
        base3::display();
        cout<<driving<<"\t"<<telephone<<"\n";
    }
    void edit()
    {
        int ch;
        cout<<"1.NAME,DOB,BLOODGROUP\n2.HEIGHT,WEIGHT\n3.POLICY_NO,ADDRESS\n4.LICENSE,TELEPHONE\n";
        cin>>ch;
        if(ch==1)
        base1::edit();
        else if(ch==2)
        base2::edit();
        else if(ch==3)
        base3::edit();
        else if(ch==4)
        {
         cout<<"Enter driving license number and telephone Number\n";
         cin>>driving>>telephone;
        }
    }
};
int main()
{
    cout<<"This program can hold data for maximum of 20 members\n";
    derived *d[20];
    string name,address,driving,dob;
    int height,weight,telephone,polno,id;
    char A;
    int ch,i=0,ch1=1,j,id1,id2,k,flag=0;
    cout<<"\tWELCOME\n";
    do
    {
        cout<<"Enter your choice\n";
        cout<<"1.Insert a New Entry\n2.Display\n3.Delete Entry\n4.Edit\n5.Search for a record\n6.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1: do
                    {
                   cout<<"Enter the Id \n";
                   cin>>id;
                   flag=1;
                   if(i!=0)
                   {
                   for(k=0;k<i;k++)
                   {
                     id2=d[k]->get(id);
                     if(id2==1)
                        flag++;
                   }
                   }
                   if(flag==1)
                   {
                   cout<<"Enter the name and DOB and Blood group\n";
                   cin>>name;
                   cin>>dob;
                   cin>>A;
                   cout<<"Enter the Height and Weight\n";
                   cin>>height>>weight;
                   cout<<"Policy number and address\n";
                   cin>>polno;
                   cin>>address;
                   cout<<"Enter driving license number and telephone Number\n";
                   cin>>driving;
                   cin>>telephone;
                   d[i] = new derived(id,name,dob,A,height,weight,polno,address,driving,telephone);
                   cout<<"Enter 0 to stop and any other key to continue\n";
                   i++;
                   cin>>ch1;
                   }
                   else
                   {
                    cout<<"The id no is already There\n";
                    cout<<"Enter 0 to stop and any other key to continue\n";
                    cin>>ch1;
                   }
                }while(ch1!=0);
                break;
            case 2: cout<<"Id\tName\tD.O.B\t\tBloodG\tHeight\tWeight\tPolicy_No\tAddress\tLicense\tMobile\n";
                    for(j=0;j<i;j++)
                    {
                       d[j]->display();
                    }
                	break;
            case 3: cout<<"Tell the id No\n";
                    cin>>id1;
                    for(j=0;j<i;j++)
                    {
                        id2=d[j]->get(id1);
                        if(id2!=0)
                            break;
                    }
                    for(k=j;k<i&&(k+1)<i;k++)
                    {
                        d[k]=d[k+1];
                    }
                    delete d[i];
                    i--;
                    break;
            case 4: cout<<"Tell the id No\n";
                    cin>>id1;
                    flag=0;
                    for(k=0;k<i;k++)
                    {
                     id2=d[k]->get(id1);
                     if(id2==1)
                        flag++;
                    }

                    if(flag==1)
                    {
                    for(j=0;j<i;j++)
                    {
                        id2=d[j]->get(id1);
                        if(id2!=0)
                            break;
                    }
                    d[j]->edit();
                    }
                    if(flag==0)
                    {
                        cout<<"The Id is not there\n";
                    }
                    break;
            case 5: cout<<"Tell the id No\n";
                    cin>>id1;
                    for(j=0;j<i;j++)
                    {
                        id2=d[j]->get(id1);
                        if(id2!=0)
                            break;
                    }
                    d[j]->display();
                    break;
            case 6: cout<<"bye\n";
                break;

        }

    }while(ch!=6);

}
