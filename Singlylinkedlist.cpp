#include<iostream>
#include<map>
using namespace std;

class Node{
      public:
      int data;
      Node* next ;
       Node(int data)
      {
        this->data=data;
        this->next=NULL;
      }
      ~Node()
      {
        int data=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory free"<<data<<endl;
      }
};
void insertathead(Node* &head,int data)//inserting at begining at head 
{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insertattail(Node* &head,int data)//inserting at tail using head only
{
    Node* temp=new Node(data);
    Node* Newnode=head;
    while(Newnode->next!=NULL)
    {
        Newnode=Newnode->next;
    }
    Newnode->next=temp;
}
void insertatTail(Node* &tail,int data)//inserting at using tail
{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertatposition(Node* &head,int p,int d)//inserting at particular position 
{
    Node* temp=new Node(d);
    int cnt=1;
    if(p==1)
    {
        temp->next=head;
        head=temp;
        return;
    }
    Node* newnode=head;
    while(cnt<p-1 && newnode->next!=NULL)
    {
        newnode=newnode->next;
        cnt++;
    }
    if(cnt==(p-1))
    {
        temp->next=newnode->next;
        newnode->next=temp;
    }
    else{
        cout<<"Enter correct  position to enter "<<endl;
    }
}
void deletatposition(Node* &head,int p)//deleting at particular position
{
    
    int cnt=1;
    if(p==1)
    {
        Node* temp=head;
       head=head->next;
       free(temp);
       return;
    }
    Node* newnode=head;
    while(cnt<p-1 && newnode->next!=NULL)
    {
        newnode=newnode->next;
        cnt++;
    }
    if(cnt==p && newnode->next==NULL)
    {
        Node* temp=newnode;
        newnode=NULL;
        free(temp);
    }
    else if(cnt==p-1 && newnode->next!=NULL)
    {
        Node* temp=newnode->next;
        newnode->next=newnode->next->next;
         free(temp);
    }
    else{
        cout<<"Enter correct  position to delete "<<endl;
    }
}
void deletevalue(Node* &head,int value){
    while(head->data==value)
    {
        Node* temp=head;
        head=head->next;
        free(temp);
    }
     Node* temp=head;
      while(temp->next!=NULL)
      {
        if(temp->next->data==value)
        {
            Node*r=temp->next;
           temp->next=temp->next->next;
           free(r);
        }
        else{
           temp=temp->next;}
      }

}
void print(Node* &head)// printing linked list
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<""<<endl;
}
bool Detectloop(Node*head)
{
    if(head==NULL)
    {
        return false;
    }
    map<Node*,bool>visited;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]==true)
        {
            return true;
        }
        else{
            visited[temp]=true;
        }
        temp=temp->next;
    }
    return false;
}
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
int main(){

    Node* Node1=new Node(5);
  //  cout<<Node1->data<<endl;
    //cout<<Node1->next<<endl;
    Node* head = Node1;
    Node* tail=Node1;
    print(head);
    insertatTail(tail,12);
    print(head);
    insertatTail(tail,12);
    print(head);
    insertatTail(tail,197);
    insertatTail(tail,13);
    insertatTail(tail,12);
    insertatTail(tail,12);
    print(head);
    insertatposition(head,5,131);
    print(head);
   //deletatposition(head,1);
   deletevalue(head,12);
  /* if(Detectloop(head))
   {
    cout<<"loop present"<<endl;
   }
   else{
    cout<<"Loop does not exsist"<<endl;
   }*/
   head->next->next->next->next=head->next;
   Node* ans=flyod(head);
   if(ans==NULL)
   {
    cout<<"Loop does not exsist"<<endl;
   }
   else{
    cout<<ans->data<<endl;
   }
   // print(head);

    return 0;
}