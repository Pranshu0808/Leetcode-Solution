class Solution {
public:

    void f(string &s, int ind, vector<string> &ans){

        if(ind == s.size()){
            ans.push_back(s);
            return;
        }

        if(isdigit(s[ind])){
            f(s, ind + 1, ans);
            return;
        }

        s[ind] = tolower(s[ind]);
        f(s, ind + 1, ans);

        s[ind] = toupper(s[ind]);
        f(s, ind + 1, ans);
    }

    vector<string> letterCasePermutation(string s){

        vector<string> ans;
        f(s, 0, ans);

        return ans;
    }
};