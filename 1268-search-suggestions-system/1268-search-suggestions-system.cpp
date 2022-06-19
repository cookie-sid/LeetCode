class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,set<string>> m;
        for(int i = 0; i < products.size(); i++) {
            for(int j = 1; j < products[i].length() + 1; j++) {
                m[products[i].substr(0,j)].insert(products[i]);
            }
        }
        
        vector<vector<string>> ans(searchWord.length());
        for(int i = 0; i < searchWord.length(); i++) {
            int ct = 0;
            for(auto x : m[searchWord.substr(0,i + 1)]) {
                ans[i].push_back(x);
                ct++;
                if(ct == 3)
                    break;
            }
        }
        return ans;
    }
};