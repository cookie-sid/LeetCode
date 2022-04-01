class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> ind(26);
        for(int i = 0; i < s.length(); i++) {
            ind[s[i] - 'A'].push_back(i);
        }
        int sum = 0;
        for(auto x: ind) {
            for(int j = 0; j < x.size(); j++) {
                int left = j == 0 ? x[j] + 1 : x[j] - x[j - 1];
                int right = j == (int)x.size() - 1 ? (int)s.length() - x[j] : x[j + 1] - x[j];
                sum += left * right;
            }
        }
        return sum;
    }
};