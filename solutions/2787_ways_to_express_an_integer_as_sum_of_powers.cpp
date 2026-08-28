static const int modulo = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int n, int x) {

        vector<int> powers;
        for (int i = 1; ; i++) {
           long long pow = 1;
           for (int j = 0; j < x; j++) p *= i;

           if (pow > n) break;
           powers.push_back((int)p);
        }

        /*  */
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            /* bottom up */
            for (int j = n; j >= p; j--) {
                dp[j] = (dp[j] + dp[j - p]) % (const int)modulo;
            }
        }


        return (int)dp[n];
    }

};