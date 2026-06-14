class Solution {
public:
    int maximumSwap(int num){
        int k = num;
        vector<int> v;
        while(num > 0){
            int x = num%10;
            v.push_back(x);
            num = num/10;
        }
        reverse(v.begin() , v.end());
        vector<int> v1 = v;
        int ct = 0;
        // if(is_sorted(v.begin() , v.end())){
        //     return k;
        // }
        sort(v1.begin() , v1.end() , greater<int>());
        for(int i = 0; i < v.size(); ++i){
            if(v1[i] != v[i]){
                ct = i;
                break;
            }
        }
        int ct0 = 0;
        for(int i = v.size()-1; i >= 0; --i){
            if(v1[ct] == v[i]){
                ct0 = i;
                break;
            }
        }
        swap(v[ct] , v[ct0]);
        int nm = 0;
        for(int i = 0; i < v.size(); ++i){
            nm = nm*10 + v[i];
        }
        return nm;
        
    }
};