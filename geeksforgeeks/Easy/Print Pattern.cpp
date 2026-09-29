class Solution {
public:
    vector<int> pattern(int n) {
        if (n <= 0) {
            return {n};
        }

        vector<int> result = pattern(n - 5);
        result.insert(result.begin(), n);
        result.push_back(n);

        return result;
    }
};