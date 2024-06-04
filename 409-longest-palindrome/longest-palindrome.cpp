class Solution {
public:
    static int longestPalindrome(string& s) {
        bitset<58> freq=0; 
        for(char c: s)
            freq.flip(c-'A');
        int len=s.size();
        for(int i=0; i<58; i++){
            if (freq[i]) len--;
        }
        return len+(freq.count()>=1);
    }
};
