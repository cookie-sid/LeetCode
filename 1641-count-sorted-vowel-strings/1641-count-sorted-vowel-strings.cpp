class Solution {
public:
    int countVowelStrings(int n) {
        
        vector<int> arr(6,1);
        arr[5] = 5;
        for(int i = 2; i <= n; i++) {
            arr[0] = 1;
            arr[1] += arr[0];
            arr[2] += arr[1];
            arr[3] += arr[2];
            arr[4] += arr[3];
            arr[5] = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
        }
        return arr[5];
    }
};