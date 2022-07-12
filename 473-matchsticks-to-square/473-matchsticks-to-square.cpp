class Solution {
public:
    
    int calls = 0;
    
    bool check(vector<int> &matchsticks, vector<int> &boxes, int ind, int maxPerBox, int done, map<vector<int>,int> &dp) {
        calls += 1;
        // for(auto x : boxes) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        if(ind == (int)matchsticks.size()) {
            vector<int> temp = boxes;
            sort(temp.begin(),temp.end());
            if(boxes[0] == boxes[1] and boxes[0] == boxes[2] and boxes[0] == boxes[3]) {
                dp[temp] = 1;
            }
            else {
                dp[temp] = -1;
            }
            
            return boxes[0] == boxes[1] and boxes[0] == boxes[2] and boxes[0] == boxes[3];
        }
        // cout<<boxes[0]<<" "<<boxes[1]<<" "<<boxes[2]<<" "<<boxes[3]<<endl;
        bool ans = false;
        vector<int> temp = boxes;
        sort(temp.begin(),temp.end());
        if(dp[temp] != 0) {
            return dp[temp] == 1;
        }
        for(int i = 0; i < 4 and !ans; i++) {
            boxes[i] += matchsticks[ind];
            if(boxes[i] > maxPerBox) {
                boxes[i] -= matchsticks[ind];
                continue;
            }
            ans = ans or check(matchsticks,boxes,ind+1,maxPerBox,done+matchsticks[ind],dp);
            boxes[i] -= matchsticks[ind];
        }
        dp[temp] = ans ? 1 : -1;
        return ans;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        for(auto x : matchsticks) {
            total += x;
        }
        if(total % 4 != 0) {
            return false;
        }
        vector<int> boxes(4);
        int count = 0;
        map<vector<int>,int> m;
        sort(matchsticks.rbegin(),matchsticks.rend());
        boxes[0] += matchsticks[0];
        bool ans = check(matchsticks,boxes,1,total/4,count,m);
        cout<<calls<<endl;
        return ans;
    }
};