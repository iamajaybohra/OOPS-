#include <iostream>

using namespace std;

class television
{
    int model_no;
    float screen_size;
    float price;

    public:
        static int c;
        static int d;

        void get_data()
        {
            c=1;

            if(d==0)
            {
                cout<<"\nEnter the model number of television:";
                cin>>model_no;
                d=2;

                if(model_no>9999 || model_no<1000)
                {
                    d=0;
                    throw(1);
                }
            }
            if(d==2)
            {
                cout<<"\nEnter the screen size(in inches):";
                cin>>screen_size;
                d=3;

                if(screen_size<12 || screen_size>17)
                {
                    d=2;
                    throw(1);
                }
            }

            if(d==3)
            {
                cout<<"\nEnter the price of the television:";
                cin>>price;

                if(price<0 || price>5000)
                {
                    d=3;
                    throw(1);
                }
            }
        }
        void display()
        {
          cout<<"\nMODEL NUMBER:"<<model_no;
          cout<<"\nSCREEN SIZE:"<<screen_size;
          cout<<"\nPRICE OF THE TELEVESION:"<<price;
        }
};

int television::c;
int television::d;

int main()
{
    television t;

    while(t.c==0)
    {
        try
        {
           t.get_data();
        }
        catch(int x)
        {
            cout<<"\nWrong Input.Enter again\n";
            t.c=0;
        }
    }
    cout<<"\nAVAILABLE ITEMS\n";
    t.display();
    cout<<"\n\n\n";
    return 0;
}
