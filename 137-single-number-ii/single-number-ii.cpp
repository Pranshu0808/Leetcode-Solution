class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int ,int> m;
        for(int i = 0 ; i < nums.size(); ++i){
            m[nums[i]]++;
        }
        int p; 
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second == 1){
                p = it->first;
            }
        }
        return p;
    }
};