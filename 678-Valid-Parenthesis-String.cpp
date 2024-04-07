class Solution {
public:
    bool checkValidString(string s) {
        int Min = 0, Max = 0;

        for (char c : s) {
            if (c == '(') {
                Min++;
                Max++;
            } else if (c == ')') {
                Min--;
                Max--;
            } else {
                Min--;
                Max++;
            }
            if (Max < 0) return false;
            if (Min < 0) Min = 0;
        }
        
        return Min == 0;
    }
};