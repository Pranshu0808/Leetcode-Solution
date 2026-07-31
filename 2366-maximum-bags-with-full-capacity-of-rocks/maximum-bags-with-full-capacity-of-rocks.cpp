class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int>v(capacity.size());
        for(int i = 0; i<capacity.size();i++){
            v[i]= capacity[i]-rocks[i];
        }
        sort(v.begin(),v.end());
        int ans =0;
        for(int i = 0 ;i<v.size();i++){
            if(v[i]==0) ans++;
            else if(a>= v[i]) {
                ans++;
                a -= v[i];
            }
            else break;
        }
        return ans;
    }
};