class Solution {
public:
    void rotate(vector<int>& v, int k){
        if(v.size() == 1){
            v[0] = v[0];
        }
        int x = k%v.size();
        if(v.size() > 1){
        ::rotate(v.rbegin() ,v.rbegin() + x , v.rend());
        }

    }
};