class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans,s=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<s-1;i++){
            if(nums[i]==nums[i+1])
            ans=nums[i];
        }
        return ans;
    }
};