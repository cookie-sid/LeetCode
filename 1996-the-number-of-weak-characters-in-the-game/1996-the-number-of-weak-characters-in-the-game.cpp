class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {

        sort(props.begin(),props.end(),[](vector<int> &a, vector<int> &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        
        vector<int> temp;
        for(int i = props.size() - 1; i >= 0; i--) {
            int ind = upper_bound(temp.begin(),temp.end(),props[i][1]) - temp.begin();
            if(ind >= temp.size()) {
                temp.push_back(props[i][1]);
            }
        }
        return props.size() - temp.size();
    }
};