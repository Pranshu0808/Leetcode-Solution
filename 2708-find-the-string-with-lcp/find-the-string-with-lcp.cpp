class Solution {
public:
    string findTheString(vector<vector<int>>& lcp){
        bool f = true;
        int n  = lcp.size();
        for(int i = 0 ; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if((lcp[i][j] != lcp[j][i])){
                    f = false;
                }
                if(lcp[i][i] != n-i){
                    f = false;
                }
            }
        }
        if(!f){
            return "";
        }
        else{
         string ans(n, '1');
        char ch = 'a';

        for(int i = 0; i < n; i++){
            if(ans[i] == '1'){
                if(ch > 'z'){ 
                    return "";
                }
                ans[i] = ch;
                for(int j = i+1; j < n; j++){
                    if(lcp[i][j] > 0){
                        ans[j] = ch;
                    }
                }

                ch++;
            }
        }

       
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(ans[i] == ans[j]){
                    int val = 1;
                    if(i+1 < n && j+1 < n){
                        val += lcp[i+1][j+1];
                    }
                    if(lcp[i][j] != val){
                        return "";
                    }
                }
                else{
                    if(lcp[i][j] != 0){ 
                        return "";
                    }
                }
            }
        }

        return ans;

        }
        
    }
};