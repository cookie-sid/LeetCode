class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int curr_len = 0, useless = -1, lastvalid = -1, pos = 0;
        for(int i = 0; i < n; i++) {
            if(useless != -1) {
                arr[i] = 0;
                continue;
            }
            if(arr[i] != 0) {
                lastvalid = i;
                pos = curr_len;
            }
            if(arr[i] == 0) {
                curr_len++;
            }
            if(curr_len == n) {
                useless = i + 1;
            }
            curr_len++;
            if(curr_len == n) {
                useless = i + 1;
            }
        }
        if(lastvalid == -1) {
            return;
        }
        for(int i = pos; i >= 0; i--) {
            arr[i] = arr[lastvalid];
            lastvalid--;
            int numofzeros = 0;
            while(lastvalid >= 0 and arr[lastvalid] == 0) {
                numofzeros++;
                lastvalid--;
            }
            int travel = 2*numofzeros;
            i--;
            while(i >= 0 and travel > 0) {
                arr[i] = 0;
                i--;
                travel--;
            }
            i++;
        }
        
    }
};