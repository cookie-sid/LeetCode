class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = -1, start = 0, end = height.size() - 1;
        while(start < end) {
            maxi = max(maxi, (end - start) * min(height[start],height[end]));
            if(height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }
        return maxi;
    }
};