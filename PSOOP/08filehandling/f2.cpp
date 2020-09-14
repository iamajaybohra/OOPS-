#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin;
    string line;
    fin.open("C:/Users/user/Desktop/file.txt");
    if(fin.is_open())
    {
        while(getline(fin,line))
        {
            cout<<line;
        }
    }
    else
        cout<<"Unable to open file";
    fin.close();
    return 0;
}
