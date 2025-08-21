class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i = 1; i <=n; ++i){
            v.push_back(i);
        }
        int sum = 0;
        for(int i =0; i < n && v.size() > 1; ++i){
             
             
                sum = (sum-1+k)%v.size();
                 v.erase(v.begin()+(sum));
                //   sum = sum+ k-1;
             
             
            
            
        }
        return v[0];

    }
};