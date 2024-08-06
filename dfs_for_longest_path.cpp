 int dfs(int node, int parent, vector<vector<int>>& adj, string& s, int& result) {
        int max1 = 0, max2 = 0;
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            int length = dfs(neighbor, node, adj, s, result);
            if (s[neighbor] != s[node]) {
                if (length > max1) {
                    max2 = max1;
                    max1 = length;
                } else if (length > max2) {
                    max2 = length;
                }
            }
        }
        
        result = max(result, max1 + max2 + 1);
        return max1 + 1;
    }