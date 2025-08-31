class Solution {
public:
    vector<int> singleNumber(vector<int>& nums){
        map<int , int> m;
        int ans = 0;
        for(int i =0 ; i < nums.size(); ++i){
            m[nums[i]]++;
        }
        vector<pair<int , int>> vp;
        for(auto it = m.begin(); it != m.end(); ++it){
            vp.push_back({it->second , it->first});
        }
        sort(vp.begin() , vp.end());
        vector<int> v;
        v.push_back(vp[0].second);
        v.push_back(vp[1].second);
        return v;
    }
};