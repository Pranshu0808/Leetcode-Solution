class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < tmp.size(); i++)
            mp[tmp[i]] = i + 1;

        vector<int> res(arr.size());
        for (int i = 0; i < arr.size(); i++)
            res[i] = mp[arr[i]];

        return res;
    }
};