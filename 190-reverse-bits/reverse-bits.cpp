class Solution {
public:
    uint32_t reverseBits(uint32_t n, int bits = 32) {
        if (bits == 0) return 0;
        return ((n & 1) << (bits - 1)) | reverseBits(n >> 1, bits - 1);
    }
};
