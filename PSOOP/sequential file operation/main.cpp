#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class stud
{
    int roll;
    char name[20];
    float marks;


    public:void getdata()
           {
               cout<<"\nEnter roll no.";
               cin>>roll;
               cout<<"\nEnter Name";
               cin>>name;
               cout<<"\nEnter Marks";
               cin>>marks;
           }
           void putdata()
           {
               cout<<"\nROLL NO:";
               cout<<roll;
               cout<<"\nNAME:";
               cout<<name;
               cout<<"\nMARKS:";
               cout<<marks;
           }

};



int main()
{
    stud X[3];

    int i;
    fstream file;
    file.open("C:/Users/user/Desktop/file/STUD.txt",ios::in|ios::out);

    for(i=0;i<3;i++)
    {
        X[i].getdata();
        file.write((char*)&X[i],sizeof(X[i]));
    }

    for(i=0;i<3;i++)
    {
        file.read((char*)&X[i],sizeof(X[i]));
        X[i].putdata();
    }
    file.close();

    return 0;
}
