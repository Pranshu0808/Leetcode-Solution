class Solution {
public:
    int maxGoodNumber(vector<int>& v) {
        int n = v.size();
       vector<int> v1;
       while(v[0] > 0){
            int x = v[0]%2;
            v1.push_back(x);
            v[0] = v[0]/2;
       }
    
        vector<int> v2;
       while(v[1] > 0){
            int x = v[1]%2;
            v2.push_back(x);
            v[1] = v[1]/2;
       }

        vector<int> v3;
       while(v[2] > 0){
            int x = v[2]%2;
            v3.push_back(x);
            v[2] = v[2]/2;
       }
        reverse(v1.begin() , v1.end());
        reverse(v2.begin() , v2.end());
        reverse(v3.begin() , v3.end());
       vector<int> res1;
        res1.insert(res1.end(), v1.begin(), v1.end());
        res1.insert(res1.end(), v2.begin(), v2.end());
        res1.insert(res1.end(), v3.begin(), v3.end());

        vector<int> res2;
        res2.insert(res2.end(), v1.begin(), v1.end());
        res2.insert(res2.end(), v3.begin(), v3.end());
        res2.insert(res2.end(), v2.begin(), v2.end());

         vector<int> res3;
        res3.insert(res3.end(), v2.begin(), v2.end());
        res3.insert(res3.end(), v1.begin(), v1.end());
        res3.insert(res3.end(), v3.begin(), v3.end());

         vector<int> res4;
        res4.insert(res4.end(), v2.begin(), v2.end());
        res4.insert(res4.end(), v3.begin(), v3.end());
        res4.insert(res4.end(), v1.begin(), v1.end());


        vector<int> res5;
        res5.insert(res5.end(), v3.begin(), v3.end());
        res5.insert(res5.end(), v1.begin(), v1.end());
        res5.insert(res5.end(), v2.begin(), v2.end());

        vector<int> res6;
        res6.insert(res6.end(), v3.begin(), v3.end());
        res6.insert(res6.end(), v2.begin(), v2.end());
        res6.insert(res6.end(), v1.begin(), v1.end());

        vector<vector<int>> all = {res1 , res2 , res3, res4 , res5 , res6};
        vector<int> vt =  *max_element(all.begin(), all.end());
        reverse(vt.begin() , vt.end());
        int ct = 0;
        for(int i = 0; i < vt.size(); ++i){
            ct = ct + vt[i]*pow(2 , i);
        }
        return ct;
        
       
    }
};