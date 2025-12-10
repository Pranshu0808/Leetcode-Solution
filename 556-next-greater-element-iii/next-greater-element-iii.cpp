class Solution {
public:
  long long nextGreaterElement(long long n) {
    long long  temp = n;
        vector<int> v;
        while(n>0){
            int ld = n%10;
            v.push_back(ld);
            n =n/10;
        }
        reverse(v.begin(), v.end());
        next_permutation(v.begin(), v.end());
        string s;
        for(int i =0;i < v.size(); ++i){
            s = s+ to_string(v[i]);
        }
            long long x = stoll(s);
      if(x > INT_MAX){
          return -1;
      }
    else if(x>temp){
    return x;
    }
else {
    return -1;
}
    }
};