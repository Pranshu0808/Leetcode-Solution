class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        bool b = true;
       for(int i=0;i<v.size();i++){
            unordered_map<char,int>freq;
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]>'0'&& v[i][j]<='9') {
                    freq[v[i][j]]++;

                }
               

            }
            for(auto & a:freq){
                if(a.second>1){
                    return false;
                }
            }
        }
        for(int i=0;i<v[0].size();i++){
            unordered_map<char,int>freq1;
            for(int j=0;j<v.size();j++){
                if((v[j][i]>'0' && v[j][i]<='9')){
                    freq1[v[j][i]]++;

                }
               

            }
            for(auto & a:freq1){
                if(a.second>1){
                   return false;
                }
            }
        }
for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                unordered_map<char,int>freq3;
                for(int k=i*3;k<i*3+3;k++){
                    
                    for(int l=j*3;l<j*3+3;l++){
                        if(v[k][l]>'0' && v[k][l]<='9'){
                            freq3[v[k][l]]++;
                        }

                    }
                    for(auto a:freq3){
                        if(a.second>1){
                            return false;
                        }
                    }
                }

            }
        }
        return b;
    }
};