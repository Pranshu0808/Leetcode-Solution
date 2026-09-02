class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
        int ct = 0; 
        vector<int> v;
        for(int i =  0; i < n; ++i){
            if(adj[i].size() == 0){
                v.push_back(i);
            }
        }
        return v;
    }
};