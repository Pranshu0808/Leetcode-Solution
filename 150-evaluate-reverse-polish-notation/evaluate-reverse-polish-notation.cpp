
  class Solution {
public:
    int priority(char c){
        if(c == '+' || c == '-') return 1;
        if(c == '*' || c == '/') return 2;
        return 0;
    }

    long long  eval(long long a, long long b , char op){
        if(op == '+') return a + b;
        if(op == '-') return a - b;
        if(op == '*') return a * b;
        return a / b;   // integer division (trunc toward zero)
    }

    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(const string &tok : tokens){
            if(tok == "+" || tok == "-" || tok == "*" || tok == "/"){
                // operator: pop two operands (b is top, a is next)
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                char op = tok[0];
                st.push(eval(a, b, op));
            } else {
                // number (may be multi-digit or negative), push it
                long long num = stoll(tok);
                st.push(num);
            }
        }

        long long res = 0;
        if(!st.empty()) res = st.top();

        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};
