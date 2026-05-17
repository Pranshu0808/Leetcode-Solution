class Solution {
public:
    void findComb(int ind , int target , vector<int> &can , vector<int> &ds , vector<vector<int>> &ans ){
      
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = ind; i < can.size();++i){
            if(i > ind && can[i] == can[i-1]) continue;
            if(can[i] > target) break;
            ds.push_back(can[i]);
            findComb(i+1 , target -can[i], can , ds , ans  );
            ds.pop_back();
        }
          
        
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        sort(can.begin() , can.end());
        findComb(0 , target , can , ds , ans);
        return ans;
    }
};