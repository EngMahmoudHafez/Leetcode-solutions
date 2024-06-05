class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minCount(26, INT_MAX);
        for (auto& word : words) {
            vector<int> count(26, 0);
            for (auto& c : word) count[c - 'a']++;
            for (int c = 0; c < 26; c++) minCount[c] = min(minCount[c], count[c]);
        }
        vector<string> result;
        for (int c = 0; c < 26; c++) {
            for (int i = 0; i < minCount[c]; i++) result.push_back(string(1, 'a' + c));
        }
        return result;
    }
};