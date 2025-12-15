class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int , int >> vp;
        for(int i = 0; i < n; ++i){
            vp.push_back({position[i] , speed[i]});
        }
        sort(vp.begin() , vp.end());
        vector<double> v(n);
        for(int i = 0 ; i < n; ++i){
            v[i] = ((target - vp[i].first)*1.0)/(vp[i].second);
        }
        stack<double> st;
        
        for(int i =0; i < n; ++i){
           while(!st.empty() && st.top() <= v[i]){
                st.pop();
           }
           st.push(v[i]);
           
        }
        int ct = 0;
        while(!st.empty()){
            ct++;
            st.pop();
        }
        return ct;



    }
};