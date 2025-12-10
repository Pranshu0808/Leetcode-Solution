class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
   
        stack<int> s;
        for(int i = 0; i < n; ++i){
            if(a[i] > 0){
                s.push(a[i]);
            }
            else{
                if((!s.empty() && s.top() < 0) || s.empty()){
                    s.push(a[i]);
                }
                else{
                while(!s.empty() && s.top() < abs(a[i]) && s.top() > 0){
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(a[i])){
                    s.pop();
                    continue;
                }
                if(!s.empty() && s.top() > abs(a[i])){
                    continue;
                }
                else{
                    s.push(a[i]);
                }
                }
                
            }
        }
        
        vector<int> v;
        while(!s.empty()){
           v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin() , v.end());
        return v;
    }
};