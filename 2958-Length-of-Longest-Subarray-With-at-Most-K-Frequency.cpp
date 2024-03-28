class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(), cnt=0;
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int l=0, r=0; r<n; r++){
            int x=nums[r];
            int& f=(freq.count(x)==0)?freq[x]=1:++freq[x];
            while (f>k)
                freq[nums[l++]]--;
        
            cnt=max(cnt,r-l+1);
        }
        return cnt;
    }
};