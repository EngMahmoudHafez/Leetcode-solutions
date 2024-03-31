class Solution {
public:
    long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minI = -1, maxI = -1, left = -1, right = 0;
        long count = 0;
        
        while (right < nums.size()) {
            if (nums[right] < minK || nums[right] > maxK) {
                minI = right;
                maxI = right;
                left = right;
            }
            
            minI = (nums[right] == minK) ? right : minI;
            maxI = (nums[right] == maxK) ? right : maxI;
            
            count += min(minI, maxI) - left;
            right++;
        }
        
        return count;
    }
};