class Solution {
public:
    int maxCount(vector<int>& v, int n, int maxSum){
        sort(v.begin() , v.end());
        set<int> s;
        for(int i = 0 ; i < v.size(); ++i){
            s.insert(v[i]);
        }
        long long mx = 0;
        int ct = 0;
        for(int i = 1; i <= n; ++i){
            if(s.find(i) == s.end()){
                mx += i;
                if(mx > maxSum){
                    break;
                }
                ct++;
            }
        }
        return ct;
    }
};