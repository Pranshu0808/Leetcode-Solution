#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestArea = 0;
        int bestDiagSq = 0;  

        for (auto &rect : dimensions) {
            int L = rect[0], W = rect[1];
            int diagSq = L * L + W * W;
            int area = L * W;

            if (diagSq > bestDiagSq) {
                bestDiagSq = diagSq;
                bestArea = area;
            } else if (diagSq == bestDiagSq) {
                bestArea = max(bestArea, area);
            }
        }
        return bestArea;
    }
};
