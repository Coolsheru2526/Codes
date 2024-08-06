#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
    }
    ~Node(){
        if(this->next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};
void insert(Node* &head,int data)
{
   Node* temp=new Node(data)   ;
   temp->next=head;
   head=temp;
Node* flyod(Node*head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
          return slow;
        }
    }
    return NULL;
}

Node* firstnodeofloop(Node*head)//this returns first node of loops Very important ***8
{
    if(head==NULL)
    {
        return false;
    }
    Node* intersection=flyod(Node* head);
    Node* slow=head;
    while(slow!=intersection)
    {
        intersection=intersection->next;
        slow=slow->next;
    }
    return slow;
}
void removeloop(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    Node* start=firstnodeofloop(head);
    Node* temp=start->next;
    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}