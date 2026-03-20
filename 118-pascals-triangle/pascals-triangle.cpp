class Solution {
public:
    vector<vector<int>> generate(int numrow) {
               vector<vector<int>> ans;
               
               for(int i = 1; i <= numrow; ++i){
                long long ele = 1;
                    vector<int> row;
                    row.push_back(1);
                    for(int col = 1; col < i; ++col){
                        ele = ele*(i-col);
                        ele = ele/ col;
                        row.push_back(ele);
                    }
                    ans.push_back(row);
               }
               return ans;
    }
};