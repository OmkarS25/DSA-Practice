#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class MyCalendar {
public:
    map<int, int> intervals; 
    MyCalendar() {}
    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); 
        if (next != intervals.end() && next->first < end) return false; 
        if (next != intervals.begin() && prev(next)->second > start) return false; 
        intervals[start] = end;
        return true;
    }
};

// class MyCalendar {
// public:
//     vector<pair<int, int>> ranges;
//     MyCalendar() {}
//     bool book(int start, int end) {
//         for (auto const& pair : ranges) {
//             if (start < pair.second && end > pair.first) return false;
//         }
//         ranges.push_back(make_pair(start, end));
//         return true;
//     }
// };