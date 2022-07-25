class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        set<char> s;
        map<int,int> r;
        for(auto x : ranks) {
            r[x]++;
        }
        for(auto x : suits) {
            s.insert(x);
        }
        if(s.size() == 1) {
            return "Flush";
        }
        for(auto x : r) {
            if(x.second >= 3) {
                return "Three of a Kind";
            }
            else if(x.second == 2) {
                return "Pair";
            }
        }
        return "High Card";
    }
};