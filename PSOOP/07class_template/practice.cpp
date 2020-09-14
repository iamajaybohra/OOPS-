#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<class T>
class matrix
{
    T **m;
    public:T get(int row,int col)
           {
               int i,j;
               m=(T**)malloc(row*sizeof(T*));
               for(i=0;i<row;i++)
                m[i]=(T*)malloc(col*sizeof(T));
               cout<<"\nEnter matrix row wise\n";
               for(i=0;i<row;i++)
               {
                   for(j=0;j<col;j++)
                   {
                       cin>>m[i][j];
                   }
               }

           }
           T display(int row,int col)
           {
               int i,j;
               for(i=0;i<row;i++)
               {
                   for(j=0;j<col;j++)
                   {
                       cout<<m[i][j]<<" ";
                   }
                   cout<<"\n";
               }
           }
};

int main()
{
    matrix<int> M1;
    int row,col;
    cout<<"\nEnter number of rows:";
    cin>>row;
    cout<<"\nenter number of columns:";
    cin>>col;
    M1.get(row,col);
    M1.display(row,col);

    return 0;
}
