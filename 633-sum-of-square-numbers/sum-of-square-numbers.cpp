class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start=0;long long end=sqrt(c);

        while(start<=end){
            long long ans=start*start+end*end;
            cout<<ans<<"="<<start*start<<" "<<end*end<<"\n";
            if(c==ans)
                return true;
            else if(c<ans)
                end--;
            else
                start++;
            
        }
    return false;
    }
};