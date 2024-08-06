#include<iostream>
#include <unordered_map>
#include<list>
using namespace std;
template <typename T>

class Graph{
  public:
  unordered_map<T ,list<T>>adj;

  void addedge(T u,T v,bool direct){
     // direct=0  ->undirected graph
     // direct=1 ->directed graph
     adj[u].push_back(v);
     if(direct==0)
     {
        adj[v].push_back(u);
     }
  }
  void printadjlist()
   {
       for(auto i: adj)
       {
        cout<<i.first<<"-->";
        for(auto j: i.second)
        {
            cout<<j<<",";
        }
        cout<<endl;
       }
    } 
};


int main(){
      int n;
      cout<<"enter the Number of nodes"<<endl;
      cin>>n;
      int m;
      cout<<"enter the Number of edges"<<endl;
      cin>>m;

      Graph<int> g;
      for(int i=0;i<m;i++)
      {
        int u,v;
        cin>>u>>v;
        // creating an undirected
        g.addedge(u,v,0);
      }
      g.printadjlist();

    return 0;
}

//CHECK WHETHER  CYCLE IS THERE IN UNDIRECTED GRAPH OR NOT USING BFS

bool iscyclicbfs(int i,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited)
{
    unordered_map<int,int>parent;
    parent[i]=-1;
    visited[i]=true;
    queue<int>q;
    q.push(i);
    while(!q.empty())
    {
        int element=q.front();
        q.pop();
        for(auto j:adj[element])
        {
            if(visited[j]==true && j!=parent[element]){
                     return true;
            }
            else if(!visited[j])
            {
                visited[j]=true;
                q.push(j);
                parent[j]=element;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>>adj;//to store graph in adjancey list
    unordered_map<int,bool>visited;

    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
          bool ans=iscyclicbfs(i,adj,visited);
          if(ans)
          {
              return "Yes";
          }

        }
    }
    return "No";  
}

//DFS TRAVEL


void dfs(int i, unordered_map<int,bool>&visited, unordered_map<int, list<int>>&adj, vector<int>&res)
{
    //answer mae daal rhe hai
    res.push_back(i);
    //visit hogya true krrhe hai
    visited[i]=true;
    //har connected node ke liye recuursive call
    for(auto j:adj[i])
    {
        if(!visited[j])
        {
     dfs(j,visited, adj,res);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
  unordered_map<int, list<int>> adj;
   unordered_map<int,bool>visited;
  for(int i=0;i<edges.size();i++)
  {
      int u=edges[i][0];
      int v=edges[i][1];
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  vector<vector<int>>ans;
  for(int i=0;i<V;i++)
  {
   if(!visited[i])
   {
       vector<int>res;
       dfs(i,visited,adj,res);
       ans.push_back(res);
   }
  }
  return ans;
}
