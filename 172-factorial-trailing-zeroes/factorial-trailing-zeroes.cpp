class Solution {
public:
    int trailingZeroes(int n) {
        int count_zero = 0;
        int i = 5;
        while(i <= n) {
            count_zero += n / i;
            i =i*5;
        }
    return count_zero;
        
    }
};