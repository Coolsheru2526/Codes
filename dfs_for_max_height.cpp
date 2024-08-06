int dfs(vector<int>adj[],int s,int p)
{
    int max1=0;
    for(int u:adj[s])
    {
            if(u!=p)
            {
                int length=dfs(adj,u,s);
                if(length>max1)
                {
                    max1=length;
                }
            }
    }
    return max1+1;
}

//travel through all nodes using loop