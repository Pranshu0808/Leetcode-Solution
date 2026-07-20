class Solution {
public:
    
    int waysToReachStair(int k) {
        //for k = 0 1 2 3 4
        int res[5] = {2, 4, 4, 3, 2};
        if(k<5){
            return res[k];
        }
        // pascals triangle where pt[n][r] = C(n,r)
        int pt[31][31] = {};
        pt[0][0] = 1;

        for(int i=1;i<31;i++){
            pt[i][0] = 1;
            pt[i][i] = 1;
            for(int j=1;j<i;j++){
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
            }
        }
        //find the power of two just greater than k
        int a = 1;
        int count = 0;
        while(k>a){
            a*=2;
            count++;
        }

        if(k<a-count-1){
            return 0;
        }
      
        return pt[count+1][a - k];
    }
};