class Solution {
public:
    string orderlyQueue(string s, int k){
        string t = s;
       // string g = s;
        if(k > 1){
            sort(s.begin() , s.end());
            return s;
        }
        else{
        for(int i = 0; i <= 1000; ++i){
            sort(s.begin() , s.begin()+k);
            t = min(t ,s);
            s = s + s[k-1];
            s.erase(k-1 ,1);
        }
        return t;
        }
        
        
         
        
    }
};