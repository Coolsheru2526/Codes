#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

void dfs(int node,int parent,int &timer, vector<int>&dis, vector<int>&low,unordered_map<int,bool>&visited, vector<int>&ap,unordered_map<int,list<int,int>>&adj)
{
    visited[node]=true;
    low[node]=timer;
    dis[node]=timer;
    timer++;
    int child=0;
    for(auto ngh:adj[node])
    {
        if(node==parent)
        {
            continue;
        }
        if(!visited[ngh])
        {
              dfs(ngh,node,timer,dis,low,visited,ap,adj);
              if(low[ngh]>=dis[node] && parent!=1)
              {
                ap[node]=1;
              }
              child++;
        }else{
           low[node]=min(low[node],dis[ngh]);
        }
    }
    if(parent==-1 && child>1)
    {
        ap[node]=1;
    }
}
int main(){
    int n=5;
    int e=5;
   vector<pair<int,int>>edges;
   edges.push_back(make_pair(0,3));
   edges.push_back(make_pair(3,4));
   edges.push_back(make_pair(0,4));
   edges.push_back(make_pair(0,1));
   edges.push_back(make_pair(1,2));
   unordered_map<int,list<int,int>>adj;
     for(int i=0;i<e;i++)
     {
        int u=edges[i].first();
        int v=edges[i].second();
        adj[u].push_back(v);
        adj[v].push_back(u);
     }

     int timer=0;
     vector<int>dis(n);
     vector<int>low(n);
     unordered_map<int,bool>visited;
     vector<int>ap(n,0);
     for(int i=0;i<n;i++)
     {
        if(!visited[i])
        {
            dfs(i,-1,timer,dis,low,visited,ap,adj);
        }
     }
     cout<<"articulation points are as follow"<<endl;
     for(int i=0;i<n;i++)
     {
        if(ap[i]!=0)
        {
            cout<<ap[i]<<" , ";
        }
     }cout<<endl;

    return 0;
}