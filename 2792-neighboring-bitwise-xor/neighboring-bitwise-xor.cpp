class Solution {
public:
    bool doesValidArrayExist(vector<int>& v) {
        int ans = 0;
        for(int i = 0 ; i < v.size(); ++i){
            ans ^= v[i];
        }
        if(ans == 0){
            return true;
        }
        else{
            return false;
        }
    }
};