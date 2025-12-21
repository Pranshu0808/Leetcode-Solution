class Solution {
public:
    int findMin(vector<int>& v){
        int mn = *min_element(v.begin() , v.end());
        return mn;
    }
};