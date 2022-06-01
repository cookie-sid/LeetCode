class Solution {//BFS
public:
    int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        vector<pair<int,int>> offsets = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // - Rather than using the inefficient HashSet, we use the bitmap
        //     otherwise we would run out of time for the test cases.
        // - We create a bitmap that is sufficient to cover all the possible
        //     inputs, according to the description of the problem.
        vector<vector<bool>> vis(608, vector<bool> (608));

        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        int steps = 0;

        while (q.size() > 0) {
            int currLevelSize = q.size();
            // iterate through the current level
            for (int i = 0; i < currLevelSize; i++) {
                pair<int,int> curr = q.front();
                q.pop();
                if (curr.first == x and curr.second == y) {
                    return steps;
                }

                for (auto offset: offsets) {
                    pair<int,int> next = make_pair(curr.first + offset.first, curr.second + offset.second);
                    // align the coordinate to the bitmap
                    if (!vis[next.first + 302][next.second + 302]) {
                        vis[next.first + 302][next.second + 302] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        // move on to the next level
        return steps;
    }
};