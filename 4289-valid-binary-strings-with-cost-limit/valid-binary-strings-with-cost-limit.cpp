class Solution {
public:
    void fun(int sm, int ind, int n, int k, vector<string>& v, string s){
        if(s.size() == n){
            if (sm <= k) {
                v.push_back(s);
            }
            return;
        }

        if(s.empty() || s.back() != '1'){
            sm += ind;
            s.push_back('1');

            fun(sm, ind + 1, n, k, v, s);

            sm -= ind;
            s.pop_back();
        }

      
        s.push_back('0');
        fun(sm, ind + 1, n, k, v, s);
        s.pop_back();
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> v;
        string s;
        int ind = 0;
        int sm = 0;

        fun(sm, ind, n, k, v, s);

        return v;
    }
};