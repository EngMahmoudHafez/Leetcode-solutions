class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> num(s.begin(),s.end());
        int c=-1;
        for(int i=0; i<num.size(); i++){
            if (num[i]<0){
                num[i]*=-1;
            }
        }
        map<int,int> m;
        for(int i:num){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>1 && i.first>c){
                c=i.first;
            }
        }
        return c;
    }
};