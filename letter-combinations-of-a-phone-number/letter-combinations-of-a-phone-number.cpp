class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> temp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> ans;
        for(int i = 0; i < digits.length(); i++) {
            int curr = digits[i] - '0';
            cout<<curr<<" ";
            if(ans.size() == 0) {
                for(auto x : temp[curr]) {
                    string temp = "";
                    temp += x;
                    ans.push_back(temp);
                }
            }
            else {
                vector<string> newans;
                for(auto x : ans) {
                    for(auto y : temp[curr])
                        newans.push_back(x + y);
                }
                ans = newans;
            }
        }
        return ans;
    }
};