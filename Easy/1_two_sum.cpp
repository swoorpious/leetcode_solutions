class Solution {
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