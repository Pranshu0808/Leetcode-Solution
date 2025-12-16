class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while((s.size() +n-i ) > k && !s.empty() && s.top() > nums[i]){
                s.pop();
            }
            s.push(nums[i]);
        }
        if(s.size() >= k){
            vector<int> v;
            while(!s.empty()){
                v.push_back(s.top());
                s.pop();
            }
            reverse(v.begin() , v.end());
            vector<int> v1;

            for(int i= 0; i < v.size() && v1.size() < k; ++i){
                v1.push_back(v[i]);
            }
            return v1;
        }
        else{
                return nums;
        }

    }
};