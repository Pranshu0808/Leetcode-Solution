#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r0, int c0) 
    {
        vector<vector<int>> cells;
        cells.reserve(rows * cols);
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c) 
            {
                int dist = abs(r - r0) + abs(c - c0);
                cells.push_back({dist, r, c});
            }
        }


        sort(cells.begin(), cells.end(),
             [](const vector<int>& a, const vector<int>& b) 
            {
                 return a[0] < b[0];
            });

        vector<vector<int>> result;
        result.reserve(rows * cols);
        for (auto &cell : cells) 
        {
            result.push_back({cell[1], cell[2]});
        }

        return result;
    }
};