class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        int n = s.size();
        vector<int> hsh(26 , 0);

        for(int i =0; i < n; ++i){
            hsh[s[i] - 'a']++;
        }

        string s1 = "";

        for(int i = 25; i >= 0; --i){

            while(hsh[i] > 0){

                int ct = 0;

                while(hsh[i] > 0 && ct < rl){
                    s1.push_back('a' + i);
                    hsh[i]--;
                    ct++;
                }

                if(hsh[i] == 0) break;

                int j = i - 1;

                while(j >= 0 && hsh[j] == 0){
                    j--;
                }

                if(j < 0) return s1;

                s1.push_back('a' + j);
                hsh[j]--;
            }
        }

        return s1;
    }
};