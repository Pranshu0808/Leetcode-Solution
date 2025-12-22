class Solution {
public:
    int twoEggDrop(int n) {
        int sum = 0;
        int moves = 0;

        while (sum < n) {
            moves++;
            sum += moves;
        }

        return moves;
    }
};