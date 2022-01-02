class Solution {
public:
    string originalDigits(string s) {
        
        vector<string> t = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        vector<int> count(26);
        for(auto x : s) {
            count[x - 'a']++;
        }
        
        vector<char> unique_even = {'z','w','u','x','g'};
        string ans = "";
        for(int i = 0; i < unique_even.size(); i++) {
            int num = count[unique_even[i]-'a'];
            for(int j = 0; j < t[2*i].length(); j++) {
                count[t[2*i][j] - 'a'] -= num;
            }
            for(int j = 0; j < num; j++) {
                ans += to_string(2*i);
            }
        }
        
        vector<char> unique_odd = {'o','r','f','s'};
        for(int i = 0; i < unique_odd.size(); i++) {
            int num = count[unique_odd[i] - 'a'];
            for(int j = 0; j < t[2*i + 1].length(); j++) {
                count[t[2*i + 1][j] - 'a'] -= num;
            }
            for(int j = 0; j < num; j++) {
                ans += to_string(2*i + 1);
            }
        }
        
        int num = count['i' - 'a'];
        for(int i = 0; i < num; i++) {
            ans += '9';
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};