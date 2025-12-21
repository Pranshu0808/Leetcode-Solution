class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size();
        int mn = min_element(v.begin() , v.end())- v.begin();
        if(target>= v[mn]&& target <= v[n-1]){
            int lo = mn  ,hi = n-1 , ans = -1;
            while(lo <= hi){
                int mid = (lo+hi)/2;
                if(v[mid] == target){
                    ans = mid;
                    return ans;
                }
                else if(v[mid] > target){
                    hi = mid -1;
                }
                else{
                    lo = mid + 1;
                }
        }
        return -1;
        }
        else{
    
        int lo = 0 ,hi = mn-1, ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(v[mid] == target){
                ans = mid;
                return ans;
            }
            else if(v[mid]  < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
       return -1;
    }
    
      
        

    }
};