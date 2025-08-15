class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return 0;

        // https://www.geeksforgeeks.org/dsa/find-significant-set-bit-number/
        // https://en.cppreference.com/w/cpp/numeric/countl_zero.html
        // https://stackoverflow.com/questions/76729428/how-to-make-a-countl-zero-but-for-any-type
        int exp = 31 - countl_zero((unsigned)n); // log2(n)
        return (exp & 1) == 0 && n == 1 << exp;
    }
};