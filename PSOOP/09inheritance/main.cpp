#include <iostream>
#include<string.h>

using namespace std;

class personal
{
    char name[20];
    char mob[11];
    char email[20];
    char sex;

    public:personal(char n[],char m[],char e[],char s)
            {
                strcpy(name,n);
                strcpy(mob,m);
                strcpy(email,e);
                sex=s;
            }
           display1()
            {
                cout<<"EMPLOYEE'S BIODATA:";
                cout<<"\nNAME:";
                cout<<name<<"\n";
                cout<<"\nMOB:";
                cout<<mob<<"\n";
                cout<<"\nE-MAIL:";
                cout<<email<<"\n";
                cout<<"\nGENDER:";
                cout<<sex<<"\n";
            }
};

class professional
{
    char skill1[20];
    char skill2[20];
    char skill3[20];

    public: professional(char s1[],char s2[],char s3[])
            {
                strcpy(skill1,s1);
                strcpy(skill2,s2);
                strcpy(skill3,s3);
            }
            display2()
            {
                cout<<"\nSKILL 1:";
                cout<<skill1<<"\n";
                cout<<"\nSKILL 2:";
                cout<<skill2<<"\n";
                cout<<"\nSKILL 3:";
                cout<<skill3<<"\n";

            }

};

class academic:public personal,public professional
{
    int Xyear;
    int XIIyear;
    int FEyear;
    float Xper;
    float XIIper;
    float FEper;

    public:academic(int X,int XII,int FE,float Xp,float XIIp,float FEp,char n[],char m[],char e[],char s,char s1[],char s2[],char s3[]):personal(n,m,e,s),professional(s1,s2,s3)
           {
               Xyear=X;
               XIIyear=XII;
               FEyear=FE;
               Xper=Xp;
               XIIper=XIIp;
               FEper=FEp;

           }
           display()
           {
               display1();
               display2();
               cout<<"\n\nX year:";
               cout<<Xyear;
               cout<<"\n\nX marks:";
               cout<<Xper;
               cout<<"\n\nXII year:";
               cout<<XIIyear;
               cout<<"\n\nXII marks:";
               cout<<XIIper;
               cout<<"\n\nFE year:";
               cout<<FEyear;
               cout<<"\n\nFE marks:";
               cout<<FEper;
           }

};
int main()
{
    int X,XII,FE;
    float Xp,XIIp,FEp;
    char nm[20],mob[11],email[20],s,dob[10],s1[20],s2[20],s3[20];

    cout<<"\nENTER PERSONAL INFORMATION:\n";
    cout<<"\nENTER NAME:";
    cin>>nm;
    cout<<"\nENTER GENDER(M/F):";
    cin>>s;
    cout<<"\nENTER MOBILE NUMBER:";
    cin>>mob;
    cout<<"\nENTER E-MAIL ID:";
    cin>>email;
    cout<<"\nENTER PROFESSIONAL INFORMATION:\n";
    cout<<"\nENTER SKILL 1:";
    cin>>s1;
    cout<<"\nENTER SKILL 2:";
    cin>>s2;
    cout<<"\nENTER SKILL 3:";
    cin>>s3;
    cout<<"\nENTER ACADEMIC INFORMATION:\n";
    cout<<"\nENTER X PASSING YEAR:";
    cin>>X;
    cout<<"\nENTER X PERCENTAGE:";
    cin>>Xp;
    cout<<"\nENTER XII PASSING YEAR:";
    cin>>XII;
    cout<<"\nENTER XII MARKS:";
    cin>>XIIp;
    cout<<"\nENTER FIRST YEAR PASSING YEAR:";
    cin>>FE;
    cout<<"\nENTER FIRST YEAR MARKS:";
    cin>>FEp;

    academic *A;
    A=new academic(X,XII,FE,Xp,XIIp,FEp,nm,mob,email,s,s1,s2,s3);
    //academic A(X,XII,FE,Xp,XIIp,FEp,nm,mob,email,s,s1,s2,s3);
    A->display();
    delete A;
}
