class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        int ans = 0;
        for(auto x : answers) {
            if(x == 0) {
                ans += 1;
                continue;
            }
            if(m[x] == 0) {
                ans += x + 1;
                m[x] = 1;
            }
            else {
                if(m[x] < x + 1) {
                    m[x] += 1;
                }
                else {
                    m[x] = 1;
                    ans += x + 1;
                }
            }
        }
        return ans;
    }
};