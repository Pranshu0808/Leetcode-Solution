class Solution {
public:
    string countOfAtoms(string s) {
        map<string, int> mp;
        stack<int> fact;
        int n = s.length(), m = 1, val = 1;

        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];
         
            if(ch >= 'a' && ch <= 'z'){
                string element = "";
                while(!(s[i] >= 'A' && s[i] <= 'Z')){
                    element = s[i] + element;
                    i--;
                }
                element = s[i] + element;
                int freq = m*val;
                mp[element] += freq;
                val = 1;
            }
            
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                string element = "";
                element += s[i];
                int freq = m*val;
                mp[element] += freq;
                val = 1;
            }
            else if(ch == ')'){
                fact.push(val);
                m *= val;
                val = 1;
            }
            else if(ch == '('){
                m /= fact.top();
                fact.pop();
            }
            else{
                string num = "";
                while(s[i] <= '9' && s[i] >= '0'){
                    num = s[i] + num;
                    i--;
                }
                i++; 
                val = stoi(num);
            }
        }
        
        string res = "";
        for(auto it : mp){
            string ele = it.first;
            string freq = "";
            if(it.second != 1) freq += to_string(it.second);
            res += ele + freq;
        }
        return res;
    }
};