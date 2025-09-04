class Solution {
public:
    int findMinDifference(vector<string>& t) {
        vector<int> v;
        for(int i = 0; i < t.size(); ++i){
            string s1 = "";
            s1 += t[i][0];
            s1 += t[i][1];
            
            int x = stoi(s1);
            if(x == 0){
                x = 24;
            }
            x = x*60;
             string s2 = "";
            s2 += t[i][3];
            s2 += t[i][4];
            int y = stoi(s2);
            int z = x + y;
            v.push_back(z);
        }
        sort(v.begin() , v.end());
        int mn = INT_MAX;
        for(int i = 0; i < v.size()-1; ++i){
            int deff = v[i+1] - v[i];
            mn = min(mn , deff);
        }
        mn = min(mn, 1440 - (v.back() - v[0]));
        return mn;

        
    }
};

