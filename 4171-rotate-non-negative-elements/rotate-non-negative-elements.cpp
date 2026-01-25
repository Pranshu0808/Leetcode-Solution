class Solution {
public:
    vector<int> rotateElements(vector<int>& v, int k) {
        int n = v.size();
        vector<int> v1;
        for(int i = 0 ; i <n ; ++i){
            if(v[i] >= 0){
                v1.push_back(v[i]);
            }
        }
        int x = 0;
        if(v1.size() > 0){
        k = k%v1.size();
        std::rotate(v1.begin(), v1.begin() + k, v1.end());
        for(int i =0; i < n; ++i){
            if(v[i] >= 0){
                v[i] = v1[x];
                x++;
            }
        }
        }
        return v;

    }
};