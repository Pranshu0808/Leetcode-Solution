class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        int n = nums2.size();
        vector<int> v(n);
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty()){
                v[i] = -1;
            }
            else{
                v[i] = s.top();
            }
            s.push(nums2[i]);
        }
        vector<pair<int , int>> vp;
        for(int i = 0; i < n; ++i){
            vp.push_back({nums2[i] , v[i]});
        }
        vector<int> v1;
        unordered_map<int , int> m;
        for(int i = 0; i < n; ++i){
            m[vp[i].first] = vp[i].second;
        }
        for(int i = 0; i < nums1.size(); ++i){
            v1.push_back(m[nums1[i]]);
        }
        return v1;



    }
};