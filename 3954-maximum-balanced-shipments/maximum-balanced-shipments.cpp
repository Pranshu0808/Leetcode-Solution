class Solution {
public:
    int maxBalancedShipments(vector<int>& v) {
        int n = v.size();
        int ct = 0;
        for(int i = 0 ; i < n-1; ++i){
            if(v[i] > v[i+1]){
                ct++;
                i++;
            }
        }
        return ct;
    }
};