class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i = 0; i < colors.length(); i++) {
            int curr = i, next = i + 1;
            int add = neededTime[curr], total = neededTime[curr];
            while(next < colors.length() and colors[curr] == colors[next]) {
                add = max(neededTime[curr],max(add,neededTime[next]));
                total += neededTime[next];
                next += 1;
                curr += 1;
            }
            ans += total - add;
            i = curr;
        }
        return ans;
    }
};