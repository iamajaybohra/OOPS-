#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class STUD
{
    int roll;
    char nm[20];

    public:STUD(int r,char n[])
           {
               roll=r;
               strcpy(nm,n);
           }
           int check(int i)
           {
               if(i==roll)
                    return 0;
               else
                    return 1;
           }
};
int main()
{
    int ch,i=-1,q,pos,j;
    int roll;char nm[20];

    STUD *S[10];
    ofstream fout;
    ifstream fin;

    //Create new Database
    fout.open("C:/Users/user/Desktop/Student.txt");
    do
    {
        i++;
        cout<<"\nEnter roll number:";
        cin>>roll;
        for(int j=1;j<=i;j++)
        {
            q=S[j-1]->check(roll);
            if(q==0)
            {
                printf("Roll number already found!!");
                break;
            }
        }
        if(q==0)
            break;
        cout<<"\nEnter name:";
        cin>>nm;
        S[i]=new STUD(roll,nm);
        fout<<roll<<" "<<nm<<"\n";
        cout<<"Enter 0 to stop 1 to continue:";
        cin>>ch;
    }while(ch==1);
    fout.close();

    //Display
    fin.open("C:/Users/user/Desktop/Student.txt");
    cout<<"\nROll NO    Name";
    for(int j=0;j<=i;j++)
    {
        fin>>roll>>nm;
        cout<<"\n"<<roll<<"          "<<nm;

    }
    fin.close();


    //Insert
    fin.open("C:/Users/user/Desktop/Student.txt");
    fout.open("Temp.txt");
    cout<<"Enter the position at which you want to insert:";
    cin>>pos;
    for(j=0;j<pos-1 && j<=i;j++)
    {
        fin>>roll>>nm;
        fout<<roll<<nm<<"\n";
    }
    for(int k=i;k>j;k--)
    {
        S[k+1]=S[k];
    }
    cout<<"\nEnter roll number:";
    cin>>roll;
    cout<<"\nEnter name:";
    cin>>nm;
    S[j]=new STUD(roll,nm);
    fout<<roll<<nm<<"\n";
    for(;j<=i;j++)
    {
        fin>>roll>>nm;
        fout<<roll<<nm<<"\n";
    }
    i++;
    fin.close();
    fout.close();
    fin.open("Temp.txt");
    fout.open("C:/Users/user/Desktop/Student.txt");
    for(int j=0;j<=i;j++)
    {
        fin>>roll>>nm;
        fout<<roll<<nm<<"\n";
    }
    fin.close();
    fout.close();


    //Display
    fin.open("C:/Users/user/Desktop/Student.txt");
    cout<<"\nROll NO    Name";
    for(int j=0;j<=i;j++)
    {
        fin>>roll>>nm;
        cout<<"\n"<<roll<<"          "<<nm;

    }
    fin.close();

    return 0;


    //Modify
    fin.open("C:/Users/user/Desktop/Student.txt");
    q=1;
    cout<<"Enter the roll number of which you want to modify data:";
    cin>>pos;
    for(int k=0;k<=i;k++)
    {
       q=S[k]->check(pos);
       if(q==0)
            break;
    }
    if(q==1)
    {
        printf("No such data found!!!");
        break;
    }
    for(j=0;j<k;j++)



}
