class Solution {
public:
    vector<int> searchRange(vector<int>& v , int target) {
        int lo = 0 , hi = v.size()-1 , ans  = -1;
        vector<int> v1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(v[mid] >= target){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }
        if(ans == -1 || v[ans] > target){
              v1.push_back(-1);
            v1.push_back(-1);
        return v1;
        }
        else{
            v1.push_back(ans);
            int ans1 = v.size();

            lo = 0 , hi = v.size()-1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(v[mid] > target){
                    ans1 = mid;
                    hi = mid-1;
                }
                else{
                    lo = mid + 1;
                }
            }
            ans1 = ans1 -1;
            v1.push_back(ans1);
            return v1;
        }
    
        
        
    }
};