class Solution {
public:
    int minPartitions(string n) {

        vector<int> v;
        for(int i = 0 ; i < n.size(); ++i){
            int x = n[i] - '0';
            v.push_back(x);
        }
        int mx = *max_element(v.begin() , v.end());
        return mx;
    }
};