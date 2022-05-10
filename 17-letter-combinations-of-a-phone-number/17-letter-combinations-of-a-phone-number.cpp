class Solution {
public:
    
    vector<string> book = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void recurr(string &digits, int currInd, string &currStr, vector<string> &ans) {
        if(currInd >= digits.length()) {
            ans.push_back(currStr);
            return;
        }
        int temp = digits[currInd] - '0';
        for(int i = 0; i < book[temp].length(); i++) {
            currStr += book[temp][i];
            recurr(digits,currInd + 1,currStr,ans);
            currStr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) {
            return {};
        }
        
        vector<string> ans;
        string blank = "";
        recurr(digits,0,blank,ans);
        return ans;
    }
};