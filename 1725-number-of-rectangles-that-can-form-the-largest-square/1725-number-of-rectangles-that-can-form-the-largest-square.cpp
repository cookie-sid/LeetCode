class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int c=0,cou=0;
        for(auto i:rectangles)
        {int t= min(i[0],i[1]); // min among the l and w
        if(t>c)cou=1,c= t; // if found a greater square then made the counter 1
        else if( t==c)cou++; // if found the same square then increased the counter
        }
        return cou;
    }
};