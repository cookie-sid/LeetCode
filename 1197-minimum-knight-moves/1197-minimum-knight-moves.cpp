class Solution {//BFS
public:
    int minKnightMoves(int x, int y) {      
        x = abs(x), y = abs(y);
        queue<pair<int, int> > q{{{0,0}}};
        unordered_set<int> seen{0};        
        const int LIMIT = 2*(abs(x)+abs(y))+1;        
        vector<vector<int> > dirs{{-2, 1}, {-1,2}, {1,2}, {2, 1}, {2,-1}, {1,-2}, {-1, -2}, {-2, -1}};
        for(int step = 0; !q.empty(); step++)
            for(auto sz = q.size(); sz > 0; sz--){
                const auto [i, j] = q.front(); q.pop();
                if(i == y && j == x ) return step;
                for(const auto& dir: dirs){
                    int ni = i + dir[0], nj = j + dir[1];
                    if(ni < -1 || ni > y + 2 || nj < -1 || nj > x + 2 || seen.count(ni*LIMIT+nj)) continue;                    
                    q.emplace(ni, nj);
                    seen.insert(ni*LIMIT+nj);                    
                }
            }
        return -1;
    }
};