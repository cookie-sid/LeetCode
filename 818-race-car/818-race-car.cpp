class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0,0,1});
        while(!q.empty()) {
            int moves = q.front()[0];
            int pos = q.front()[1];
            int vel = q.front()[2];
            q.pop();
            if(pos == target)
                return moves;
            if (abs(pos) > 2 * target) {
                continue;
            }
            q.push({moves + 1, pos + vel, vel * 2});
            if((pos + vel > target and vel > 0) or (pos + vel < target and vel < 0))
                q.push({moves + 1, pos, vel > 0 ? -1 : 1});
        }
        return 0;
    }
};