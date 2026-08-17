class Solution {
public:
    bool check(long long mid,long long k,long long x)
    {
        long long p=1;
        while(p<=mid)
            p=p*2;
        long long temp=0;
        long long rem=p-mid-1;
        for(long long i=1;i<=62;i++)
        {
            long long k1=(1ll<<(i-1));
            if(k1>=p)
                break;
            if(i%x==0)
            {
                k-=(p/2);
            }
            k1=(1ll<<(i));
            if(i%x==0)
            {
                k+=(rem/k1)*(k1/2)+min(rem%k1,k1/2);
            }
            if(k<0)
                return false;
        }
        return k>=0;
    }
    long long findMaximumNumber(long long k, int x) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long l=0;
        long long h=1e18;
        long long ans=0;
        long long x1=x;
        while(l<=h)
        {
            long long mid=(l+h)/2;
            if(check(mid,k,x1))
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};