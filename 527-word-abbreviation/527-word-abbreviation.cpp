class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string,int> m;
        int n = words.size();
        unordered_map<string,bool> pres; 
        for(int i = 0; i < n; i++) {
            int l = words[i].length();
            for(int j = words[i].length() - 4; j >= 0; j--) {
                m[words[i].substr(0,j + 1) + "|" + to_string(l - 1 - (j + 1)) + "|" + words[i][l-1]]++;
            }
        }
        vector<string> ans;
        for(int i = 0; i < n; i++) {
            if(words[i].length() <= 3) {
                ans.push_back(words[i]);
                pres[words[i]] = true;
            }
            else {
                int charsBetween = words[i].length() - 1;
                string test = "";
                int l = words[i].length();
                bool done = false;
                for(int j = 0; j < l and charsBetween > 2 and !done; j++) {
                    test += words[i][j];
                    charsBetween--;
                    if(m[test + "|" + to_string(l - 1 - test.length()) + "|" + words[i][l-1]] > 1) {
                        continue;
                    }
                    else {
                        if(pres[test + to_string(charsBetween) + words[i][l-1]]) {
                            continue;
                        }
                        else {
                            pres[test + to_string(charsBetween) + words[i][l-1]] = true;
                            ans.push_back(test + to_string(charsBetween) + words[i][l-1]);
                            done = true;
                        }
                    }
                }
                if(!done) {
                    ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};