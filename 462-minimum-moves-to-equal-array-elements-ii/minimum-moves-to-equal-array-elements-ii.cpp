class Solution {
public:
    int minMoves2(vector<int>& v){
        sort(v.begin() , v.end());
        long long sum = v[v.size()/2];
        long long ct = 0;
        for (int i = 0; i < v.size(); ++i) {
            ct = ct + abs(v[i] - sum);
        }

        return ct;
    }
};