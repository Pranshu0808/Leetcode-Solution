class Solution {
public:
    int countCompleteSubarrays(vector<int>& v){
        int n = v.size();
        unordered_set<int> s , s1;
        for(int i = 0 ; i < n; ++i){
            s.insert(v[i]);
        }
        int x = s.size();
        int ct = 0;
        for(int i = 0 ; i <n; ++i){
            s1.clear();
            for(int j = i ; j < n; ++j){
                s1.insert(v[j]);
                if(s1.size() == x){
                    ct++;
                }
            }
        }
        return ct;

    }
};