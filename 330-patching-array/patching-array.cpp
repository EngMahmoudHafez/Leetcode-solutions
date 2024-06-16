class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int nn=nums.size();int i=0;int c=0;long long p=0;
        while(p<n){
            if ((i < nn) && (p+1 >= nums[i])){
                p+=nums[i];
                i++;
            }else{
                c++;p+=(p+1);
            }
        }
        return c;
    }
};