class Solution {
public:
    int partitionArray(vector<int>& v, int k) {
        sort(v.begin() , v.end());

        int ct = 0;
        int x = 0;
        int deff;
        for(int i = 1; i < v.size(); ++i){
            deff = v[i] - v[x];

            if(deff > k){
                ct++;
                x = i;
                i=i-1;
            }
        }
        if(deff <= k){
            ct = ct +1;
            return ct;
        }
        else{
            return ct+1;
        }
    
    }
};