class Solution {
public:

    bool isDivisible(int num) {

        int temp = num;

        while (temp > 0) {

            int rem = temp % 10;

            if (rem == 0 || num % rem != 0) {
                return false;
            }

            temp /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> result;

        for (int i = left; i <= right; i++) {

            if (isDivisible(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};