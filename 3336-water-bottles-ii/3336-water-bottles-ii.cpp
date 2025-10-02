class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            numBottles++, total++, numExchange++;
        }
        return total;
    }
};