class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        map<int , int> m;
        for(int i = 0 ; i < v.size(); ++i){
            m[v[i]]++;
        }
        vector<int> vp;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second >= 2){
                vp.push_back(it->first);
                vp.push_back(it->first);
            }
            else if(it->second < 2){
                vp.push_back(it->first);
            }
        }
        sort(vp.begin() , vp.end());
        int n = vp.size();
        v.clear();
        for(int i = 0 ; i < vp.size(); ++i){
            v.push_back(vp[i]);
        }
       
        return v.size();
    }
};