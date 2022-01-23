class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowest = to_string(low).length();
        int highest = to_string(high).length();
        vector<int> ans;
        for(int i = lowest; i <= highest; i++) {
            string s = "";
            for(int j = 0; j < i; j++) {
                s += '0';
            }
            for(int j = 1; j <= 10 - i; j++) {
                string temp = s; 
                for(int k = 0; k < i; k++) {
                    temp[k] += j + k;
                }
                int result = stoi(temp);
                if(result >= low and result <= high)
                    ans.push_back(result);
            }
        }
        return ans;
    }
};