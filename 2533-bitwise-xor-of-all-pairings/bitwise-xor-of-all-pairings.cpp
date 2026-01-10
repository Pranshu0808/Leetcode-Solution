class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m = nums2.size();
        int x = 0;
        if(n%2 != 0 && m%2 != 0){
            for(int i = 0 ; i < n; ++i){
                x ^= nums1[i];
            }
            for(int i = 0 ; i < m; ++i){
                x ^= nums2[i];
            }
        }
        else if(n%2 == 0 && m%2 != 0){
            for(int i = 0 ; i < n; ++i){
                x ^= nums1[i];
            }
        }
        else if(n%2 != 0 && m%2 == 0){
            for(int i = 0 ; i < m; ++i){
                x ^= nums2[i];
            }
        }
        else{
            return 0;
        }

        return x;
        
    }
};