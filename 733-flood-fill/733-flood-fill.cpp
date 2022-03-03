class Solution {
public:
    
    void fill(vector<vector<int>>& image, int x, int y, int col, int curr) {
        if(x < 0 or x >= image.size() or y < 0 or y >= image[0].size())
            return;
        if(image[x][y] != curr)
            return;
        
        image[x][y] = col;
        fill(image,x + 1,y,col,curr);
        fill(image,x - 1,y,col,curr);
        fill(image,x,y + 1,col,curr);
        fill(image,x,y - 1,col,curr);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        fill(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};