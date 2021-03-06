class Solution {
public:
    
    int recurr(vector<int> &houses, vector<vector<int>> &cost, int m, int n, 
               int currHouse, int lastSelect, int currNHs, int target, 
               map<pair<int,pair<int,int>>,int> &mm) {
        
        auto memoPair = make_pair(lastSelect,make_pair(currHouse,currNHs));
        if(mm.find(memoPair) != mm.end()) {
            return mm[memoPair];
        }
        
        if(currNHs > target or (currNHs < target and currHouse == m)) {
            mm[memoPair] = 1e9;
            return 1e9;
        }
        if(currNHs == target and currHouse == m) {
            mm[memoPair] = 0;
            return 0;
        }
        
        if(houses[currHouse] != 0) {
            if(houses[currHouse] == lastSelect) {
                mm[memoPair] = recurr(houses,cost,m,n,currHouse + 1,lastSelect,currNHs,target,mm);
                return mm[memoPair];
            }
            else {
                mm[memoPair] = recurr(houses,cost,m,n,currHouse + 1,houses[currHouse],currNHs + 1,target,mm);
                return mm[memoPair];
            }
        }
        int mini = 1e9;
        for(int i = 0; i < n; i++) {
            if(i + 1 == lastSelect) {
                mini = min(mini,cost[currHouse][i] + recurr(houses,cost,m,n,currHouse + 1,i + 1,currNHs,target,mm));
            }
            else {
                mini = min(mini,cost[currHouse][i] + recurr(houses,cost,m,n,currHouse + 1,i + 1,currNHs + 1,target,mm));
            }
        }
        
        mm[memoPair] = mini;
        return mini;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        map<pair<int,pair<int,int>>,int> mm;
        int ans = recurr(houses,cost,m,n,0,-1,0,target,mm);
        if(ans == 1e9) {
            return -1;
        }
        return ans;
    }
};