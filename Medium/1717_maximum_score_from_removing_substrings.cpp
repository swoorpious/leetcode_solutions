/* pair<int - score, string - substring> */

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        // ab -> x
        // ba -> y
        string highPair = x > y ? "ab" : "ba";
        string lowPair = x > y ? "ba" : "ab";
        int highScore = max(x, y);
        int lowScore = min(x, y);

        auto [hpScore, hpStr] = removeSubstring(s, highPair, highScore); // remove high priority substrings
        score += hpScore;

        auto [lpScore, _] = removeSubstring(hpStr, lowPair, lowScore); // remove low priority substrings
        score += lpScore;

        return score;

    }


private:

    pair<int, string> removeSubstring(const string& s, const string& subStr, int score) {
        int finalScore = 0;
        string stack;

        for (char c : s) {
            if (!stack.empty() && stack.back() == subStr[0] && c == subStr[1]) {
                stack.pop_back();
                finalScore += score;
            }
            else
                stack.push_back(c);

        }

        return {finalScore, stack};

    }


};