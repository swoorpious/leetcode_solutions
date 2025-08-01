class SolutionOne {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out = {{1}};

        for (int i = 0; i < numRows; i++) {
            if (i == 0)
                continue;

            int totalNums = i + 1;
            vector<int> row = {};
            for (int j = 0; j < totalNums; j++) {
                if (j == 0 || j == totalNums - 1)
                    row.push_back(1);
                else {
                    int curr = out[i - 1][j - 1] + out[i - 1][j];
                    row.push_back(curr);
                }
            }

            out.push_back(row);
        }

        return out;
    }
};


class SolutionTwo {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};

        vector<vector<int>> currentTrig = generate(numRows - 1);
        vector<int> newRow(numRows, 1);

        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = currentTrig.back()[i - 1] + currentTrig.back()[i];
        }

        currentTrig.push_back(newRow);
        return currentTrig;
    }
};