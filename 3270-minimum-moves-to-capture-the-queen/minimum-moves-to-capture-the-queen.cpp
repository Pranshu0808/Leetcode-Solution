class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e){
            if(b>f){
                swap(b,f);
            }
            if(b<=d && d<=f && a==c)return 2;
            return 1;
        }
        if(b==f){
            if(a>e){
                swap(a,e);
                swap(b,f);
            }
            if(a<=c && c<=e && b==d)return 2;
            return 1;
        }
        if((c-d)==(e-f)){
            if(c>e){
                swap(c,e);
                swap(d,f);
            }
            if((c<=a && a<=e) && (d<=b&&b<=f) && (a-b)==(c-d)){
                return 2;
            }return 1;
        }
        if((c+d)==(e+f)){
            if(c<e){
                swap(c,e);
                swap(d,f);
            }
            if((c>=a && a>=e) && (d<=b&&b<=f) && (a+b)==(c+d)){return 2;
            }return 1;
        }
        return 2;
    }
};