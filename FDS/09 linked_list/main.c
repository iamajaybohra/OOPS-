#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int id;
    char nm[20];
    struct node *next;
}n;

n *create(int a)
{
    n *head,*p;
    head=(n*)malloc(sizeof(n));
    printf("\nEnter Book ID:");
    scanf("%d",&head->id);
    printf("\nEnter Book Name:");
    scanf("%s",&head->nm);
    head->next=NULL;
    p=head;
    for(int i=1;i<a;i++)
    {
        p->next=(n*)malloc(sizeof(n));
        p=p->next;
        printf("\nEnter Book ID:");
        scanf("%d",&p->id);
        printf("\nEnter Book name:");
        scanf("%s",&p->nm);
        p->next=NULL;
    }
    return head;
}

void print(n *head)
{
    n *p=head;
    while(p->next!=NULL)
    {
        printf(" => ");
        printf("%d",p->id);
        printf("%s",p->nm);
        p=p->next;
    }
    printf("%d",p->id);
    printf("%s",p->nm);
}

n *ins(n *head)
{
    n *p;
    int ch,b;
    if(head==NULL)
    {
        printf("\nNO DATABASE CREATED FOR INSERTION.FIRST CREATE A DATABASE!!!");
    }
    else
    {
    p=(n*)malloc(sizeof(n));
    printf("\nEnter Book id:");
    scanf("%d",&p->id);
    printf("\nEnter Book Name:");
    scanf("%s",&p->nm);
    p->next=NULL;
    printf("\nWhere to insert the new node:\n1.At the beginning\n2.In between\n3.At the End\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        p->next=head;
        head=p;
        return head;
    }
    if(ch==2)
    {
        n *r=head;
        printf("\nEnter the book id after which you want to insert:");
        scanf("%d",&b);

        while(r->id!=b)
            r=r->next;

        p->next=r->next;
        r->next=p;
        return head;

    }

    if(ch==3)
    {
        n *q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
        return head;
    }
    else
    {
        printf("\nWrong Input!!!\n");
        return head;
    }
    }
}

n *del(n *head)
{
    int a,b;
    n *p;
    if(head==NULL)
    {
        printf("\nNO RECORD TO DELETE!");
    }
    else
    {
    printf("\nWhich node you want to delete:\n1.Beginning Node\n2.In between Node\n3.Last Node\n");
    scanf("%d",&a);
    if(a==1)
    {
        p=head;
        head=head->next;
        free(p);
        return head;
    }
    if(a==2)
    {
        p=head;
        n *q=head->next;
        printf("\nEnter the book id which you want to delete:");
        scanf("%d",&b);

        while(q->id!=b)
        {
            q=q->next;
            p=p->next;
        }
        p->next=q->next;
        free(q);
        return head;
    }
    if(a==3)
    {
        p=head;
        n *q=head->next;
        while(q->next!=NULL)
        {
            q=q->next;
            p=p->next;
        }
        p->next=NULL;
        free(q);
        return head;
    }
    else
    {
        printf("Wrong Choice!!!.");
        return head;
    }
    }
}

n *concat(n *h1,n *h2)
{
    n *p=h1;

    if(h1==NULL && h2==NULL)
        return NULL;

    else if(h1==NULL)
        return h2;

    else if(h2==NULL)
        return h1;

    else
    {
        while(p->next!=NULL)
            p=p->next;
        p->next=h2;
        return h1;
    }

}

void rev(n *head)
{
    n *p=head;
    int arr[20];
    char a[20][20];
    int top=0;
    while(p->next!=NULL)
    {
        arr[top]=p->id;
        a[top][0]=p->nm;
        p=p->next;
        top++;
    }
    arr[top]=p->id;
    a[top][0]=p->nm;
    for(int i=top;i>=0;i--)
    {
        printf("%d => ",arr[i]);
        printf("%s => ",a[i][0]);
    }
}

n *invert(n *head)
{
    n *p=head;
    n *q=head->next;
    n *r=head->next->next;

    p->next=NULL;
    while(q->next!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    head=q;
    return head;
}

int main()
{
    int a,b,ch;
    n *h=NULL,*h1=NULL,*h2=NULL;
    printf("\n\n\t\t----- BOOK DATABASE BASED ON SINGLY LINKED LIST-----\n");
    while(1)
    {
    printf("\n\nSelect any one of the following:\n\n1.Create new Database\n2.Print the database\n3.Insert a new record\n4.Delete a record\n5.Concatenate two database\n6.Reverse the database\n7.Invert the database permanently\n8.EXIT\n\nEnter your option:");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("\nEnter number of records:");
               scanf("%d",&a);
               h=create(a);
               printf("\nDatabase created successfully!!");
               break;

        case 2:printf("\nThe linked list is:");
               print(h);
               break;

        case 3:h=ins(h);
               printf("Inserted successfully!!");
               break;

        case 4:h=del(h);
               printf("Record deleted successfully!!");
               break;

        case 5:printf("Enter number of record:");
               scanf("%d",&b);
               h2=create(b);
               h=concat(h,h2);
               printf("Database concatenated successfully!!");
               break;

        case 6:printf("The database list is:");
               rev(h);
               break;

        case 7:h=invert(h);
               printf("\nInverted Successfully\n");
               break;

        case 8:printf("\nThank you!!!");
               return 0;
    }
    }

return 0;
}
