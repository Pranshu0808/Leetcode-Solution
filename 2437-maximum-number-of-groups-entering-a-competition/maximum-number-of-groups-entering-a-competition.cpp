class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n =  grades.size();
        int ct = 0;
        int x = 1;
        while(n > 0){
            n = n - x;
            ct++;
            x = x + 1;
            if(n == 0){
                return ct;
            }
            else if(n < 0){
                return ct-1;
            }
        }
        return -1;
         
    }
};