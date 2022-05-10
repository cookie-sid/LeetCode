class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> endsInOne(n), endsInZero(n);
        if(s[0] == '0') {
            endsInOne[0] = 1;
        }
        else {
            endsInZero[0] = 1;
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                endsInOne[i] = min(endsInOne[i-1], endsInZero[i-1]) + 1;
                endsInZero[i] = endsInZero[i-1];
            }
            else {
                endsInOne[i] = min(endsInOne[i-1], endsInZero[i-1]);
                endsInZero[i] = endsInZero[i-1] + 1;
            }
        }
        return min(endsInOne[n-1], endsInZero[n-1]);
    }
};