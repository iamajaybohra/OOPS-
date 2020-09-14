#include <iostream>

using namespace std;

template<class T>
class matrix
{
    int row;
    int col;
    T **mat;

    public:int i,j,k;
           void transpose();
           void getmat()
           {
               cout<<"\nEnter number of rows:";
               cin>>row;
               cout<<"\nEnter number of columns:";
               cin>>col;
               mat=new T*[row];
               for(i=0;i<row;i++)
               {
                   mat[i]=new T[col];
               }

               for(i=0;i<row;i++)
                 for(j=0;j<col;j++)
                    cin>>mat[i][j];

               for(i=0;i<row;i++)
               {for(j=0;j<col;j++)
                    cout<<mat[i][j]<<" ";
                    cout<<"\n";
               }

           }

           void sum(matrix mat1)
           {

               for(i=0;i<row;i++)
               {
                    for(j=0;j<col;j++)
                      cout<<(mat[i][j]+mat1.mat[i][j])<<" ";
                    cout<<"\n";
               }
           }
           void sub(matrix mat1)
           {
               for(i=0;i<row;i++)
               {for(j=0;j<col;j++)
                  cout<<(mat[i][j]-mat1.mat[i][j])<<" ";
                  cout<<"\n";
               }
           }
           void multiplication(matrix mat1)
           {
               int sum=0;
               for(i=0;i<row;i++)
               {
                for(j=0;j<mat1.col;j++)
                {  sum=0;
                    for(k=0;k<col;k++)
                    {
                      sum=sum+mat[i][k]*mat1.mat[k][j];
                    }
                 cout<<sum<<" ";
                }
                cout<<"\n";
               }
           }
           friend istream &operator >>(istream &in,matrix M);
           friend ostream &operator <<(ostream &out,matrix M);
};

istream &operator >>(istream &in,matrix M)
{
    cout<<"\nEnter number of rows:";
    cin>>row;
    cout<<"\nEnter number of columns:";
    cin>>col;
    mat=new T*[row];
    for(i=0;i<row;i++)
    {
    mat[i]=new T[col];
    }

    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            cin>>mat[i][j];
}

template<typename T>
void matrix<T>::transpose()
{
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cout<<mat[j][i]<<" ";
        cout<<"\n";
    }
}
int main()
{
    int choice,choice1;
    matrix<int> A;
    matrix<int> B;
    matrix<double> C;
    matrix<double> D;

    cout<<"\n\nSELECT ANY ONE OF THE FOLLOWING:\n\n1.Integer matrix\n2.Double Matrix\nEnter your Option:";
    cin>>choice1;

    switch(choice1)
    {
     case 1:
       while(1)
       { cout<<"\n\nSELECT ANY ONE OF THE FOLLOWING:\n\n1.Enter a matrix\n2.Addition of the matrix\n3.Subtraction of the matrix\n4.Multiplication of the matrix\n5.Transpose of matrix\n6.Exit\n\nEnter your choice:";
         cin>>choice;

         switch(choice)
         {
         case 1:A.getmat();
                cout<<"\n";
                break;

         case 2:B.getmat();
                cout<<"\n";
                A.sum(B);
                break;

         case 3:B.getmat();
                cout<<"\n";
                A.sub(B);
                break;

         case 4:B.getmat();
                cout<<"\n";
                A.multiplication(B);
                break;

         case 5:A.transpose();
                break;

         case 6:return 0;

         default:cout<<"WRONG INPUT";
                break;

         }
        }
         break;
     case 2:
        while(1)
        {cout<<"\n\nSELECT ANY ONE OF THE FOLLOWING:\n\n1.Enter a matrix\n2.Addition of the matrix\n3.Subtraction of the matrix\n4.Multiplication of the matrix\n5.Transpose of matrix\n6.Exit\n\nEnter your choice:";
         cin>>choice;

         switch(choice)
         {
         case 1:C.getmat();
                break;

         case 2:D.getmat();
               C.sum(D);
               break;

         case 3:D.getmat();
               C.sub(D);
               break;

         case 4:D.getmat();
               C.multiplication(D);
               break;

         case 5:C.transpose();
               break;

         case 6:return 0;

         default:cout<<"WRONG INPUT";
                break;

         }
        }
        break;
    default:cout<<"WRONG INPUT";
            break;

    }
   return 0;

}
