class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> diffs;
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(heights[i] > heights[i-1]) {
                diffs.push(-(heights[i] - heights[i-1]));
                if(ladders) {
                    ladders--;
                }
                else {
                    int top = -diffs.top();
                    if(bricks < top) {
                        break;
                    }
                    else {
                        bricks -= top;
                        diffs.pop();
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};