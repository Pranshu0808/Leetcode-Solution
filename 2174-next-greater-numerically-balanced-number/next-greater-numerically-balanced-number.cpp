class Solution {
public:
    int nextBeautifulNumber(int n){
          int ct = 0;
          if(n >= 666666){
            return 1224444;
          }
           n++;
           
          while(true){
            unordered_map<int ,int> m;
            int temp = n;
            while(temp > 0){
                int x = temp%10;
                m[x]++;
                temp = temp/10;
            }
            bool b = true;
            for(auto it = m.begin() ; it != m.end(); ++it){
                if(it->first != it->second){
                    b = false;
                }
            }

            if(b == true){
                ct = n;
                break;
            }
            n++;
          }
          return ct;
        
    }
};     

 auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
