class Solution {
public:
    void findComb(int ind , int target , vector<int> &can , vector<int> &ds , vector<vector<int>> &ans){
        if(ind == can.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(can[ind] <= target){
            ds.push_back(can[ind]);
            findComb(ind , target -can[ind], can , ds , ans);
            ds.pop_back();
        }
         findComb(ind+1 , target, can , ds , ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0 , target , candidates , ds , ans);
        return ans;
    }
};