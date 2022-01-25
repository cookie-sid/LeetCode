class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) {
            return false;
        }
        bool found = false;
        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] == arr[i-1] or arr[i] == arr[i+1] or (!found and arr[i] < arr[i-1]) or (found and arr[i] < arr[i+1])) {
                return false;
            }
            if(!found and arr[i] > arr[i-1] and arr[i] > arr[i+1]) {
                found = true;
                continue;
            }
        }
        return found;
    }
};