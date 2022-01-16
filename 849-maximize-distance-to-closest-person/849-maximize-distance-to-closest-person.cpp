class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n = seats.size(), ans = -1;
        int first = -1, second = -1;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                if(first == -1) {
                    second = i;
                    ans = max(ans,second);
                    first = i;
                }
                else {
                    second = i;
                    ans = max(ans,(second - first)/2);
                    first = i;
                }
            }
            if(i == n-1 and seats[i] != 1) {
                second = i;
                ans = max(ans,second - first);
                first = i;
            }
        }
        return ans;
        
    }
};