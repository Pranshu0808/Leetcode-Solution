class Solution {
public:

    int minimumSum(int n, int k){
        vector<int> v;
        vector<int> v1;
        for(int i = 1; i < (k+1)/2 ; ++i){
                v1.push_back(k-i);
        }
        for(int i =1; i < 100 && v.size() < n; ++i){
            auto it = find(v1.begin() , v1.end() ,i );
            if(it == v1.end()){
                v.push_back(i);
            }
        }
        int x = accumulate(v.begin() , v.end() , 0);
        return x;
        
    }
};