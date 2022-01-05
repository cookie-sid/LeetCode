class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int bestproduct = -11;
        int maxi_indvalue = -11;
        for(int i = 0; i < nums.size(); i++) {
            int product = 1, negatives = 0, lastnegprod = 1, l_index = -1, firstnegprod = 1;
            while(i < nums.size() and nums[i] != 0) {
                maxi_indvalue = max(maxi_indvalue,nums[i]);
                product *= nums[i];
                lastnegprod *= nums[i];
                if(nums[i] < 0) {
                    l_index = i;
                    negatives++;
                    lastnegprod = nums[i];
                }
                if(firstnegprod > 0) {
                    firstnegprod *= nums[i];
                }
                bestproduct = max(bestproduct,max(product,nums[i]));
                i++;
            }
            if(i < nums.size()) {
                bestproduct = max(bestproduct,0);
            }
            if(negatives % 2 == 0) {
                if(negatives == 0)
                    continue;
                bestproduct = max(bestproduct,product);
            }
            else {
                if(negatives == 1 and product == nums[l_index]) {
                    continue;
                }
                bestproduct = max(bestproduct,max(product/firstnegprod,product/lastnegprod));
            }
        }
        return bestproduct;
    }
};