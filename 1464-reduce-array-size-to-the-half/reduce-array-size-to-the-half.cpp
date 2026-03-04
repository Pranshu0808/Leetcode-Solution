class Solution {
public:
    int minSetSize(vector<int>& arr){
        int n = arr.size();
        int x = n/2;
        unordered_map<int , int> m;
        for(int i =0; i < n; ++i){
            m[arr[i]]++;
        }
        vector<pair<int , int>> v;
        for(auto it = m.begin(); it != m.end(); ++it){
            v.push_back({it->second , it->first});
        }
        sort(v.begin() , v.end());
        int sum = 0;
        int ct = 0;

        for(int i = v.size()-1; i >= 0; --i){
            sum += v[i].first;
            ct++;
            if(sum >= x){
                
                break;
            }
        }
        return ct;
    }
};