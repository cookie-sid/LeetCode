class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int ans = 0, mod = 1e9 + 7;
        sort(arr.begin(),arr.end());
        unordered_map<int,int> freq;
        for(auto x : arr) {
            freq[x]++;
        }
        for(int i = 0; i <arr.size() - 2; i++) {
            
            int req = target - arr[i];
            
            int low = i + 1, high = arr.size() - 1;
            
            while(low < high) {
                if(arr[low] + arr[high] > req) {
                    high--;
                }
                else if(arr[low] + arr[high] < req) {
                    low++;
                }
                else {
                    int curr_l = low, curr_h = high;
                    if(arr[low] == arr[high]) {
                        int temp = 0;
                        while(low <= high) {
                            low++;
                            temp++;
                        }
                        ans += ((temp) * (temp - 1))/2;
                        ans %= mod;
                        continue;
                    }
                    while(low < high and arr[low] == arr[low + 1]) {
                        low++;
                    }
                    low++;
                    while(low < high and arr[high] == arr[high - 1]) {
                        high--;
                    }
                    high--;
                    ans += (low - curr_l)*(curr_h - high);
                }
            }
            
        }
        return ans;
        
    }
};