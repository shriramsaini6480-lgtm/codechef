class Solution {
public:
    string removeUtil(string &s) {
        string result;
        int i = 0;

        while (i < static_cast<int>(s.size())) {
            int j = i + 1;

            // Find the end of the run of identical characters.
            while (j < static_cast<int>(s.size()) && s[j] == s[i]) {
                ++j;
            }

            // Keep the character only if its run had length one.
            if (j == i + 1) {
                result.push_back(s[i]);
            }

            i = j;
        }

        // Removing groups may create new adjacent duplicates.
        if (result.size() != s.size()) {
            return removeUtil(result);
        }

        return result;
    }
};