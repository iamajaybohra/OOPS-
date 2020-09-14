#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    char name[20];
    fstream file;
    file.open("STUD.dat",ios::in|ios::out);
    cin>>name;
    file.write((char*)&name,sizeof(name));
    file.close();
    return 0;
}
