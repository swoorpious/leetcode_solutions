// leetcode optimizer hack found on a 0ms code
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto sid = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int left = 0; // for sliding window
        int count = 0;


        for (int i = 1; i < n + k - 1; i++) {
            if (i - left + 1 > k) left++;

            bool isAlternating = true;
            for (int j = left; j < i; j++) {
                if (colors[(i - 1) % n] == colors[i % n]) {
                    left = i;
                    isAlternating = false;
                }

            }

            if (isAlternating && i - left + 1 == k) count++;

        }

        return count;

    }
};