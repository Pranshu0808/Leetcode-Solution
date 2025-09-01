class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        for(int i = 0; i < arr1.size(); ++i){
            ans ^= arr1[i];
        }
        int ct = 0;
        for(int i  = 0; i < arr2.size(); ++i){
            ct ^= arr2[i];
        }
        int sum = ans&ct;
        return sum;
    }
};