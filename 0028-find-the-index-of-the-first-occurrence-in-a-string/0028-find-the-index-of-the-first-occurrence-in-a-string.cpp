class Solution {
public:
    int strStr(const string &haystack, const string &needle) {
        size_t pos = haystack.find(needle);
        if (pos != string::npos) return static_cast<int>(pos);
        return -1; // If the needle is not found
    }
};