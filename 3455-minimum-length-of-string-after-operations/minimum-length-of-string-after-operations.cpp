class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>  m;
        for(int i = 0 ; i < s.size(); ++i){
            m[s[i]]++;
        }
        int sum = 0;
        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second%2 != 0){
                sum = sum + (it->second-1);
            }
            else{
                sum = sum + (it->second-2);
            }
        }
       int x = s.size()-sum;
       return x;

    }
};