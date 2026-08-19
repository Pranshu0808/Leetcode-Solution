class Solution {
public:

    bool checkBipartite(int start, vector<vector<int>>& graph, vector<int>& color){ 
        queue<int> q;
        q.push(start);
        color[start] = 0; 
        while(!q.empty()){   
            int node = q.front();
            q.pop();    
            for(int i = 0; i < graph[node].size(); i++){   
                int adjNode = graph[node][i]; 
                if(color[adjNode] == -1){
                    color[adjNode] = 1 - color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode] == color[node]){
                    return false;
                }
            }
        }  
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
        
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){      
            if(color[i] == -1){  
                if(!checkBipartite(i, graph, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};