// this problem is so dumb idek why i solved it IT WAS ALREADY SOLVED ITSELF
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        int pos = 0;

        for (auto& num : nums) {
            if (num > 0) pos++;
            if (num < 0) neg++;
        }

        return max(neg, pos);
    }
};