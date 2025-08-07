/*  */
class SolutionOne {
public:
    int romanToInt(string s) {
        const unordered_map<string, int> romanRep = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            string currChar(1, s[i]);
            string nextChar(1, s[i + 1]);

            const auto currIt = romanRep.find(currChar);

            if (currIt != romanRep.end()) {
                int curr = currIt->second;

                if (i + 1 < s.size()) {
                    const auto nextIt = romanRep.find(nextChar);
                    int next = nextIt->second;

                    if (curr < next && nextIt != romanRep.end()) {
                        i++;
                        result += next - curr;
                        continue;
                    }
                }


                result += curr;

            }
        }


        return result;

    }
};


/*  */
class SolutionTwo {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> romanRep = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            if(i + 1 < s.size() && romanRep.at(s[i]) < romanRep.at(s[i+1])) {
                result -= romanRep.at(s[i]);
            }
            else{
                result += romanRep.at(s[i]);
            }
        }


        return result;

    }
};