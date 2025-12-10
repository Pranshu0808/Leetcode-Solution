class Solution {
public:
    int priority(char c){
        if(c == '+' || c == '-') return 1;
        if(c == '*' || c == '/') return 2;
        return 0;
    }
    int eval(int a, int b , char op){
        if(op == '+') return a+b;
        if(op == '-') return a-b;
        if(op == '*') return a*b;
        return a/b;
        
    }
    int calculate(string s){
        stack<int> ans;
        stack<char> st;
       int  n =  s.size();
       for(int i = 0 ; i  <n; ++i){
            char c = s[i];
            if(c == ' '){
                continue;
            }
            if(isdigit(c)){
                long long num = 0;
                while(i < n && isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                ans.push(num);
                i--;
            }
            else if(c == '('){
                st.push(c);
            }
            else if(c == ')'){
                while(!st.empty() && st.top() != '('){
                    int b = ans.top(); ans.pop();
                    int a = ans.top(); ans.pop();
                    char op = st.top(); st.pop();
                    ans.push(eval(a,b, op));
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            else{

                 if (c == '+' || c == '-') {
                    int j = i - 1;
                    while (j >= 0 && s[j] == ' ') j--;
                    if (j < 0 || s[j] == '(' || s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/') {
                        
                        ans.push(0);
                    }
                }
                while(!st.empty() && priority(st.top()) >= priority(s[i])){
                    int b = ans.top(); ans.pop();
                    int a = ans.top(); ans.pop();
                    char op = st.top(); st.pop();
                    ans.push(eval(a,b, op));
                }
                st.push(s[i]);
            }  
       }
        while(!st.empty()){
            int b = ans.top(); ans.pop();
            int a = ans.top(); ans.pop();
            char op = st.top(); st.pop();
            ans.push(eval(a,b, op));
       }
       if(ans.empty()){
            return 0;
        } 
        else {
            return ans.top();
        }
    }
};
