class Solution {
public:
    
    bool check(vector<vector<char>>& board, int x, int y, 
               vector<vector<bool>>& taken, string current, string word) {
        
        if(word.substr(0,current.length()) != current) {
            return false;
        }
        if(current == word) {
            return true;
        }
        if(x >= board.size() or y >= board[0].size() or x < 0 or y < 0) {
            return false;
        }
        if(current.length() > word.length()) {
            return false;
        }
        if(taken[x][y] == true) {
            return false;
        }
        if(word.substr(0,current.length() + 1)  != current + board[x][y]) {
            return false;
        }
        
        taken[x][y] = true;
        
        bool ans = false;
        
        ans = ans or check(board,x+1,y,taken,current + board[x][y],word) or 
            check(board,x,y+1,taken,current + board[x][y],word) or 
            check(board,x-1,y,taken,current + board[x][y],word) or 
            check(board,x,y-1,taken,current + board[x][y],word);
        
        taken[x][y] = false;
        
        return ans;
               
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        bool found = false;
        
        if(word.length() > (int)board.size() * (int)board[0].size())
            return found;
        
        map<char,int> m;
        for(auto x : board) {
            for(auto y : x) {
                m[y]++;
            }
        }
        for(auto x : word) {
            m[x]--;
            if(m[x] < 0) {
                return found;
            }
        }
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> taken(board.size(),vector<bool>(board[0].size()));
                found = found or check(board,i,j,taken,"",word);
            }
        }
        
        return found;
    }
};