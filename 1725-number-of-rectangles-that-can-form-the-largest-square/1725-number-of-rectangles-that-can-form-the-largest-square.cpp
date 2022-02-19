class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> squares;
        int count = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            int minim = INT_MAX;
            for (int j = 0; j < 2; j++) {
                minim = min(minim, rectangles[i][j]);
            }
            squares.push_back(minim);
        }
        int maxi = *max_element(squares.begin(), squares.end());
        for (auto x : squares) {
            if (x == maxi)
                count++;
        }
        return count;
    }
};