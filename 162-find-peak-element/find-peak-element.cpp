class Solution {
public:
    int findPeakElement(vector<int>& v) {
        auto mx = max_element(v.begin() , v.end());
        auto z = mx - v.begin();
        return z;
    }
};