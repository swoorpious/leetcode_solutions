/*
 *  uses basic logic (not that the other one is any harder)
 */
class SolutionOne {
public:
    int numOfUnplacedFruits(vector<int>& fruits /* quantity of fruits */, vector<int>& baskets) {
        int range = baskets.size();

        for (const auto& fruit : fruits) {
            for (auto& basket : baskets) {
                if (fruit <= basket) {
                    range--;
                    basket = -1;
                    break;
                }
            }
        }

        return range;
    }
};



class SolutionTwo {
public:
    int numOfUnplacedFruits(vector<int>& fruits /* quantity of fruits */, vector<int>& baskets) {
        int range = baskets.size();
        vector<bool> isUsed(range, false);
        int count = 0;

        for (int i = 0; i < range; i++) {
            bool placed = false;

            for (int j = 0; j < range; j++) {
                if (!isUsed[j] && fruits[i] <= baskets[j]) {
                    isUsed[j] = true;
                    placed = true;
                    break;
                }
            }

            if (!placed) count++;
        }

        return count;
    }
};