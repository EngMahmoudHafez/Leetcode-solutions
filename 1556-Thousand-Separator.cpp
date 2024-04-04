class Solution {
public:
    string thousandSeparator(int n) {
        string ans = to_string(n);
        if (ans.size() <= 3) return ans;
        for(int i=ans.size();i>=1;i=i-3)
        {
            if(i==ans.size())continue;
            else ans.insert(i, ".");
        }
        return ans;
    }
};