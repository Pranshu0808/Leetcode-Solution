


class Solution {
public:
    string removeKdigits(string num, int k){
        string res = "";
        for(int i = 0 ; i < num.size(); ++i){
            
            while(!res.empty() && ((res.back() - '0') >  ( num[i] - '0' )) && k > 0){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
         while(( k > 0) && !res.empty()){
            res.pop_back();
            k--;
        }
        if(res.empty()){
            return "0";
        }
        else{
            while(res.size() > 1 && res[0] == '0'){
                res.erase(res.begin());
            }
            if(res.empty()){
                return "0";
            }
            else{
                return res;
            }
        }
        // stack<char> s;
        // for(int i = 0 ; i < num.size(); ++i){
        //     while(!s.empty() && k > 0 && (s.top() - '0' ) > ( num[i] - '0' )){
        //         s.pop();
        //         k = k -1; 
        //     }
        //     s.push(num[i]);
        // }
        // while( k > 0){
        //     s.pop();
        //     k--;
        // }
        // if(s.empty()){
        //     return "0";
        // }
        // else{
        //     res = "";
        //     while(!s.empty()){
        //         res = res + s.top();
        //         s.pop();
        //     }
        //     while(res.size() != 0 && res.back() == '0'){
        //         res.pop_back();
        //     }
        //     reverse(res.begin() , res.end());
        //     if(res.empty()){
        //         return "0";
        //     }
        //     else{
        //         return num;
        //     }
        // }
        
    }
};