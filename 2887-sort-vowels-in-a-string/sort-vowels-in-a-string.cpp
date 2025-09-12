class Solution {
public:
    string sortVowels(string s){
        vector<char>  v1 , v;
        for(int i = 0 ;i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                v1.push_back(s[i]);
            }
        
           
        }
        sort(v1.begin() , v1.end());
        string s1;
        long long ct = 0;
        for(int i = 0 ;i < s.size(); ++i){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
               s[i] =  v1[ct];
                ct++;
            }
           
        }
       
        return s;

    }
};