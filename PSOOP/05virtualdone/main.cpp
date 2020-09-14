#include<iostream>
#define PI 3.14159
using namespace std;

class shape
{
protected:
    float x,y;
public:
    virtual void getdata()
    {

    }
    virtual void area()=0;
};
class rectangle:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE LENGTH AND BREADTH\n";
        cin>>x>>y;
    }
    void area()
    {
        float a = x*y;
        cout<<"AREA OF RECTANGLE IS::"<<a<<endl;
    }
};
class square:public shape
{
 public:
    void getdata()
    {
        cout<<"ENTER THE SIDE\n";
        cin>>x;
    }
    void area()
    {
        float a = x*x;
        cout<<"AREA OF SQAURE IS::"<<a<<endl;
    }
};
class triangle:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE BASE LENGTH AND ALTITUDE\n";
        cin>>x>>y;
    }
    void area()
    {
        float a = (x*y)/2;
        cout<<"AREA OF TRIANGLE IS::"<<a<<endl;
    }
};
class circle:public shape
{
public:
    void getdata()
    {
        cout<<"ENTER THE RADIUS\n";
        cin>>x;
    }
    void area()
    {
        double a = PI*x*x;
        cout<<"AREA OF RECTANGLE IS::"<<a<<endl;
    }
};
int main()
{
    shape *s;
    int ch;
    do
    {
    cout<<"WHOSE AREA YOU WANT TO CALCULATE?\n";
    cout<<"1.Rectangle\n2.Square\n3.Triangle\n4.Circle\n5.Exit\n";
    cin>>ch;
    switch(ch)
    {
            case 1: s = new rectangle;
                    s->getdata();
                    s->area();
                    break;
            case 2: s = new square;
                    s->getdata();
                    s->area();
                    break;
            case 3: s = new triangle;
                    s->getdata();
                    s->area();
                    break;
            case 4: s = new circle;
                    s->getdata();
                    s->area();
                    break;
    }
    }while(ch!=5);
}

