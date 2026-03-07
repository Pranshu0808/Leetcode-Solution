class Solution {
public:
    bool rotateString(string s, string goal){
        string temp = s;
        for(int i = 0; i < s.size()+1; ++i){
            
            rotate(s.rbegin() , s.rbegin()+i , s.rend());
            
            if(s == goal){
                return true;
            }
            s = temp;
        }

        return false;
        
    }
};