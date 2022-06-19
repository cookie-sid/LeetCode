class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans(searchWord.length());
        int start = 0, end = products.size() - 1, n = products.size() - 1;
        for(int i = 0; i < searchWord.length(); i++) {
            while(start <= n and (products[start].length() < i + 1 or products[start][i] < searchWord[i])) {
                start++;
            }
            while(end >= 0 and (products[end].length() < i + 1 or products[end][i] > searchWord[i])) {
                end--;
            }
            for(int j = start; j <= min(end,min(start + 2, (int)products.size() - 1)); j++) {
                ans[i].push_back(products[j]);
            }
        }
        return ans;
    }
};