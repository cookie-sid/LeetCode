class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> ans;
        
        int x = mat.size(), y = mat[0].size();
        int total = x + y - 2;
        int curr = 0;
        
        bool topToBottom = false;
        int startx = 0, starty = 0;
        while(curr <= total) {
            
            int sx = startx, sy = starty;
            if(topToBottom) {
                sy = min(y - 1, sy + sx);
                sx = curr - sy;
            }
            cout<<sx<<" "<<sy<<endl;
            if(!topToBottom) {
                while(sx >= 0 and sx <= x - 1 and sy <= y - 1 and sy >= 0) {
                    ans.push_back(mat[sx][sy]);
                    sx--;
                    sy++;
                }
            }
            else {
                while(sx >= 0 and sx <= x - 1 and sy <= y - 1 and sy >= 0) {
                    ans.push_back(mat[sx][sy]);
                    sx++;
                    sy--;
                }
            }
            startx++;
            if(startx == x) {
                startx--;
                starty++;
            }
            cout<<startx<<" "<<starty<<endl;
            topToBottom = !topToBottom;
            curr++;
        }
        
        return ans;
        
    }
};