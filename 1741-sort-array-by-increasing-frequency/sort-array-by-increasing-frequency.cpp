class Solution {
public:
    vector<int> frequencySort(vector<int>& nums){
        int n = nums.size();
        unordered_map<int , int> m;
        for(int i = 0; i < n; ++i){
            m[nums[i]]++;
        }
        vector<pair<int , int>> vp;
        for(auto it = m.begin() ; it != m.end() ; ++it){
            vp.push_back({it->second , it->first});
        }
        vector<int> v;
        sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
    if(a.first == b.first)
        return a.second > b.second;  
    return a.first < b.first;         
});
        for(int i = 0; i < vp.size(); ++i){
            for(int j = 0; j < vp[i].first; ++j){
                v.push_back(vp[i].second);
            }
        }
        return v;
        
    }
};