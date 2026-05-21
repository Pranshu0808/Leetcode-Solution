class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        unordered_set<string>mpp;
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            string s="";
            int x=arr1[i];
            while(x>0){
                s.push_back(char((x%10)+'0'));
                x=x/10;
            }
            reverse(s.begin(),s.end());
            for(int i=1;i<=s.size();i++){
                mpp.insert(s.substr(0,i));
            }
        }
        for(int i=0;i<arr2.size();i++){
            string s="";
            int x=arr2[i];
            while(x>0){
                s.push_back(char((x%10)+'0'));
                x=x/10;
            }
            reverse(s.begin(),s.end());
            for(int i=1;i<=s.size();i++){
                if(mpp.find(s.substr(0,i))!=mpp.end()) ans=max(ans,i);
            }

        }
        return ans;
    }
};