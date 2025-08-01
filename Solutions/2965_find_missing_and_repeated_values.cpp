/*
 *  runtime: 0ms (27ms leetcode evaluation)
*/
class SolutionOne {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        std::map<int /* num */, int /* frequency */> range;
        int repeatedNum = -1;
        int missingNum = -1;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int num = grid[i][j];
                range[num]++;
            }
        }

        for (int i = 1; i <= pow(grid.size(), 2); i++) {
            if (range.find(i) == range.end())
                missingNum = i;
            else if (range[i] > 1)
                repeatedNum = i;
        }

        return { repeatedNum, missingNum };
    }
};



/*
 *  runtime: 0ms (3ms leetcode evaluation)
*/
class SolutionTwo {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeatedNum = -1;
        int missingNum = -1;

        vector<int> count(n*n + 1, 0);
        vector<int> out;

        for (const auto& i : grid) {
            for (int j : i) {
                count[j]++;
            }
        }

        for (int i = 1; i <= n*n; i++) {
            if (count[i] > 1) repeatedNum = i;
            if (count[i] == 0) missingNum = i;
        }

        out.push_back(repeatedNum);
        out.push_back(missingNum);
        return out;
    }
};