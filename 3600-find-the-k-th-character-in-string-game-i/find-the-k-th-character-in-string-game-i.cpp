class Solution {
public:
    char f(string s , int k){
    
    int t = s.size();
    for(int i = 0; i < t; ++i){
        if(s[i] == 'z'){
            s.push_back('a');
        }
        else{
            s.push_back(s[i] + 1);
        }
    }
    if(k <= s.size()){
        return s[k-1];
    }
    else{
        return f(s , k);
    }
}
    char kthCharacter(int k){
        string s = "a";
        return f(s , k );
       
    }
};