#include<iostream>
#include<vector>

using namespace std;

class Disjoint{
   vector<int> rank,parent,size;
   public:
   Disjoint(int n)
   {
    rank.resize(n+1,0);
    parent.resize(n+1); 
     size.resize(n+1,1); 
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
   }
   int findUpar(int node){
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=findUpar(parent[node]);
   }
   void unionbyrank(int u,int v)
   {
    int upu=findUpar(u);
    int upv=findUpar(v);
    if(upu==upv){return ;}
    if(rank[upu]<rank[upv])
    {
        parent[upu]=upv;       
    }
    else if(rank[upv]<rank[upu])
    {
        parent[upv]=upu;
    }
    else{
        parent[upv]=upu;
        rank[upu]++;
    }
   }
   void unionbysize(int u,int v)
   {
    int upu=findUpar(u);
    int upv=findUpar(v);
    if(upu==upv){return ;}
    if(size[upu]<size[upv])
    {
        parent[upu]=upv;
        size[upv]+=size[upu];
    }else{
        parent[upv]=upu;
        size[upu]+=size[upv]; 
    }
   }
};