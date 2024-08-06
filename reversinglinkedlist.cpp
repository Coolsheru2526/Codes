#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(this->next!=NULL)
        {
            delete next;
            next==NULL;
        }
    }
};
 
void insert(Node* &head,int data)
{
   Node* temp= new Node(data);
   temp->next=head;
   head=temp;
}
Node* reverse(Node* &head)
{
    
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* chead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return chead;
}
void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
   cout<<endl;
}
int main (){
    Node* head= new Node(10);
   /*= char c='a';
    if(c>70)
    {
        c=c-32;
        cout<<c<<endl;
    }*/
    insert(head,12);
      insert(head,13);
        insert(head,14);
          insert(head,15);
   print(head);
   head=reverse(head);
   print(head);
    return 0;
}