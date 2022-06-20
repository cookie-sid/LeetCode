class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> diff = {-1,0,1};
        int newlyAlive = 2, newlyDead = 3;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int countActualAlive = 0, countActualDead = 0, validN = 0;
                for(int p = -1; p < 2; p++) {
                    for(int q = -1; q < 2; q++) {
                        if(p == 0 and q == 0) {
                            continue;
                        }
                        if(i + p < 0 or i + p >= n or  j + q < 0 or j + q >= m) {
                            continue;
                        }
                        validN++;
                        if(board[i][j] == 0 and (board[i + p][j + q] == 1 or board[i + p][j + q] == newlyDead)) {
                            countActualAlive++;
                        }
                        if(board[i][j] == 1 and (board[i + p][j + q] == 0 or board[i + p][j + q] == newlyAlive)) {
                            countActualDead++;
                        }
                    }
                }
                if(board[i][j] == 0) {
                    if(countActualAlive == 3) {
                        board[i][j] = newlyAlive;
                    }
                }
                if(board[i][j] == 1) {
                    if(validN - countActualDead < 2 or validN - countActualDead > 3) {
                        board[i][j] = newlyDead;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == newlyAlive) {
                    board[i][j] = 1;
                } 
                if(board[i][j] == newlyDead) {
                    board[i][j] = 0;
                }
            }
        }
    }
};