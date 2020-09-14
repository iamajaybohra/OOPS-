#include <iostream>

using namespace std;

class divide
{
    public:double x,y;
           static int c;
           void get_data()
           {   c=1;
               cout<<"\nENTER THE FIRST NUMBER:";
               cin>>x;
               cout<<"\nENTER THE SECOND NUMBER:";
               cin>>y;

               if(y==0)
                {
                    c=0;
                    throw(1);
                }
           }
           void print_data()
           {
               cout<<"\nFIRST/SECOND="<<x/y;
               cout<<"\n";
           }

};

int divide::c;

int main()
{
    divide d;


    while(d.c==0)
    {
        try{
            d.get_data();
        }
        catch(int z)
        {
            cout<<"\nDIVIDE BY ZERO NUMBER.RE-ENTER THE NUMBERS";
        }
    }

    d.print_data();
    return 0;
}
