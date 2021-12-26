class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1)
            return {"()"};
        vector<vector<string>> temp(n);
        temp[0].push_back({"()"});
        for(int i = 1; i < n; i++) {
            int start = 0, end = i - 1;
            set<string> s;
            while(start <= end) {
                for(auto x : temp[start])
                {
                    for(auto y : temp[end])
                    {
                        s.insert(x + y);
                        s.insert(y + x);
                    }
                }
                start++;
                end--;
            }
            for(auto x : s)
            {
                temp[i].push_back(x);
            }
            for(auto x : temp[i-1])
            {
                string newstr = "(";
                newstr += x;
                newstr += ")";
                temp[i].push_back(newstr);
            }
        }
        return temp[n-1];
    }
};