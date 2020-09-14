#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
    int Exp;
    int Coef;
    struct node *next;
}node;

node *create()
{
    node *head,*p;
    int Exp,Coef,n,i;

    printf("\nEnter number of terms:");
    scanf("%d",&n);
    printf("\nEnter the polynomial in descending order of exponent:\n");

    printf("Enter Coefficient Value:");
    scanf("%d",&Coef);
    printf("Enter Power Value:");
    scanf("%d",&Exp);
    head=(node*)malloc(sizeof(node));
    head->Coef=Coef;
    head->Exp=Exp;
    head->next=head;

    p=head;
    for(i=1;i<n;i++)
    {
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        printf("Enter Coefficient Value:");
        scanf("%d",&Coef);
        printf("Enter Power Value:");
        scanf("%d",&Exp);
        p->Coef=Coef;
        p->Exp=Exp;
        p->next=head;
    }

    return head;
}

void display(node *head)
{
    node *p ;
    p=head;
    if (p== NULL )
    {
        printf("The polynomial is empty\n");
        return;
    }
    do
    {
        if ( p->Exp != 0 )
            printf("%.2dx^%d", p->Coef, p->Exp );

        else
            printf("%.2d", p->Coef);

        p = p -> next;
        if ( p != head )
            if ( p->Coef > 0)
                printf(" + ");

    }while(p != head );

    printf("\n");

}

int Eval(node *start1)
{
            node *P1;
            int x;
            int sum=0.0,Coef,Exp;
            printf("\n Enter the value of variable x : ");
            scanf("%d",&x);
            P1 = start1;

            do
            {
                        Coef=P1->Coef;
                        Exp=P1->Exp;
                        sum=sum+Coef*pow(x,Exp);
                        P1 = P1->next;
            }while (P1!=start1);

return(sum);
}

node *mul(node *start1,node *start2)
{
    node *p1, *p2, *p3, *dummy, *temp,*start3,*New ;
    int Exp, flag;
    int Coef;
    p1 = start1;
    p3 = ( node*)malloc(sizeof(node) );
    p3->next = p3;
    start3=p3;
    temp=p3;

    do
    {
        p2 = start2;
        do
        {
            Coef=p1->Coef * p2->Coef;
            Exp=p1->Exp + p2->Exp;
            flag=0;
            if ( flag==1)
                temp->Coef = temp ->Coef + Coef;
            else
            {
                New = (node*)malloc(sizeof(node));
                New->Exp = Exp;
                New->Coef = Coef;
                New->next = New;
                p3 -> next = New;
                p3 = New;
            }

            p2 = p2 -> next;
        }while ( p2 != start2);

        p1 = p1 -> next;
    }while ( p1 != start1 );

    start3=temp->next;
    p3 ->next = start3;
    p3 = start3;
    free ( temp);

    return(p3);
}

node *add(node *start1,node *start2)
{

    node *P1,*P2,*P3,*start3;
    int Coef;
    P1 = start1;
    P2 = start2;
    int flag=0;
    start3 = (node*)malloc(sizeof(node));
    P3=start3;
    P3->next=start3;



        while(P1->next!=(start1) && P2->next!=(start2))
        {

            if(flag==1)
            {
            P3->next=(node*)malloc(sizeof(node));
            P3=P3->next;
            P3->next=start3;
            }
            if(1)
            {
            if(P1->Exp==P2->Exp)
                {
                    P3->Exp=P1->Exp;
                    P3->Coef=P1->Coef + P2->Coef;
                    P1 = P1->next;
                    P2 = P2->next;
                    flag=1;
                }
            else if(P1->Exp<P2->Exp)
                {
                    P3->Coef=P2->Coef;
                    P3->Exp=P2->Exp;
                    P2 = P2->next;
                    flag=1;
                }
            else if(P1->Exp>P2->Exp)
                {
                    P3->Coef=P1->Coef;
                    P3->Exp=P1->Exp;
                    P1 = P1 -> next;
                    flag=1;
                }
            }
        }


        while(P1!=(start1) && P2!=(start2) )
        {

            if(flag==1)
            {
                P3->next=(node*)malloc(sizeof(node));
                P3=P3->next;
                P3->next=start3;
            }
            if(1)
            {if(P1->Exp==P2->Exp)
            {
                P3->Exp=P1->Exp;
                P3->Coef=P1->Coef + P2->Coef;
                P1 = P1->next;
                P2 = P2->next;
                flag=1;
            }
            else if(P1->Exp < P2->Exp)
            {
                Coef = P2 -> Coef;
                P3->Coef= Coef;
                P3->Exp=P2->Exp;
                P2 = P2 -> next;
                flag=1;
            }
            else if(P1->Exp>P2->Exp)
            {
                Coef = P1 -> Coef;
                P3->Coef=Coef;
                P3->Exp=P1->Exp;
                P1 = P1 -> next;
                flag=1;
            }

        }
        }


        while (P1!=(start1))
        {
            P3->next=(node*)malloc(sizeof(node));
            P3=P3->next;
            P3->next=start3;
            P3->Coef=P1->Coef;
            P3->Exp=P1->Exp;
            P1=P1->next;

        }

        while (P2!=(start2))
        {

            P3->next=(node*)malloc(sizeof(node));
            P3=P3->next;
            P3->next=start3;
            P3->Coef=P2->Coef;
            P3->Exp=P2->Exp;
            P2=P2->next;
        }


return(start3);
}

int main()
{
  node *p1, *p2, *p3;
  int choice,result=0;

  printf("\n\n Program for Polynomial Addition, Multiplication and Evaluation using Circular Linked List\n\n");
  printf("\n\nEnter the first polynomial\n\n");
  p1 = create();
  printf("\n\nEnter the Second polynomial\n\n");
  p2 = create();

  printf("\nThe first polynomial is as follows\n");
  display(p1);
  printf("\nThe second polynomial is as follows\n");
  display(p2);

  do
  {
    printf("\n\t\t Main Menu");
    printf("\n 1.Addition \n 2.Multiplication \n 3.Evaluation\n 4.Exit ");
    printf("\n Enter Your Choice ");
    scanf("%d",&choice);

    switch(choice)
    {
     case 1:p3=add(p1,p2);
            printf("\n The addition of the polynomials is as follows\n");
            display(p3);
            break;

     case 2:p3 = mul(p1,p2);
            printf("\n The multiplication of the polynomials is as follows\n");
            display(p3);
            break;

     case 3:result = Eval(p1);
            printf("\n The Evaluation of 1st polynomial is :  %d",result);
            result=Eval(p2);
            printf("\n The Evaluation of 2nd polynomial is : %d",result);
            break;

     case 4:printf("\nThank You\n");
            break;
    }
}while(choice!=4);

return 0;
}
