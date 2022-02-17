class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.length() - 1; i++)
        {
            
            int index,maxi;
            for(int j = i + 1; j < s.length(); j++) {
                if(j == i + 1) {
                    index = j;
                    maxi = s[j] - '0';
                }
                else {
                    if(s[j] - '0' >= maxi) {
                        maxi = max(maxi,s[j] - '0');
                        index = j;
                    }
                }
            }
            if(maxi > s[i] - '0') {
                swap(s[i],s[index]);
                return stoi(s);
            }
        }
        return num;
    }
};