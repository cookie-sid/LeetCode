class Solution {
public:
    
    vector<string> book = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        for(int i = 0; i < digits.length(); i++) {
            
            
            int currsize = ans.size();
            vector<string> tmp;
            for(int j = 0; j < book[digits[i] - '0'].length(); j++) {
                
                if(currsize == 0) {
                    string temp = "";
                    tmp.push_back(temp + book[digits[i] - '0'][j]);
                }
                else {
                    for(int k = 0; k < currsize; k++) {
                        tmp.push_back(ans[k] + book[digits[i] - '0'][j]);
                    }
                }
                
            }
            ans = tmp;
            
        }
        return ans;
    }
};