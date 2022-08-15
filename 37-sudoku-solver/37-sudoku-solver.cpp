class Solution {
public:
    
    bool check(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            unordered_set<char> r,c;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    return false;
                if(r.count(board[i][j]))
                    return false;
                if(c.count(board[j][i]))
                    return false;
                r.insert(board[i][j]);
                c.insert(board[j][i]);
            }
        }
        for(int i = 0; i < 9; i+=3) {
            for(int j = 0; j < 9; j+=3) {
                unordered_set<char> box;
                for(int k = i; k < i + 3; k++) {
                    for(int l = j; l < j + 3; l++) {
                        if(board[k][l] == '.')
                            return false;
                        if(box.count(board[k][l]))
                            return false;
                        box.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
    
    bool fill(vector<vector<char>> &board) {
        bool ans = false;
        bool done = true;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    done = false;
                    vector<bool> s(10,true);
                    int x = (i/3)*3, y = (j/3)*3;
                    for(int k = x; k < x + 3; k++) {
                        for(int l = y; l < y + 3; l++) {
                            if(board[k][l] != '.') {
                                s[board[k][l] - '0'] = false; 
                            }
                        }
                    }
                    for(int k = 0; k < 9; k++) {
                        if(board[k][j] != '.') {
                            s[board[k][j] - '0'] = false;
                        }
                        if(board[i][k] != '.') {
                            s[board[i][k] - '0'] = false;
                        }
                    }
                    bool none = true, goBack = true;
                    for(int k = 1; k < 10; k++) {
                        if(s[k]) {
                            none = false;
                            board[i][j] = '0' + k;
                            bool res = fill(board);
                            if(res) {
                                goBack = false;
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    if(none) {
                        return false;
                    }
                    if(goBack) {
                        return false;
                    }
                }
            }
        }
        if(done) {
            if(check(board)) {
                return true;
            }
        }
        return ans;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        fill(board);
    }
    
};