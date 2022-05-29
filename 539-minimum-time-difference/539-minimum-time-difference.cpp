class Solution {
public:
    
    int diff(string &a, string &b) {
        int temp1 = stoi(a.substr(0,2) + a.substr(3));
        int temp2 = stoi(b.substr(0,2) + b.substr(3));
        if(temp1 == temp2) {
            return 0;
        }
        int mins = 0;
        while(temp1 < temp2) {
            mins++;
            temp1++;
            if(temp1 % 100 == 60)
                temp1 += 40;
            if(temp1 == 2400)
                temp1 = 0;
        }
        while(temp2 < temp1) {
            mins++;
            temp2++;
            
            if(temp2 % 100 == 60)
                temp2 += 40;
            if(temp2 == 2400)
                temp2 = 0;
        }
        
        return min(mins,1440-mins);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int mini = 2401;
        for(int i = 1; i < timePoints.size(); i++) {
            mini = min(mini,diff(timePoints[i],timePoints[i-1]));
        }
        mini = min(mini,diff(timePoints.back(),timePoints[0]));
        return mini;
    }
};