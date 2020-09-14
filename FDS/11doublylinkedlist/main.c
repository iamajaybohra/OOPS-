#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int roll;
  char name[20];
  struct node* prev;
  struct node* next;
}node;

node* create(node *head,int a)
{
    int i;
    head->prev=NULL;
    node *p=head;
    node *q=head;
    for(i=1;i<=a;i++)
    {
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        printf("\nEnter roll number:");
        scanf("%d",&p->roll);
        printf("\nEnter name:");
        scanf("%s",&p->name);
        p->prev=q;
        q=q->next;
    }
    p->next=NULL;
    return head;
}

node* insert(node *head)
{
    int opt,r;
    if(head==NULL)
    {
        printf("\nNO database found for insertion.First create a database..");
    }
    else
    {node *p=head;
    node *q;
    q=(node*)malloc(sizeof(node));
    printf("\nEnter roll number:");
    scanf("%d",&q->roll);
    printf("\nEnter name:");
    scanf("%s",&q->name);

    printf("Where you want to insert the new record:\n1.At the beginning\n2.In between\n3.At the end\nEnter your option");
    scanf("%d",&opt);
    if(opt==1)
    {
        q->prev=NULL;
        q->next=head;
        head->prev=q;
        head=q;
        return head;
    }
    if(opt==2)
    {
        printf("\nEnter the roll no. after which you want to insert:");
        scanf("%d",&r);
        while(p->roll!=r)
        {
            p=p->next;
        }
        q->prev=p;
        q->next=p->next;
        p->next->prev=q;
        p->next=q;
        return head;
    }
    if(opt==3)
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
        q->prev=p;
        q->next=NULL;
        return head;
    }
    }
}

node* del(node *head)
{
    int r;
    node *p=head;
    if(head==NULL)
    {
        printf("\nNo record found to delete!!");
    }
    else
    {printf("\nEnter the roll number you want to delete:");
    scanf("%d",&r);
    if(head->roll==r)
    {
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    else
    {
        while(p->roll!=r)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return head;
    }
    }
}

void modify(node *head)
{
    node *p=head;
    int r;
    if(head==NULL)
        printf("No record found to update!!");
    else
    {printf("\nEnter the roll no. to modify:");
    scanf("%d",&r);
    while(p->roll!=r)
    {
        p=p->next;
    }
    printf("\nEnter the new roll number:");
    scanf("%d",&p->roll);
    printf("\nEnter the new name:");
    scanf("%s",&p->name);
    }
}

void disfor(node *head)
{
    if(head==NULL)
        printf("NO RECORD FOUND!!!");
    else
    {while(head->next!=NULL)
    {
        printf("\nROLL NUMBER:%d",head->roll);
        printf("\tName:%s",head->name);
        head=head->next;
    }
    printf("\nROLL NUMBER:%d",head->roll);
    printf("\tName:%s",head->name);
    }
}

void disback(node *head)
{
    if(head==NULL)
        printf("No record found!!");
    else
    {node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p->prev!=NULL)
    {
        printf("\nROLL NUMBER:%d",p->roll);
        printf("\tName:%s",p->name);
        p=p->prev;
    }
    printf("\nROLL NUMBER:%d",p->roll);
    printf("\tName:%s",p->name);
    }
}

int main()
{
    int ch,a,b,c;
    node *head;
    head=NULL;

    while(1)
    {printf("\n\n\t\t______Database Record_______\n\nSelect any one of the following:\n1.Create a new database\n2.Insert a new record\n3.Delete a record\n4.Modify a record\n5.Display forward\n6.Display backward\n7.EXIT\n\nEnter your option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter number of records:");
               scanf("%d",&a);
               head=(node*)malloc(sizeof(node));
               printf("\nEnter roll number:");
               scanf("%d",&head->roll);
               printf("\nEnter name:");
               scanf("%s",&head->name);
               head=create(head,a-1);
               break;

        case 2:head=insert(head);
               printf("Record Inserted Successfully!");
               break;

        case 3:head=del(head);
               printf("Record deleted Successfully!");
               break;

        case 4:modify(head);
               printf("Record modified Successfully!");
               break;

        case 5:printf("\nForward display:\n");
               disfor(head);
               break;

        case 6:printf("\n Backward display:\n");
               disback(head);
               break;

        case 7:printf("\nThank You\n\n");
               return 0;

        default:printf("Wrong Input!!!!");
                break;
    }
    }
    return 0;
}
