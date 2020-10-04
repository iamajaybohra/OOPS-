#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next=NULL;
};
node* insert_last(node *head,int d){
    if(head==NULL){
        head=new node;
        head->data=d;
        return head;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node;
        temp=temp->next;
        temp->next=NULL;
        temp->data=d;
        return head;
    }
}
node* insert_front(node *head,int d){
    if(head==NULL){
        head=new node;
        head->data=d;
        return head;
    }
    else{
        node *temp=new node;
        temp->data=d;
        temp->next=head;
        return temp;
    }
}
void display(node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    return display(head->next);
}
node* reverse_ll(node* head){
    node *cur=head;
    node *pre=NULL;
    node *nx=NULL;
    while(cur!=NULL){
        nx=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nx;
    }
    head=pre;
    return head;
}
int main(){
    node *head=NULL;
    int n;
    cout<<"how many no you want to insert in ll:: ";
    cin>>n;
    int b;
    cout<<"enter the no:: ";
    for(int i=0;i<n;i++){
        cin>>b;
        head=insert_last(head,b);
    }
    cout<<"\n";
    display(head);
    cout<<"\n";
    head=reverse_ll(head);
    cout<<"after reverse:: ";
    display(head);
}
