class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] <= arr[i + 1])
                left++;
            else{
                break;
                }
        }
        
        if(left == n - 1){
            return 0;
        }
        int right = n - 1;
        for(int i = n - 1; i > 0; i--){
            if (arr[i - 1] <= arr[i])
                right--;
            else
                break;
        }

    
        int ans = min(n - left - 1, right);

        int i = 0, j = right;
        while(i <= left && j < n){
            if(arr[i] <= arr[j]){
                ans = min(ans, j - i - 1);
                i++;
            } 
            else{
                j++;
            }
        }

        return ans;
    }
};
