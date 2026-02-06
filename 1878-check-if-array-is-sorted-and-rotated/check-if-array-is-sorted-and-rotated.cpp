class Solution {
public:
    bool check(vector<int>& v){
        for(int i = 0; i < v.size(); ++i){
            ::rotate(v.rbegin() ,v.rbegin() + 1 , v.rend());
            if(is_sorted(v.begin() , v.end())){
            return true;
        }
        }
        
        return false;
    }
};