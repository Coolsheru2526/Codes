#include<iostream>
using namespace std;

class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isterminal;
   TrieNode(char c)
   {
    data=c;
    for(int i=0;i<26;i++)
    {
        children[i]=NULL;
    }
    isterminal=false;
   }

};
class Trie{
  public:
 
  TrieNode* root;
   Trie(){
    root=new TrieNode('\0');
  }
  void insertutil(TrieNode* root, string word)
  {
    if(word.length()==0)
    {
        root->isterminal=true;
        return;
    }
    int index=word[0]-'a';//Asuming all words in caps
  
     TrieNode* child;
     //present hai
     if(root->children[index]!=NULL)
     {
     child=root->children[index];
     }else{     //absent hai
           child=new TrieNode(word[0]);
           root->children[index]=child;
     }
     //recursion
    insertutil(child,word.substr(1));
  }
  void insert(string word)
  {
      insertutil(root,word);
  }

  bool searchutil(TrieNode* root,string word)
  {
      if(word.length()==0)
      {
       return root->isterminal;
      }
      int index=word[0]-'a';
      TrieNode* child;
      if(root->children[index]!=NULL)
      {
        child=root->children[index];
      }else{
        return false;
      }
      return(searchutil(child,word.substr(1)));
  }

  bool search(string word)
  {
     return(searchutil(root,word));
  }

  void removeutil(TrieNode* root,string word)
  {
      if(word.length()==0)
      {
        root->isterminal=false;
      }
      int index=word[0]-'a';
      TrieNode* child;
      if(root->children[index]!=NULL)
      {
        child=root->children[index];
      }else{
        return;
      }
      return(removeutil(child,word.substr(1)));
  }

  void remove(string word)
  {
     (removeutil(root,word));
  }

    bool preutil(TrieNode* root,string word)
    {
        if(word.length()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }else{
            return false;
        }
        return(preutil(child,word.substr(1)));
    } 
   bool pre(string word)
   {
      return(preutil(root,word));
   }
};
int main(){
  Trie *t= new Trie();
  t->insert("help");
   //t->insert("AT");
    //t->insert("ABCD");
     //t->insert("ABCDE");
   cout<<"Present or NOT"<<" "<<t->search("hel")<<endl;
    cout<<"Present or NOT"<<" "<<t->pre("hel")<<endl;

  /* cout<<"Present or NOT"<<" "<<t->search("AT")<<endl;
   cout<<"Present or NOT"<<" "<<t->search("ABCD")<<endl;
    cout<<"Present or NOT"<<" "<<t->search("ABCDE")<<endl;
    */
   t->remove("ABC");
    cout<<"Present or NOT"<<" "<<t->search("ABC")<<endl;
    
    
    return 0;
}