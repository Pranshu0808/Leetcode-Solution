class Solution {
public:
    int minOperations(vector<int>& a){
        int num = a[0];
        for(int i=1;i<a.size();i++){
            if(a[i] != num) return 1;
        }
        return 0;
    }
};