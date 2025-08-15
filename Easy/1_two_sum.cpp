class SolutionOne {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int /* val */, int /* index */> freqMap;
        vector<int> res(2, 0);

        for (int i = 0; i < nums.size(); i++) {
            const auto it = freqMap.find(target - nums[i]);

            if (it != freqMap.end())
            {
                res[0] = it->second;
                res[1] = i;
            }

            else freqMap[nums[i]] = i;
        }

        return res;
    }
};


/* given that each case will have one solution defined */
class SolutionTwo {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int /* val */, int /* index */> freqMap;

        for (int i = 0; i < nums.size(); i++) {
            if (freqMap.find(target - nums[i]) != freqMap.end())
                return {freqMap[target - nums[i]], i};


            freqMap[nums[i]] = i;
        }

        return {};
    }
};