class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int prevEndsInOne = 0, prevEndsInZero = 0;
        if(s[0] == '0') {
            prevEndsInOne = 1;
        }
        else {
            prevEndsInZero = 1;
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                prevEndsInOne = min(prevEndsInOne, prevEndsInZero) + 1;
            }
            else {
                prevEndsInOne = min(prevEndsInOne, prevEndsInZero);
                prevEndsInZero = prevEndsInZero + 1;
            }
        }
        return min(prevEndsInOne, prevEndsInZero);
    }
};