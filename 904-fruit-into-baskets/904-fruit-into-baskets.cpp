class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        if(fruits.size() == 1) {
            return 1;
        }
        
        int ans = 1, start = 0;
        unordered_map<int,int> rightMost;
        rightMost[fruits[0]] = 1;
        
        for(int i = 1; i < fruits.size(); i++) {
            rightMost[fruits[i]] = i + 1;
            if(rightMost.size() <= 2) {
                ans = max(ans,i - start + 1);
            }
            else {
                int mini = 1e9, val = -1;
                for(auto x : rightMost) {
                    if(mini > x.second and x.second != 0) {
                        mini = x.second;
                        val = x.first;
                    }
                }
                start = mini;
                rightMost.erase(val);
                ans = max(ans,i - start + 1);
            }
        }
        return ans;
    }
};