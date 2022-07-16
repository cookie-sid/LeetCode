class Solution {
public:
    
    long long ways(int m, int n, int currMoves, int r, int c,
            map<pair<int,pair<int,int>>,long long> &mp) {
        auto p = make_pair(currMoves,make_pair(r,c));
        if(mp.find(p) != mp.end()) {
            return mp[p];
        }
        if(r < 0 or c < 0 or r >= m or c >= n) {
            return 1;
        }
        if(currMoves == 0) {
            mp[p] = 0;
            return mp[p];
        }
        int mod = 1e9 + 7;
        mp[p] += ways(m,n,currMoves-1,r+1,c,mp)%mod + ways(m,n,currMoves-1,r-1,c,mp)%mod + ways(m,n,currMoves-1,r,c+1,mp)%mod + ways(m,n,currMoves-1,r,c-1,mp)%mod;
        mp[p] %= mod;
        return mp[p];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        map<pair<int,pair<int,int>>,long long> mp;
        return ways(m,n,maxMove,startRow,startColumn,mp);
    }
};