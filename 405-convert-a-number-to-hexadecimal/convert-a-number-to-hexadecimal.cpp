class Solution {
public:
    string toHex(int num){
        if (num == 0) return "0";
        
        unsigned int n = (unsigned int) num; 
        string hexChars = "0123456789abcdef";
        string result = "";
        
        while(n > 0){
            int digit = n & 15;  
            result.push_back(hexChars[digit]);
            n >>= 4;             
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
