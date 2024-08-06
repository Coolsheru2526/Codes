#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
void levelordertraversal(Node* root)
{
    cout<<"aya hoon"<<endl;
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
    Node* temp=q.front();
    q.pop();
    if(temp==NULL)
    {
        cout<<endl;
        if(!q.empty()){
            q.push(NULL);
        }
    }
    else{
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    
   }
}
void Inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
     cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<endl;
}

Node* NodeInsertBst(Node* root,int data)
{
    if(root==NULL)
      {
        root=new Node(data);
        return root;
      }
      if(root->data>=data)
      {
        root->left= NodeInsertBst(root->left,data);
      }else{
         root->right= NodeInsertBst(root->right,data);
      }
      return root;
} 
int minvalue(Node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
Node* deletefrombst(Node*root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        //0 child
        if(root->right==NULL && root->left==NULL)
        {
            delete root;
            return NULL;
        }

        //1 child
        //left child
         if(root->right==NULL && root->left!=NULL)
         {
            Node* temp=root->left;
            delete root;
            return temp;
         }
        //right child
         if(root->right!=NULL && root->left==NULL)
         {
            Node* temp=root->right;
            delete root;
            return temp;
         }

        //2 child
        if(root->right!=NULL && root->left!=NULL)
        {
            int mini=minvalue(root->right);
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
            return root;
        }
    }
    if(root->data>val)
    {
        root->left=deletefrombst(root->left,val);
        return root;
    }else{
         root->right=deletefrombst(root->right,val);
        return root;
    }
}
void TakeInput(Node* &root)
{
    int data;
    cin>>data;
      while(data!=-1)
      {
       root= NodeInsertBst(root,data);
       cin>>data;
      }
}

//balanced bst Fast Approch
pair<bool,int> isbalancefast(Node* root)
{
    if(root==NULL)
    {
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
     pair<bool,int>left= isbalancefast(root->left);
      pair<bool,int>right= isbalancefast(root->right);
      bool leftans=left.first;
      bool rightans=right.first;
      bool diff=abs(left.second-right.second)<=1;
      pair<bool,int> ans;
      ans.second=max(left.second,right.second)+1;
      if(leftans && rightans && diff)
      {
        ans.first=true;
      }else{
        ans.first=false;
      }
      return ans;
}



int main(){
    Node* root=NULL;
    cout<<"Enter Data to Create BST"<<endl;
    TakeInput(root);//insertion in BST is O(logn)
    cout<<"printing level order traversal"<<endl;
    levelordertraversal(root);
    cout<<"Inorder"<<endl;
    Inorder(root);
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<"postorder"<<endl;
    postorder(root);
    return 0;
}