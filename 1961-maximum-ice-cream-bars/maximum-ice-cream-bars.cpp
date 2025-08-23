class Solution {
public:
    int maxIceCream(vector<int>& v, int x) {
        sort(v.begin(),  v.end());
        int ct = 0; 
        int sum = 0;
        for(int i = 0 ; i < v.size(); ++i){
            sum += v[i];
            if(sum <= x){
                ct++;
            }
            else{
                break;
            }
        }
        return ct;
    }
};