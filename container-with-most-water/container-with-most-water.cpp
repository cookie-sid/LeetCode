class Solution {
public:
    
    static bool comp(pair<int,int> a, pair<int,int> b) {
        if(a.first != b.first)
            return a.first > b.first;
        
        return a.second < b.second; 
    }
    
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> temp;
        for(int i = 0; i < height.size(); i++)
            temp.push_back(make_pair(height[i],i));
        
        sort(temp.begin(),temp.end(),comp);
        
        int rightmost = -1, leftmost = 1e9, ans = -1;
        for(int i = 0; i < temp.size(); i++) {
            if(i == 0) {
                rightmost = max(rightmost,temp[i].second);
                leftmost = min(leftmost,temp[i].second);
            }
            else {
                if(rightmost == leftmost) {
                    ans = max(ans,temp[i].first * abs(temp[i].second - rightmost));
                    rightmost = max(rightmost,temp[i].second);
                    leftmost = min(leftmost,temp[i].second);
                }
                else {
                    if(temp[i].second < leftmost) {
                        ans = max(ans,temp[i].first * abs(temp[i].second - rightmost));
                        rightmost = max(rightmost,temp[i].second);
                        leftmost = min(leftmost,temp[i].second);
                    }
                    else if(temp[i].second > rightmost) {
                        ans = max(ans,temp[i].first * abs(temp[i].second - leftmost));
                        rightmost = max(rightmost,temp[i].second);
                        leftmost = min(leftmost,temp[i].second);
                    }
                    else {
                        ans = max(ans,temp[i].first * abs(leftmost - rightmost));
                        rightmost = max(rightmost,temp[i].second);
                        leftmost = min(leftmost,temp[i].second);
                    }
                }
            }
        }
        return ans;
        return 0;
    }
};