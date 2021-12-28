class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            set<int> sx,sy;
            for(int j = 0; j < 9; j++) {
                int currx = board[i][j] - '0';
                int curry = board[j][i] - '0';
                if(sx.count(currx) == 1 and currx > 0 and currx < 10) {
                    return false;
                }
                if(sy.count(curry) == 1 and curry > 0 and curry < 10) {
                    return false;
                }
                if(board[i][j] != '.') {
                    sx.insert(currx);
                }
                if(board[j][i] != '.') {
                    sy.insert(curry);
                }
            }
        }
        
        for(int i = 0; i < 9; i+=3) {
            for(int j = 0; j < 9; j+=3) {
                set<int> s;
                for(int k = i; k < i + 3; k++) {
                    for(int l = j; l < j + 3; l++) {
                        if(board[k][l] == '.')
                            continue;
                        if(s.count(board[k][l] - '0') == 1) {
                            return false;
                        }
                        s.insert(board[k][l] - '0');
                    }
                }
            }
        }
        return true;
        
    }
};