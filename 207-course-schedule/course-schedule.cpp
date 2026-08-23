class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(int i  = 0; i < prerequisites.size(); ++i){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int> indegree(V , 0);
        for(int i = 0; i < V; ++i){
            for( int j = 0; j < adj[i].size(); ++j){
                int it = adj[i][j];
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < V; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> Topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            Topo.push_back(node);
            for(int i = 0 ; i < adj[node].size(); ++i){
                auto it = adj[node][i];
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(Topo.size() == V){
            return true;
        }
        return false;
    }
};