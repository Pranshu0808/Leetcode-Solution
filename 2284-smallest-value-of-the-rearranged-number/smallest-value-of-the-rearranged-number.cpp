class Solution {
public:
    long long smallestNumber(long long num){
        vector<int> v;
        if(num == 0){
            return 0;
        }
        if(num > 0){
            while(num > 0){
                int x = num%10;
                v.push_back(x);
                num = num/10;
        }
        sort(v.begin() , v.end());
        int f = -1;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] == 0){
                f = i;
            }
        }
        if(f != -1){
        swap(v[0] , v[f+1]);
        }
        long long d = 0;
        for(int i = 0; i < v.size(); ++i){
            d = d*10 + v[i];
        }
        return d;
        }
        else{
            num = abs(num);
            while(num > 0){
                int x = num%10;
                v.push_back(x);
                num = num/10;
        }
        
        sort(v.begin() , v.end() , greater<int>());
        long long d = 0;
        for(int i = 0; i < v.size(); ++i){
            d = d*10 + v[i];
        }
        d = -d;
        return d; 
        }
        return -1;
        
    }
};