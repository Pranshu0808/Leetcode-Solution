class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int chunks = 0;
        int mx = 0;

        for (int i = 0; i < v.size(); i++) {
            mx = max(mx, v[i]);
            if(mx == i){
                chunks++;
            }
        }
        return chunks;
    }
};
