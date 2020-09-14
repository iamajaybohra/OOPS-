#include <stdio.h>
#include <stdlib.h>

struct STUD
{
    int roll;
    char nm[20];
    float marks;
};

void get_data(struct STUD* V)
{
    printf("\nEnter roll number:");
    scanf("%d",&V->roll);
    printf("Enter Name:");
    scanf("%s",&V->nm);
    printf("Enter Total Marks:");
    scanf("%f",&V->marks);
}

void print_data(struct STUD V)
{
    printf("\n\nRoll number: %d",V.roll);
    printf("\nName: %s",V.nm);
    printf("\nMarks: %f",V.marks);
}

void search_data(struct STUD V[],int c,int d)
{
    int r,i,flag=0;
    printf("Enter the roll number to be executed:");
    scanf("%d",&r);
    for(i=0;i<c;i++)
    {
        if(r==V[i].roll)
        {
            flag=1;
            if(d==0)
                get_data(&V[i]);
            else if(d==1)
                print_data(V[i]);
            else if(d==2)
                del_data(V,i,c);
            break;
        }
    }
    if(flag==0)
        printf("Record Not found!!!");

}
void del_data(struct STUD V[],int k,int c)
{
    int i;
    for(i=k;i<c-1;i++)
    {
        V[i]=V[i+1];
    }
}
int main()
{
    struct STUD S[30];
    int i,choice,c=0,m=0;
    while(1)
    {printf("\n\t\t::STUDENT RECORD::\n\nSelect any one of the following\n1.Enter Student Data\n2.Display Data\n3.Search Specific Record\n4.Edit Record\n5.Delete Record\n6.Exit\n\nEnter your option:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:printf("Enter number of records:");
               scanf("%d",&m);
               printf("\nEnter Data:\n");
               for(i=c;i<m+c;i++)
                get_data(&S[i]);
               c=c+m;
               break;
        case 2:printf("The record are as follows:\n");
               for(i=0;i<c;i++)
                print_data(S[i]);
               break;

        case 3:search_data(S,c,1);
               break;

        case 4:search_data(S,c,0);
               break;

        case 5:search_data(S,c,2);
               c--;
               break;

        case 6:printf("\nThank You\n\n");
               return 0;

        default:printf("Wrong Choice!!!!!");

    }

    }

 return 0;
}
