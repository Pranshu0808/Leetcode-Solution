class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        vector<int> v;
        int n = A.size();
        unordered_map<int , int > m;
        for(int i = 0; i  <n; ++i){
            m[A[i]]++;
            int ct = 0;
            for(int j = 0; j <= i; ++j){
                if(m.find(B[j]) != m.end()){
                    ct++;
                }
            }
            v.push_back(ct);
        }
        return v;
        
    }
};