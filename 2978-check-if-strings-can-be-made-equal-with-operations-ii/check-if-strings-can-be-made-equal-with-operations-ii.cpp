class Solution {
public:
    bool checkStrings(string s1, string s2){
        int n = s1.size();
        unordered_map<char, pair<int,int>> mp;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                mp[s1[i]].first++;  
            } else {
                mp[s1[i]].second++;  
            }
        }
         for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                mp[s2[i]].first--;  
            } else {
                mp[s2[i]].second--;  
            }
        }


       for(auto it = mp.begin(); it != mp.end(); ++it){
        for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second.first != 0 || it->second.second != 0){
            return false;
            break;
        }
    }
       }
        return true;



    }
};