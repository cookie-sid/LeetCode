class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1);
        set<int> s;
        int temp = 1;
        while(temp <= 100000) {
            s.insert(temp);
            temp *= 2;
        }
        
        count[0] = 0;
        int start = 0;
        for(int i = 1; i <= n; i++) {
            if(s.count(i) == 1) {
                start = 0;
            }
            count[i] = 1 + count[start];
            start++;
        }
        
        return count;
    }
};