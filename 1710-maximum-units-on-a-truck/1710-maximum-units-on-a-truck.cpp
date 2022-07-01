class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] != b[1] ? a[1] > b[1] : a[0] > b[0];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0, k = 0;
        while(truckSize and k < boxTypes.size()) {
            ans += min(truckSize,boxTypes[k][0]) * boxTypes[k][1];
            truckSize -= min(truckSize,boxTypes[k][0]);
            k++;
            
        }
        return ans;
    }
};