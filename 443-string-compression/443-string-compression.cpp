class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        for(int i = 0; i < chars.size(); i++) {
            char currChar = chars[i];
            int count = 1;
            while(i + 1 < chars.size() and chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            string temp = "";
            if(count != 1) {
                temp = to_string(count);
            }
            if(temp.length() != 0) {
                chars[start] = currChar;
                start++;
                for(int j = 0; j < temp.length(); j++) {
                    chars[start++] = temp[j];
                }
            }
            else {
                chars[start] = currChar;
                start++;
            }
        }
        while(chars.size() != start) {
            chars.pop_back();
        }
        return chars.size();
        
    }
};