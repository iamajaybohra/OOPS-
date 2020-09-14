#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class stud
{
    int roll;
    char nm[20];
    float marks;

    public:void getdata()
           {
               cout<<"\nEnter roll number";
               cin>>roll;
               cout<<"\nEnter name:";
               cin>>nm;
               cout<<"\nEnter Marks";
               cin>>marks;
           }
           void display()
           {
               cout<<"\nRoll number:"<<roll;

               cout<<"\nEnter name:"<<nm;

               cout<<"\nEnter marks"<<marks;
           }

};

int main()
{
    stud X;

    ofstream fout;
    fout.open("file.txt",ios::out|ios::app);
    X.getdata();
    fout.write((char*)&X,sizeof(X));
    fout.close();

    ifstream fin;
    fin.open("file.txt",ios::in);
    while(!fin.eof())
    {
        fin.read((char*)&X,sizeof(X));
        X.display();
    }
    fin.close();
}
