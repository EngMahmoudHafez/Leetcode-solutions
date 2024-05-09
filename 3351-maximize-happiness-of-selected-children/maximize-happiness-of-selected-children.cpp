class Solution {
public:
      long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());

        vector<bool> selected(happiness.size(), false);

        long long ans = 0;
        int count = 0;

        for (int i = 0; i < happiness.size(); ++i) {
            if (!selected[i]) {
                ans += max(0, happiness[i] - count);
                ++count;
                selected[i] = true;

                if (count >= k) {
                    break;
                }
            }
        }

        return ans;
    }
};