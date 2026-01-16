class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>v;
        // int i=0;
        // int j=0;
        // while(i<nums1.size()&&j<nums2.size()){
        //     if(nums1[i]<nums2[j]){
        //         v.push_back(nums1[i++]);
        //     }
        //     v.push_back(nums2[j]++);
        // }

        nums1.insert(nums1.end() , nums2.begin() , nums2.end());
        sort(nums1.begin() , nums1.end());
        if(nums1.size()%2 != 0){
            int x = nums1.size()/2;
            return nums1[x]*1.0;
        }
        else{
            int x = nums1.size()/2;

            return ((nums1[x]+nums1[x-1])*1.0)/2;
        }


        
    }
};