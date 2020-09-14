#include<stdio.h>
#include<stdlib.h>

typedef struct pnode
{
    int Exp;
    int Coef;
    struct pnode *next;
}node;

node *get()
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

void show(node *head)
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
node *add(node *First,node *Second);
{
     node *Third;
     
      



}
int main()
{
    node *First, *Second, *ans;

    printf("\n\n____________Polynomial Representation using CLL__________\n\n");

    printf("\nEnter details of first polynomial:\n");
    First=get();

    printf("\nEnter details of second polynomial:\n");
    Second=get();

    printf("\nFirst Polynomial:");
    show(First);
    printf("\nSecond Polynomial:");
    show(Second);

    ans=mul(First, Second);
    printf("\nMultiplication of polynomials is:");
    show(ans);

    ans=add(First, Second);
    printf("\nAddition of polynomials is:");
    show(ans);

    return 0;
}
