class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v){
       
        sort(h.begin() , h.end());
        sort(v.begin() , v.end());
        v.push_back(0);
        h.push_back(0);
        int x = h.size();
        int ct = 0;
        int mx = 0;
        for(int i =0; i < x-1; ++i){
            if(h[i] == h[i+1]-1){
                ct++;
            }
            else{
                mx = max(mx, ct);
                ct = 0;
            }
        }

        int x1  = v.size();
        int ct1 = 0;
        int mx1 = 0;
        for(int i =0; i < x1-1; ++i){
            if(v[i] == v[i+1]-1){
                ct1++;
            }
            else{
                mx1 = max(mx1 , ct1);
                ct1 = 0;
            }
        }
        int f = min(mx, mx1);
        int y = (f+2)*(f+2);
        return y;
        
    }
};