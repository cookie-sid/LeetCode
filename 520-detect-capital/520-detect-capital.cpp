class Solution {
public:
    bool detectCapitalUse(string word) {
        bool valid = true, firstcapital = false, allcapital = true, otherthanfirst = false, alllower = true;
        for(int i = 0; i < word.length(); i++) {
            if(i == 0) {
                if(word[i] - 'A' >= 0 and word[i] - 'A' <= 25) {
                    firstcapital = true;
                    alllower = false;
                }
                else {
                    allcapital = false;
                }
            }
            else {
                if(!(word[i] - 'A' >= 0 and word[i] - 'A' <= 25)) {
                    allcapital = false;
                }
                else {
                    alllower = false;
                    otherthanfirst = true;
                }
            }
        }
        if(alllower or (firstcapital and !otherthanfirst) or (allcapital)) {
            return true;
        }
        return false;
    }
};