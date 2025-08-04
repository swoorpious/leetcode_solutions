// approach using window sliding algorithm
// i wrote another Solution earlier using baskets logic but don't have the courage to put it here anymore
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() <= 2) return fruits.size();

        unordered_map<int /* fruit type */, int /* frequency */> freqMap;

        int left = 0, maxPick = 0;

        for (int i = 0; i < fruits.size(); i++) {
            freqMap[fruits[i]]++;

            if (freqMap.size() > 2) {
                freqMap[fruits[left]]--;
                if (freqMap[fruits[left]] == 0) freqMap.erase(fruits[left]);
                left++;
            }

            maxPick = max(maxPick, i - left + 1);
        }


        return maxPick;
    }
};