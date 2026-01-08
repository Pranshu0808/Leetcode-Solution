class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char , int> m;
        for(int i = 0; i < n; ++i){
            m[word[i]]++;
        }
        
        vector<int> v;
        for(auto it = m.begin(); it != m.end(); ++it){
            v.push_back(it->second);
        }
        sort(v.begin() , v.end());
        int x = v.size();
        int ct = 0;
        if(x%8 == 0){
            int y = x/8;
            int l = 0;
            
                for(int i = 0; i < x; ++i){
                    if(l < 8){
                        ct = ct + y*v[i];
                    }
                    l++;
                    if(l == 8){
                        l = 0;
                        y--;
                    }
                }
          
        }
        else{
            int f = x%8;
            int y = x/8;
            y = y + 1;
            for(int i =0; i < f; ++i){
                ct = ct + y*v[i];
            }
            y--;
            int l = 0;
            
                for(int i = f; i < x; ++i){
                    if(l < 8){
                        ct = ct + y*v[i];
                    }
                    l++;
                    if(l == 8){
                        l = 0;
                        y--;
                    }
                }
            
           
        }
        return ct;
    }
};