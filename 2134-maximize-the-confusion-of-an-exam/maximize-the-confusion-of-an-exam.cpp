class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        unordered_map<char , int> m;
        int n = s.size();
        int l = 0 , r  = 0 , mx = 0 , mxlen = 0;
        while(r < n){
            m[s[r]]++;
            mx = max(mx , m[s[r]]);
            int x = r - l + 1;
            if((x - mx ) > k){
                m[s[l]]--;
                l++;
            }
            mxlen = max(mxlen , r-l + 1);
            r++;
           //  mAX LEN = MAX(MAN , LEN );
        }
        return mxlen;
    }
};