class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string cur = "";
        int k = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');         
            } else if (ch == '[') {
                counts.push(k);                 
                strs.push(cur);                  
                k = 0;
                cur.clear();                     
            } else if (ch == ']') {
                int times = counts.top(); counts.pop();
                string prev = strs.top(); strs.pop();
                string repeated;
                repeated.reserve(cur.size() * times);
                for (int i = 0; i < times; ++i) repeated += cur;
                cur = prev + repeated;           
            } else { 
                cur.push_back(ch);
            }
        }
        return cur;
    }
};
