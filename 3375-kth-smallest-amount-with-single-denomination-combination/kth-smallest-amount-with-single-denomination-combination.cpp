class Solution {
public:

    long long check(vector<int>&coins,long long mid ){
        int n=coins.size();
        int mask=(1<<n)-1;
        long long count =0;
        for(int i=1;i<=mask;i++){
            long long lcm=1;
            for(int j=0;j<n;j++){
                if(((1<<j)&i)){
                    lcm=(lcm/__gcd(lcm,(long long)coins[j]))*coins[j];
                   // if (lcm > mid);
                }
            }
            if(__builtin_popcount(i)%2==0){
                count-=mid/lcm;
            }
            else{
                count+=mid/lcm;
            }
        }
        return count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        long long  start=0;
        long long end=100*1e11;
        long long ans=0;
        while(start<=end){
            long long mid =start+(end-start)/2;
            long long count =check(coins,mid);
            if(count==k){
                ans=mid;
                end=mid-1;
            }
            else if(count<k){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};