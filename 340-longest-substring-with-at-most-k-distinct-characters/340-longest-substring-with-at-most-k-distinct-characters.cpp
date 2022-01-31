class Solution {
public:
    
    bool checkAtMostK(map<char,int> &freq, int p) {
        int count = 0;
        for(auto x : freq) {
            if(x.second != 0) {
                count++;
            }
        }
        if(count <= p) {
            return true;
        }
        return false;
    } 
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if(k == 0) {
            return 0;
        }
        
        map<char,int> freq;
        int ans = 1;
        int start = 0;
        freq[s[0]] += 1;
        for(int i = 1; i < s.length(); i++) {
            freq[s[i]] += 1;
            while(start < i  and !checkAtMostK(freq,k)) {
                freq[s[start]] -= 1;
                start++;
            }
            ans = max(ans,i - start + 1);
        }
        return ans;
        
        
    }
};