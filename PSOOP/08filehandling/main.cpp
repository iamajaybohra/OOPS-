#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

class student
{
    int roll;
    int marks;
    char name[20];
    public:
        student(int roll,int marks,char name[])
        {
            this->roll = roll;
            this->marks = marks;
            strcpy(name,name);
        }
        int getid(int id)
        {
            if(this->roll == id)
                return 1;
            else
                return 0;
        }

};

int main()
{
    student *s[10];
    int ch,i=-1;
    int roll,marks,pos,j,id,flag=0;
    char name[20];
    ifstream fin;
    ofstream fout;

    do
    {
        cout<<"\n\n\t\t__________STUDENT DATABASE RECORD__________\n\nSelect any one of the following:\n\n";
        cout<<"1.Create a new database\n2.Display all records\n3.Insert a record\n4.Delete a record\n5.Exit\n\nEnter your option:";
        cin>>ch;

        switch(ch)
        {
            case 1 :fout.open("file.txt");
                    do
                    {
                        i++;
                        cout<<"\nEnter roll number:";
                        cin>>roll;
                        cout<<"\nEnter Name:";
                        cin>>name;
                        cout<<"\nEnter marks:";
                        cin>>marks;
                        s[i] = new student(roll,marks,name);
                        fout<<roll<<" "<<name<<" "<<marks;
                        fout<<endl;
                        cout<<"Enter 0 To stop or 1 to Continue:";
                        cin>>ch;
                    }while(ch!=0);
                    fin.close();
                    break;

            case 2 :fout.open("file.txt");
                    cout<<"\nROLL_NO\tNAME\tMARKS\n";
                    for(j=0;j<=i;j++)
                    {
                        fout>>roll>>name>>marks;
                        cout<<roll<<"\t"<<name<<"\t"<<marks<<endl;
                    }
                    fout.close();
                    break;

            case 3 :cout<<"\nEnter The Position you want to insert:";
                    cin>>pos;
                    fout.open("file.txt");
                    fin.open("Temp.txt");
                    for(j=0;j<pos-1 && j<=i;j++)
                    {
                      fout>>roll>>name>>marks;
                      fin<<roll<<" "<<name<<" "<<marks<<endl;
                    }
                    for(int k=i;k>j;k--)
                        s[k+1] = s[k];
                    cout<<"\nEnter roll number:";
                    cin>>roll;
                    cout<<"\nEnter Name:";
                    cin>>name;
                    cout<<"\nEnter marks:";
                    cin>>marks;
                    s[j] = new student(roll,marks,name);
                    fin<<roll<<" "<<name<<" "<<marks<<endl;
                    for( ;j<=i;j++)
                    {
                      fout>>roll>>name>>marks;
                      fin<<roll<<" "<<name<<" "<<marks<<endl;
                    }
                    i++;
                    fin.close();
                    fout.close();
                    fout.open("Temp.txt");
                    fin.open("file.txt",ios::trunc);
                    for(j=0;j<=i;j++)
                    {
                        fout>>roll>>name>>marks;
                        fin<<roll<<" "<<name<<" "<<marks<<endl;
                    }
                    fin.close();
                    fout.close();
                    break;
            case 4 :cout<<"\nEnter The Roll Number Of the record to be deleted:";
                    cin>>id;
                    for(j=0;j<=i;j++)
                    {
                        flag = s[j]->getid(id);
                        if(flag==1)
                            break;
                    }
                    if(flag==1)
                    {
                        fout.open("file.txt");
                        fin.open("Temp.txt");

                        for(int k=0;k<=i;k++)
                        {
                            fout>>roll>>name>>marks;
                            if(k!=j)
                                fin<<roll<<" "<<name<<" "<<marks<<endl;
                        }
                        i--;
                        fin.close();
                        fout.close();
                        fout.open("Temp.txt");
                        fin.open("file.txt",ios::trunc);
                        for(j=0;j<=i;j++)
                        {
                            fout>>roll>>name>>marks;
                            fin<<roll<<" "<<name<<" "<<marks<<endl;
                        }
                        fin.close();
                        fout.close();
                    }
                    else
                        cout<<"The Entered Id is Not Present!\n\n";

                    break;
        default:cout<<"\n\nWrong Input!!!!!\n";
                    break;
        }
    }while(ch!=6);

return 0;
}
