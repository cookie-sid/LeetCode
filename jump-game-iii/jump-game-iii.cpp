class Solution {
public:
    
    bool canItThough(vector<int>& arr, int start, vector<bool>& temp) {
        if(arr[start] == 0) {
            return true;
        }
        
        if(temp[start] == true) {
            return false;
        }
        else {
            temp[start] = true;
        }
        
        if(start - arr[start] < 0 and arr[start] + start < arr.size())
            return canItThough(arr,arr[start] + start,temp);
        if(start - arr[start] >= 0 and arr[start] + start < arr.size())
            return canItThough(arr,arr[start]+start,temp) or canItThough(arr,start - arr[start],temp);
        if(start - arr[start] >= 0 and arr[start] + start >= arr.size())
            return canItThough(arr,start - arr[start],temp);
        
        return false;
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        vector<bool> temp(50002);
        return canItThough(arr,start,temp);
        
        
    }
};