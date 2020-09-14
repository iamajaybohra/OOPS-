#include <iostream>
using namespace std;

class Complex
{
    public: int real,img;
            Complex()
            {
                real=0;
                img=0;
            }
            Complex(int x,int y)
            {
                real=x;
                img=y;
            }
            Complex operator * (Complex C)
            {
                Complex C3;
                C3.real=real*C.real-img*C.img;
                C3.img=real*C.img+img*C.real;
                return C3;
            }
            Complex operator / (Complex C)
            {
                Complex C3;
                C3.real=((real*C.real+img*C.img)/(C.real*C.real+C.img*C.img));
                C3.img=((img*C.real-real*C.img)/(C.real*C.real+C.img*C.img));
                return C3;
            }

            friend Complex operator + (Complex C1,Complex C2);
            friend Complex operator - (Complex C1,Complex C2);
            friend istream& operator >> (istream&in,Complex&C1);
            friend ostream& operator << (ostream&out,Complex &C1);

};

istream &operator >> (istream &in,Complex &C1)
{
    cout<<"\nEnter Real Part:";
    in>>C1.real;
    cout<<"\nEnter Imaginary Part:";
    in>>C1.img;
    return in;
}

ostream &operator << (ostream &out,Complex &C1)
{
    out<<C1.real<<"+i"<<C1.img<<"j"<<"\n";
    return out;
}

Complex operator + (Complex C1,Complex C2)
{
    Complex C3;
    C3.real=C1.real+C2.real;
    C3.img=C1.img+C2.img;
    return C3;
}

Complex operator - (Complex C1,Complex C2)
{
    Complex C3;
    C3.real=C1.real-C2.real;
    C3.img=C1.img-C2.img;
    return C3;
}

int main()
{
    int choice,x,y;
    Complex X,Y,Z;

    cout<<"\nCOMPLEX NUMBER 1:\n";
    cin>>X;
    cout<<"\nCOMPLEX NUMBER 2:\n";
    cin>>Y;

    cout<<X;
    cout<<Y;

    while(1)
    {cout<<"\n\n\nSELECT ANY ONE OF THE FOLLOWING:\n1.Addition of Complex Number\n2.Subtraction of Complex Number\n3.Division of Complex Number\n4.Multiplication Of Complex Number\n5.EXIT\n\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:{Z=X+Y;
               cout<<"\nADDITION:";
               cout<<Z;
               break;}

        case 2:{Z=X-Y;
               cout<<"\nSUBTRACTION:";
               cout<<Z;
               break;}

        case 3:{Z=X*Y;
               cout<<"\nMULTIPLICATION:";
               cout<<Z;
               break;}

        case 4:{Z=X/Y;
                cout<<"\nDIVISION:";
                cout<<Z;
                break;}

        case 5:return 0;

       default:cout<<"Wrong Choice!!!!!";
               break;
    }
    }

    return 0;
}
