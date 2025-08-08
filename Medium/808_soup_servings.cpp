#define SIZE 256

class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1;

        double dat[SIZE][SIZE];
        fill(&dat[0][0], &dat[0][0] + SIZE*SIZE, -1);

        function<double(int, int)> calc = [&](int i, int j) -> double {
            if (i <= 0 && j > 0) return 1;
            if (i <= 0 && j <= 0) return 0.5;
            if (i > 0 && j <= 0) return 0;
            if (dat[i][j] != -1) return dat[i][j];

            double out = 0.25f * (
                calc(i - 4, j) +
                calc(i - 3, j - 1) +
                calc(i - 2, j - 2) +
                calc(i - 1, j - 3)
            );

            return dat[i][j] = out;
        };

        int _n = ceil(n / 25.0f);

        return calc(_n, _n);
    }
};