class Solution {
public:
    int racecar(int target) {
        long long t = target;
        queue<vector<long long>> q;
        q.push({0,0,1});
        while(!q.empty()) {
            long long moves = q.front()[0];
            long long pos = q.front()[1];
            long long vel = q.front()[2];
            q.pop();
            if(pos == t)
                return moves;
            // if (abs(pos) > 2 * target) {
            //     continue;
            // }
            q.push({moves + 1, pos + vel, vel * 2});
            if((pos + vel > target and vel > 0) or (pos + vel < target and vel < 0))
                q.push({moves + 1, pos, vel > 0 ? -1 : 1});
        }
        return 0;
    }
};