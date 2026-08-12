class Solution {
public:

    void dfs(int node , vector<int> adls[] , vector<int>& vis){
        vis[node] = 1;
        for(int i = 0 ; i < adls[node].size(); ++i){
            int it = adls[node][i];
            if(!vis[it]){
                dfs(it  , adls , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int V = isConnected.size();
        vector<int> adls[V+1];
        for(int i = 0; i < V; ++i){
            for(int j = 0 ; j < V; ++j){
                if(isConnected[i][j] == 1 && i != j){
                    adls[i+1].push_back(j+1);
                    adls[j+1].push_back(i+1);
                }
            }
        }
        int ct = 0; 
        vector<int> vis(V+1 , 0);
        for(int i = 1; i <= V; ++i){
            if(!vis[i]){
                ct++;
                dfs(i , adls , vis);
            }
        }
        return ct;
    }
};