class Solution {
public:
    int numberOfBeams(vector<string>& v) {
        vector<int> v1;
    for(int i = 0; i < v.size(); ++i){
        int ct =0;
        for(int j = 0; j < v[0].size(); ++j){
        if(v[i][j] == '1'){
            ct++;
        }}
        if(ct==0){
            continue;
        }
        else {
            v1.push_back(ct);
        }
        
    
    }
        if(v1.size() == 0){
            return 0;
        }
        else{
            int sum = 0;
        for(int i = 0; i < v1.size()-1; ++i){
                sum = sum + (v1[i+1]*v1[i]);
        }
         
            return sum;
        }
        

            
    }
};