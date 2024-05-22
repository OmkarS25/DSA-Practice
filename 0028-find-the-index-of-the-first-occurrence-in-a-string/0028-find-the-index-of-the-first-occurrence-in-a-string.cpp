class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle)
            return 0;
        if (needle.length() == 1) {
            for (int i = 0; i <= haystack.length() - 1; i++) {
                if (haystack[i] == needle[0])
                    return i;
            }
            return -1;
        }
        for (int i = 0, j = needle.length(); i < haystack.length() - 1;
             i++, j + needle.length()) {
            if (haystack.substr(i, j) == needle)
                return i;
        }
        return -1;
    }
    // int strStr(const string &haystack, const string &needle) {
    //     size_t pos = haystack.find(needle);
    //     if (pos != string::npos) return static_cast<int>(pos);
    //     return -1; // If the needle is not found
    // }
};