class Solution {
public:
    int reverse(int x) {
        if(x > -10 && x < 10){
            return x;
        }
        if(x == 10){
            return 1;
        }
        if(x == -10){
            return -1;
        }
        
        if(x >= 0){
            string s;
        while(x >= 10){
            int ld = x%10;
            s = s + to_string(ld);
            x = x/10;
        }
        int y = stoi(s);
            if(y > INT_MAX/10){
                return 0;
            }
            else{
                string t = s + to_string(x);
                int z = stoi(t);
            return z;
            }
        }
        

        else{
            string s;
        while(x <= -10){
            int ld = -(x%10);
            s = s + to_string(ld);
            x = x/10;
        }
        int y = -stoi(s);
            if(y < INT_MIN/10){
                return 0;
            }
            else{
                string t = s + to_string(-x);
                int z = -stoi(t);
                return z;
            }
        }


    }
};