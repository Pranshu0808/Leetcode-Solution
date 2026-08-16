class Solution {
public:
    void dfs(int& ct , int& ct1 , int start , vector<int> adj[] , vector<int>& vis , int source ,int destination , bool& b){
        vis[start] = 1;
        if(start == source){
                ct = 1;
        }
        if(start == destination){
                ct1 = 1;
        }
        if(ct == 1 && ct1 == 1){
                b = true;
        }
        for(int i =  0; i <adj[start].size(); ++i){
            int it = adj[start][i];
            if(!vis[it]){
                
                dfs(ct , ct1 , it , adj , vis  ,source , destination , b);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i = 0 ; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int> vis(n , 0);
        bool b = false;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                int ct = 0 , ct1 = 0;
                dfs(ct , ct1  , i , adj , vis , source , destination , b);
                if(b == true){
                    return b;
                }
            }
        }
        return b;

    }
};