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

bool hasCycle;
 
// Function to check if a vertex v
// can be added at index pos in
// the Hamiltonian Cycle
bool isSafe(int v, int graph[][6], vector<int> path, int pos)
{
   
    // If the vertex is adjacent to
    // the vertex of the previously
    // added vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;
 
    // If the vertex has already
    // been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    // Both the above conditions are
    // not true, return true
    return true;
}
 
// Recursive function to find all
// hamiltonian cycles
void FindHamCycle(int graph[][6], int pos, vector<int> path, bool visited[], int N)
{
    // If all vertices are included
    // in Hamiltonian Cycle
    if (pos == N) {
 
        // If there is an edge
        // from the last vertex to
        // the source vertex
        if (graph[path[path.size() - 1]][path[0]] != 0) {
 
            // Include source vertex
            // into the path and
            // print the path
            path.push_back(0);
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << endl;
 
            // Remove the source
            // vertex added
            path.pop_back();
 
            // Update the hasCycle
            // as true
            hasCycle = true;
        }
        return;
    }
 
    // Try different vertices
    // as the next vertex
    for (int v = 0; v < N; v++) {
 
        // Check if this vertex can
        // be added to Cycle
        if (isSafe(v, graph, path, pos) && !visited[v]) {
 
            path.push_back(v);
            visited[v] = true;
 
            // Recur to construct
            // rest of the path
            FindHamCycle(graph, pos + 1, path, visited, N);
 
            // Remove current vertex
            // from path and process
            // other vertices
            visited[v] = false;
            path.pop_back();
        }
    }
}
 
// Function to find all possible
// hamiltonian cycles
void hamCycle(int graph[][6], int N)
{
    // Initially value of boolean
    // flag is false
    hasCycle = false;
 
    // Store the resultant path
    vector<int> path;
    path.push_back(0);
 
    // Keeps the track of the
    // visited vertices
    bool visited[N];
 
    for (int i = 0; i < N; i++)
        visited[i] = false;
 
    visited[0] = true;
 
    // Function call to find all
    // hamiltonian cycles
    FindHamCycle(graph, 1, path, visited, N);
 
    if (!hasCycle) {
 
        // If no Hamiltonian Cycle
        // is possible for the
        // given graph
        cout << "No Hamiltonian Cycle" << "possible " << endl;
        return;
    }
}

vector<vector<int>> cycles;
 
// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
 
    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }
 
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
           
        int cur = p;
          v.push_back(cur);
 
        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    // partially visited.
    color[u] = 1;
 
    // simple dfs on graph
    for (int v : graph[u]) {
 
        // if it has not been visited previously
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
 
    // completely visited.
    color[u] = 2;
}
 
 enum Color {WHITE, GRAY, BLACK};
 
// Graph class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices
    list<int>* adj; // adjacency lists
 
    // DFS traversal of the vertices reachable from v
    bool DFSUtil(int v, int color[]);
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    bool isCyclic();
};
 
// Constructor
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// Utility function to add an edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}
 
// Recursive function to find if there is back edge
// in DFS subtree tree rooted with 'u'
bool Graph::DFSUtil(int u, int color[])
{
    // GRAY :  This vertex is being processed (DFS
    //         for this vertex has started, but not
    //         ended (or this vertex is in function
    //         call stack)
    color[u] = GRAY;
 
    // Iterate through all adjacent vertices
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // An adjacent of u
 
        // If there is
        if (color[v] == GRAY)
          return true;
 
        // If v is not processed and there is a back
        // edge in subtree rooted with v
        if (color[v] == WHITE && DFSUtil(v, color))
          return true;
    }
 
    // Mark this vertex as processed
    color[u] = BLACK;
 
    return false;
}
 
// Returns true if there is a cycle in graph
bool Graph::isCyclic()
{
    // Initialize color of all vertices as WHITE
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;
 
    // Do a DFS traversal beginning with all
    // vertices
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
           if (DFSUtil(i, color) == true)
              return true;
 
    return false;
}

