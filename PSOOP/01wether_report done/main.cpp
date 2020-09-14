#include <iostream>
using namespace std;

class weather_report
{
    int day_of_mon;
    float hightemp,lowtemp,amount_rain,amount_snow;
    static int avg_ht,avg_lt,avg_rain,avg_snow,c;

    public:
        weather_report()
        {
            day_of_mon=0;
            hightemp=0;
            lowtemp=0;
            amount_rain=0;
            amount_snow=0;

        }
        
        void get_data()
        {
            cout<<"\nEnter the highest temperature on that day:";
            cin>>hightemp;
            avg_ht+=hightemp;
            cout<<"\nEnter the lowest temperature on that day:";
            cin>>lowtemp;
            avg_lt+=lowtemp;
            cout<<"\nEnter the amount of rainfall:";
            cin>>amount_rain;
            avg_rain+=amount_rain;
            cout<<"\nEnter the amount of snowfall:";
            cin>>amount_snow;
            avg_snow+=amount_snow;
            c++;
        }

         void report()
        {
            cout<<hightemp;
            cout<<lowtemp;
            cout<<amount_rain;
            cout<<amount_snow;
            cout<<"\n\n";
        }

        void average()
        {
            cout<<"\n FOR THIS MONTH:";
            cout<<"\nAverage HIGH Temperature of the month:"<<(avg_ht/c);
            cout<<"\nAverage LOW Temperature of the month:"<<(avg_lt/c);
            cout<<"\nAverage Rainfall of the month:"<<(avg_rain/c);
            cout<<"\nAverage Snowfall of the month:"<<(avg_snow/c);
            cout<<"\n\n";

        }

};

int weather_report::avg_ht;
int weather_report::avg_lt;
int weather_report::avg_rain;
int weather_report::avg_snow;
int weather_report::c;

int main()
{
    int choice,d,i;
    weather_report m1[30];



    while(1)
    {
        cout<<"\n1.Enter the data\n2.See particular day report\n3.Monthly report of the Weather\n4.Exit\n\nENTER YOUR CHOICE:";
        cin>>choice;

        switch(choice)
        {
            case 1:cout<<"\nEnter the day of the month:";
                   cin>>d;
                   m1[d-1].get_data();
                   break;

            case 2:cout<<"\nEnter the day of the month:";
                   cin>>d;
                   m1[d-1].report();
                   break;

            case 3: cout<<"Day            High Temp.           Low Temp.           Rainfall             Snowfall";
                    for(i=0;i<30;i++)
                   {
                    m1[i].report();
                   }
                   m1[1].average();
                   break;

            case 4:cout<<"\nThank You\n";
                   return 0;

            default:cout<<"\nWrong Choice.Enter Again\n";
                    break;

        }

    }
    return 0;

}

