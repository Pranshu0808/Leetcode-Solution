class Solution {
public:
    int largestRectangleArea(vector<int>& h){
        int n = h.size();
        // NEXT GREATER ELEMENT................ 
        vector<int> nse(n);
        stack<int> s ;
        for(int i = n-1; i >= 0; --i){
            while(!s.empty() && h[s.top()] >= h[i]){
                s.pop();
            }
            if(s.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = s.top();
            }
            s.push(i);
        }
        // PREVIOUS SMALLER ELEMENT............
        vector<int> pse(n);
        stack<int> s1;
        for(int i = 0; i < n; ++i){
            while(!s1.empty() && h[s1.top()] >= h[i]){
                s1.pop();
            }
            if(s1.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = s1.top();
            }
            s1.push(i);
        }
        int mx = 0;
        for(int i = 0 ; i < n; ++i){
            mx = max(mx , h[i]*(nse[i] - pse[i] - 1));

        }
        return mx;
        
        
        
    }
};