class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k %= n;
        
        if(n == 1 or k == 0) {
            return;
        }
        
        int current = nums[0], next = k, swapsDone = 0, currentIndex = 0;
        while(swapsDone < n and currentIndex < k) {
            int elementToBePlaced = -1;
            while(next != currentIndex) {
                elementToBePlaced = nums[next];
                nums[next] = current;
                current = elementToBePlaced;
                next += k;
                next %= n;
                swapsDone++;
                if(swapsDone == n) {
                    return;
                } 
            }
            nums[next] = current;
            swapsDone++;
            current = nums[currentIndex + 1];
            currentIndex += 1;
            next = currentIndex + k;
            next %= n;
        }
    }
};