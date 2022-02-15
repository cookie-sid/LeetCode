class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(abbr.length() > word.length())
            return false;
        int at = 0;
        for(int i = 0; i < abbr.length(); i++) {
            if(abbr[i] -'0' >= 0 and abbr[i] -'0' <= 9) {
                if(abbr[i] == '0')
                    return false;
                
                int num = 0;
                while(i < abbr.length() and abbr[i] - '0' >= 0 and abbr[i] - '0' <= 9) {
                    num *= 10;
                    num += abbr[i] - '0';
                    i++;
                }
                cout<<num<<" ";
                at += num;
                if((at < word.length() and word[at] != abbr[i]) or (at == word.length() and i != abbr.length()) or (at > word.length())) {
                    return false;
                }
                i--;
            } 
            else {
                at++;
            }
        }
        if(at != word.length())
            return false;
        return true;
    }
};