#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
private:
    int total;
    int rows;
    int cols;
    unordered_map<int, int> map;

public:
    Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
        srand(time(0)); 
    }

    vector<int> flip() {
        int r = rand() % total;
        int x = map.find(r) != map.end() ? map[r] : r;
        map[r] = map.find(total - 1) != map.end() ? map[total - 1] : total - 1;
        total--;

        return {x / cols, x % cols};
    }

    void reset() {
        map.clear();
        total = rows * cols;
    }
};