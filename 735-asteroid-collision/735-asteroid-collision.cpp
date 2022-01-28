class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int start = 0;
        vector<int> ans;
        stack<int> res;
        while(start < asteroids.size()) {
            while(start < asteroids.size() and asteroids[start] < 0) {
                if(!res.empty() and res.top() > 0) {
                    if(abs(res.top()) > abs(asteroids[start])) {
                        start++;
                        continue;
                    }
                    else if(abs(res.top()) == abs(asteroids[start])) {
                        res.pop();
                        start++;
                        continue;
                    }
                    else {
                        res.pop();
                        continue;
                    }
                }
                res.push(asteroids[start]);
                start++;
            }
            while(start < asteroids.size() and asteroids[start] > 0) {
                res.push(asteroids[start]);
                start++;
            }
        }
        while(!res.empty()) {
            ans.push_back(res.top());
            res.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};