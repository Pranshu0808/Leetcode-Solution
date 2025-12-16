class Solution {
public:
    int maxCoins(vector<int>& p){
        int n = p.size();
        int sum = 0;
        int x = n/3;
        x = x;
        sort(p.begin() , p.end());
        for(int i= x; i < p.size(); i += 2){
                sum = sum + p[i]; 
            
        }
        return sum;   
    }
};