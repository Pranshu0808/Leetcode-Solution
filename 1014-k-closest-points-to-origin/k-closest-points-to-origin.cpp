class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k){
        int n = v.size();
        vector<pair< double , pair<int , int> >> vp;
        for(int i = 0 ;i < n; ++i){
            int x = (abs(v[i][0]*v[i][0]) + abs(v[i][1]*v[i][1]));
            vp.push_back({sqrt(x) , {v[i][0] , v[i][1]}});
        }
        sort(vp.begin() , vp.end());
        vector<vector<int>> v1(k , vector<int>(2));
        for(int i = 0; i < k; ++i){
            v1[i][0] = vp[i].second.first;
            v1[i][1] = vp[i].second.second;
        }
        return v1;
        
        
    }
};