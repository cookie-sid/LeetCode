class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,pair<int,int>> m;
        for(auto x : words) {
            string tmp = x;
            reverse(tmp.begin(),tmp.end());
            if(m.find(x) != m.end()) {
                m[x].first += 1;
            }
            else if(m.find(tmp) != m.end()) {
                m[tmp].second += 1;
            }
            else {
                m[x].first += 1;
            }
        }
        bool selected = false;
        int ans = 0;
        for(auto x : m) {
            if(x.first[0] == x.first[1]) {
                int oneVal = max(x.second.first,x.second.second);
                if(oneVal%2 == 1 and !selected) {
                    ans += 2;
                    selected = true;
                }
                ans += (oneVal - oneVal%2) * 2;
            }
            else {
                int maxi = min(x.second.second,x.second.first);
                ans += maxi * 2 * 2;
            }
        }
        return ans;
    }
};