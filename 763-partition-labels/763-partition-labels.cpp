class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> firstIndex(26,-1), lastIndex(26,-1);
        for(int i = 0; i < s.length(); i++) {
            char x = s[i];
            if(firstIndex[x - 'a'] == -1)
                firstIndex[x - 'a'] = i;
            lastIndex[x - 'a'] = i;
        }
        vector<int> res;
        int currEndIndex = -1, prevEndIndex = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                currEndIndex = lastIndex[s[i] - 'a'];
            }
            else {
                if(i > currEndIndex) {
                    res.push_back(currEndIndex - prevEndIndex + 1);
                    prevEndIndex = currEndIndex + 1;
                    currEndIndex = lastIndex[s[i] - 'a'];
                    continue;
                }
                if(currEndIndex < lastIndex[s[i] - 'a'])
                    currEndIndex = lastIndex[s[i] - 'a'];
            }
        }
        res.push_back(currEndIndex - prevEndIndex + 1);
        return res;
    }
};