class Solution {
public:
    int trap(vector<int>& arr){
        int n = arr.size();
        int lmx = 0 , rmx = 0 ,sum = 0,  l = 0 , r = n-1 ;
        while(l < r){
            if(arr[l] <= arr[r]){
                if(lmx > arr[l]){
                    sum += lmx - arr[l];
                }
                else{
                    lmx = arr[l];
                   
                }
                l = l + 1;
            }
            else{
                if(rmx > arr[r]){
                    sum = sum + rmx - arr[r];
                }
                else{
                    rmx = arr[r];
                }
                r = r -1;
            }
        }
        return sum;
      
    }
};