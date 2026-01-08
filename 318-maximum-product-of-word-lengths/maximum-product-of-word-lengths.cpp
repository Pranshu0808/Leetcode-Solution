class Solution {
public:
    int getstate(string s) {
        int state = 0;
        for(int c = 0; c < s.size(); c++){
            int index = s[c] - 'a';
            state |= 1 << (index);
           } 
        return state;
       } 
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int state[n];
        for(int i = 0; i < n; i++)
            state[i] = getstate(words[i]);
          
        int answer = 0;
        for(int i = 0; i < n; i++) 
            for(int j = i+1; j < n; j++) 
                if(!(state[i] & state[j])) {
                    int ans = words[i].size()*words[j].size();
                    answer = max(answer, ans) ;
                }
        return answer;
    }
};