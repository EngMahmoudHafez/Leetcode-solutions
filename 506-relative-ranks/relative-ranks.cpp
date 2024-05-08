class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector <pair<int,int>>pairs ;
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            pairs.push_back({score[i],i});
        }
        sort(pairs.begin(),pairs.end(),greater<pair<int,int>>());
        for(int i=0;i<n;i++) {
            if(i==0)ans[pairs[i].second]="Gold Medal";
            else if(i==1)ans[pairs[i].second]="Silver Medal";
            else if(i==2)ans[pairs[i].second]="Bronze Medal";
            else ans[pairs[i].second] = to_string(i+1);
        }
        return ans;
    }
};