class Solution {
public:
    static bool lemonadeChange(vector<int>& bills, int i=0, int cnt5=0, int cnt10=0) {
        if (i==bills.size()) return cnt5>=0&&cnt10>=0;// base case
        if (cnt5<0 || cnt10<0 ) return 0;
        int b=bills[i];
        if (b==5) return lemonadeChange(bills, i+1, cnt5+1, cnt10);
        if (b==10) return lemonadeChange(bills, i+1, cnt5-1, cnt10+1);
        if (b==20 && cnt10>0) return lemonadeChange(bills, i+1, cnt5-1, cnt10-1);
        else return lemonadeChange(bills, i+1, cnt5-3, cnt10);
    }
};