class Solution {
public:
    int minSwaps(string s){
        stack<int> st;
        int ct = 0 , ct1 = 0 ,sum = 0;
        int l = 0  , r = s.size()-1;
       for(int i = 0; i < s.size(); ++i){
            st.push(s[l]);
            if(s[i] == ']'){
                ct++;
            }
            if(s[i] == '['){
                ct1++;
            }
            
            if(ct > ct1){
                st.pop();
                while(s[r] == '['){
                    st.push(s[r]);
                    r--;
                }
                
                s[r] = ']';
                ct--;
                ct1++;
                sum++;
            }
        }
        return sum;
    }
};