class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& v1) {
        vector<vector<int>> vp;
        int n = v.size();
        int i = 0;

        while(i < n && v[i][1] < v1[0]) {
            vp.push_back(v[i]);
            i++;
        }

        while(i < n && v[i][0] <= v1[1]) {
            v1[0] = min(v1[0], v[i][0]);
            v1[1] = max(v1[1], v[i][1]);
            i++;
        }
        vp.push_back(v1);

        while(i < n) {
            vp.push_back(v[i]);
            i++;
        }

        return vp;
    }
};
