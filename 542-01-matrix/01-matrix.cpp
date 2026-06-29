class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int time=1;
        while(!q.empty()){
            int sz=q.size();
            for(int j=0;j<sz;j++){
                auto[r,c]=q.front();
            for(int i=0;i<4;i++){
                int ndr=r+dir[i][0];
                int ndc=c+dir[i][1];
                if(ndr<0 ||ndr>=n ||ndc<0 || ndc>=m || vis[ndr][ndc]){
                    continue;
                }
                dp[ndr][ndc]=time;
                q.push({ndr,ndc});
                vis[ndr][ndc]=true;
            }
            q.pop();
            }
            time++;
        }
        return dp;
    }
};