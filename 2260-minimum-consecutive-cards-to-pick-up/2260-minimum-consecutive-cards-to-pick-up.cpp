class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> m;
        int mini = 1e9;
        for(int i = 0; i < cards.size(); i++) {
            if(m[cards[i]] == 0) {
                m[cards[i]] = i + 1;
                continue;
            }
            mini = min(i + 1 - m[cards[i]] + 1, mini);
            m[cards[i]] = i + 1;
        }
        return mini == 1e9 ? -1 : mini;
    }
};