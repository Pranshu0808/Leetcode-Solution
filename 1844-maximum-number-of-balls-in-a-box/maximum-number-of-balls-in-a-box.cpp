class Solution {
public:
    int digitsum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(50, 0);
        int ans = INT_MIN;

        for (int i = lowLimit; i <= highLimit; i++) {
            int box = digitsum(i);
            count[box]++;
            ans = max(ans, count[box]);
        }

        return ans;
    }
};