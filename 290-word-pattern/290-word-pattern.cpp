class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,string> m;
        
        int curr = 0;
        for(int i = 0; i < pattern.length(); i++) {
            if(curr >= s.length()) {
                return false;
            }
            if(m[to_string(pattern[i])] == "") {
                string str = "";
                for(int j = curr; j < s.length(); j++) {
                    if(s[j] == ' ') {
                        curr = j + 1;
                        break;
                    }
                    str += s[j];
                    curr = j + 1;
                }
                if(m[str] != "") {
                    return false;
                }
                m[to_string(pattern[i])] = str;
                m[str] = to_string(pattern[i]);
            }
            else {
                string str = "";
                for(int j = curr; j < s.length(); j++) {
                    if(s[j] == ' ') {
                        curr = j + 1;
                        break;
                    }
                    str += s[j];
                    curr = j + 1;
                }
                if(m[to_string(pattern[i])] != str) {
                    return false;
                }
            }
        }
        
        if(curr < s.length()) {
            return false;
        }
        return true;
    }
};