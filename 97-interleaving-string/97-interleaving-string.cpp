class Solution {
public:
    
    map<vector<string>,int> m;
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1 == "") {
            if(s2 == s3) {
                m[{s1,s2,s3}] = 2;
                return true;
            }
            else {
                m[{s1,s2,s3}] = 1;
                return false;
            }
        }
        if(s2 == "") {
            if(s1 == s3) {
                m[{s1,s2,s3}] = 2;
                return true;
            }
            else {
                m[{s1,s2,s3}] = 1;
                return false;
            }
        }
        if(s1.length() + s2.length() != s3.length()) {
            m[{s1,s2,s3}] = 1;
            return false;
        }
        string s = "";
        int start = 0;
        bool ans = false;
        if(m[{s1,s2,s3}] != 0) {
            return m[{s1,s2,s3}] == 1 ? false:true;
        }
        if(s1[start] != s3[start] and s2[start] != s3[start]) {
            m[{s1,s2,s3}] = 1;
            return false;
        }
            
        if(!ans and s1[start] == s3[start] and s2[start] != s3[start]) {
            ans = ans or isInterleave(s1.substr(start+1),s2,s3.substr(start + 1));
        }
        
        if(!ans and s1[start] == s3[start] and s2[start] == s3[start]) {
            ans = ans or isInterleave(s1.substr(start+1),s2,s3.substr(start + 1))
                or isInterleave(s1,s2.substr(start+1),s3.substr(start + 1));
        }
        
        if(!ans and s2[start] == s3[start] and s1[start] != s3[start]) {
            ans = ans or isInterleave(s1,s2.substr(start + 1),s3.substr(start + 1));
        }
        m[{s1,s2,s3}] = ans == true ? 2 : 1;
        return ans;
    }

};