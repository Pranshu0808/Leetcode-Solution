class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        int n = v.size();
        int minlen = INT_MAX;
        unordered_map<int , int > m;

        for(int i = 0 ; i < n; ++i){
            int x = v[i];
            if(m.find(x) != m.end()){
                int y = i - m[x] + 1;
                minlen = min(minlen , y);
            }
            m[v[i]] = i;
        }
        if(minlen == INT_MAX){
            return -1;
        }
        else{
            return minlen;
        }
    }
};