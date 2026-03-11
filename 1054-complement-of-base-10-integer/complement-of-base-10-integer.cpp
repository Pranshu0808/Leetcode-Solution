// variant
class Solution {
public:
    int bitwiseComplement(int n) {
        return ~n & (bit_floor(2u*(n |1))-1);
    }
};