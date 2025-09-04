class Solution {
public:
    int findClosest(int& _x, int& _y, int& _z) {
        int x = abs(_z-_x), y = abs(_z-_y);
        return x==y ? 0 : (x<y ? 1 : 2);
    }
};