class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        
        int count = 1;
        int current = -1;
        for(auto x : rectangles) {
            int mini = min(x[0],x[1]);
            if(mini > current) {
                count = 1;
                current = mini;
            }
            else if(mini == current) {
                count++;
            }
            else {
                continue;
            }
            current = max(current,mini);
        }
        return count;
        
    }
};