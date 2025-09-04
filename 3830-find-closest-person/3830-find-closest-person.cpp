class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(z-x), y = abs(z-y);
        return x==y ? 0 : (x<y ? 1 : 2);
    }
};