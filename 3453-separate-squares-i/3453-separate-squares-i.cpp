class Solution {
public:
    double helper(const vector<vector<int>> &sq, double Y) {
        double area = 0;
        for (const auto& s : sq) {
            int x = s[0], y = s[1], l = s[2];
            if (y>=Y) area += 1.0*l*l; // Entire square is above Y
            else if (y+l>Y) area += (y+l-Y)*l; // Partial overlap above Y
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& sq) {
        double total = 0, low = 0, high = 0;
        for (const auto& s : sq) {
            total += 1.0 * s[2] * s[2];
            high = max(high, static_cast<double>(s[1] + s[2]));
        }

        // Binary search for the dividing line
        while (high - low > 1e-5) {
            double mid = (low + high) / 2.0;
            double areaAbove = helper(sq, mid);
            if (areaAbove > total/2.0) low = mid;   // line must go higher
            else high = mid;  // line must go lower
        }
        return high;
    }
};
