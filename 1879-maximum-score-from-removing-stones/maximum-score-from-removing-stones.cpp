class Solution {
public:
    int maximumScore(int a, int b, int c){
        vector<int > v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;
        sort(v.begin() , v.end());
        int x = v[0];
        int y = v[2] - v[1];
        if(y >= x){
            return x + v[1];
        }
        else{
            x = x-y;
            v[2] = v[1];
            if(x%2 == 0){
                x = x/2;
                v[1] = v[1] - x;
                return v[0] + v[1];
            }
            else{
                x =( 1+ x)/2;
                v[1] = v[1] - x;
                return v[0] + v[1];

            }
        }
      
        
    }
};