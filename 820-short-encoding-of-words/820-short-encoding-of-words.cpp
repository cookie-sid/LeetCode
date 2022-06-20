class Solution {
public:
    
    static bool cmp(string &a, string &b) {
        return a.length() > b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        string ans = "";
        for(int i = 0; i < words.size(); i++) {
            if(i == 0) {
                ans += words[i];
                ans += "#";
            }
            else {
                int pos = 0;
                bool isIt = false;
                while(true) {
                    if(ans.find(words[i],pos) == string::npos) {
                        break;
                    }
                    else {
                        int ind = ans.find(words[i],pos);
                        if(ans[ind + words[i].length()] != '#') {
                            pos += words[i].length();
                        }
                        else {
                            isIt = true;
                            break;
                        }
                    }
                }
                if(!isIt) {
                    ans += words[i] + "#";
                }
            }

        }
        return ans.length();
    }
};