using namespace std;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        if (basket1.size() != basket2.size()) return -1;

        long long minCost = LLONG_MAX;
        map<int, int> freqMap;
        // assuming that the previous condition of both baskets being the same size is true
        for (int i = 0; i < basket1.size(); i++) {
            freqMap[basket1[i]]++;
            freqMap[basket2[i]]--;

            minCost = min(minCost, (long long)min(basket1[i], basket2[i]));
        }


        // frequency has to be even to swap
        vector<int> costsToSwap;
        for (const auto& [cost, freq] : freqMap) {
            if (freq % 2 != 0) return -1;
            for (int i = 0; i < abs(freq / 2); i++)
                costsToSwap.push_back(cost);
        }


        long long totalCostToSwap = 0;
        for (int i = 0; i < costsToSwap.size() / 2; i++)
        {
            /*
             *  2 * minCost -> swapping both ways between the two baskets
             *  costsToSwap[i] -> direct swap betweem the baskets
             */
            totalCostToSwap += min(2 * minCost, (long long)costsToSwap[i]);
        }

        return totalCostToSwap;
    }
};