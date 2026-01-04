class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& v, int k) {


sort(v.begin(), v.end(), [k](const vector<int>& a, const vector<int>& b){
    return a[k] > b[k];
});
return v;
    }
};