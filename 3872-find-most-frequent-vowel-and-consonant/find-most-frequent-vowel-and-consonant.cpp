class Solution {
public:
    int maxFreqSum(string s){
      
        unordered_map< char , int> m1 , m2;
        for(int i = 0 ; i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                m1[s[i]]++;
            }
            else{
                m2[s[i]]++;
            }
        }
        
        int mx1 = 0 , mx2 = 0;
        for(auto it = m1.begin(); it != m1.end(); ++it){
            if(mx1 < it->second){
                mx1 = it->second;
            }
        }

        for(auto it = m2.begin(); it != m2.end(); ++it){
            if(mx2 < it->second){
                mx2 = it->second;
            }
        }
        int sum = mx1 + mx2;
        return sum;
    }
};