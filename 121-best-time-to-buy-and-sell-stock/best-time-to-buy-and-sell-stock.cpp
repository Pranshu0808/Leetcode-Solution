class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int mini = prices[0];
        int mxProfit = 0;
        for(int i = 0 ; i < n; ++i){
            int cost = prices[i] - mini;
            mxProfit = max(mxProfit , cost);
            mini = min(mini , prices[i]);
        }
        return mxProfit;
        
    }
};