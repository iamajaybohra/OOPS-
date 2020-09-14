#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct book *down;
    struct book *next;

}node;

node *create(int value)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->down = NULL;
    temp->next = NULL;
    temp->data = value;
    return temp;
}
node *create_book()
{
    node *head;
    int x;
    printf("\n\nPlease Enter The data or 0 To stop: ");
    scanf("%d",&x);
    if(x!=0)
    {
        head = create(x);
        printf("For Forward of %d",x);
        head->next = create_book();
        printf("For Down of %d",x);
        head->down = create_book();
        return head;
    }
    else
        return NULL;
}
void print(node *head)
{
    if(head==NULL)
        return;
    else
    {
        printf("%d\t",head->data);
        print(head->down);
        print(head->next);
    }
}
int main()
{
    printf("\nGLL IMPLEMENTATION\n");
    node *head = NULL;
    head = create_book();
    print(head);
}

