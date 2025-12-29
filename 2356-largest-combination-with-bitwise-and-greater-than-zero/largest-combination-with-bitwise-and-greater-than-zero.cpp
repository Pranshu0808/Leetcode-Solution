class Solution {
public:
    int largestCombination(vector<int>& v) {
        int n = v.size();
        unordered_map<int , int> m;
        for(int i =0;i < n; ++i){
            for(int j = 24; j >= 0; --j){
                if(((v[i]) >> j) & 1 != 0){
                    m[j]++;
                }
            }
        }
        int mx = 0;
        for(auto it = m.begin(); it != m.end(); ++it){

            mx = max(mx , it->second);
        }
        return mx;
        
    }
};